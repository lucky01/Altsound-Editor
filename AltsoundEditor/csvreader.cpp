/*
 * csvreader.c
 *
 *  Created on: 21.02.2019
 *
 *      Author: Stefan Rinke
 *
 *      (C) 2019 by Stefan Rinke / Rinke Solutions
 *  This work is licensed under a Creative
 *	Commons Attribution-NonCommercial-
 *	ShareAlike 4.0 International License.
 *
 *	http://creativecommons.org/licenses/by-nc-sa/4.0/
 *
 */

#include "csvreader.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>


/**
 * init struct and open file
 */
CsvReader* csv_open(const char* filename, int delimiter) {
	CsvReader* c = (CsvReader * ) malloc(sizeof(CsvReader));
	c->f = fopen(filename, "r");
	if( c->f == NULL ) {
		free(c);
		return NULL;
	}
	c->delimiter = delimiter;
	c->n_header_fields = 0;
	c->n_fields = 0;
	return c;
}

int get_line(char* buffer, size_t buflen, FILE* fp)
{
	char* end = buffer + buflen - 1; /* Allow space for null terminator */
	char* dst = buffer;
	int c;
	while ((c = getc(fp)) != EOF && c != '\n' && dst < end)
		*dst++ = c;
	*dst = '\0';
	return((c == EOF && dst == buffer) ? EOF : dst - buffer);
}

/**
 * trim field buffer from end to start
 */
static void trim( char* start, char* end) {
	while( end > start) {
		end--;
		if( *end == ' ' || *end == '\t' || *end == '\r' || *end == '\n' ) {
			*end = 0;
		} else {
			break;
		}
	}
}

/**
 * parse line (either header or record).
 * handles
 */
int parse_line( CsvReader* c, char* line, int header ) {
	char* p = line;
	char* d, *f;
	int capacity = 0;
	int field_number = 0;
	int enclosed_in_quotes = 0;
	int escaped = 0;
	int allocField = 1;
	int justAfterDelim = 1; 		// if set skip whitespace
	char** fields = header ? c->header_fields : c->fields;
	while(*p) {
		// realloc field array
		if( field_number == capacity ) {
			int size = (capacity+10)*sizeof(char*);
			fields = capacity == 0 ? (char **) malloc(size) : (char **) realloc(fields, size);
			capacity += 10;
			for(int i=field_number; i<capacity; i++) fields[i] = NULL;
		}
		// allocate field
		if( allocField ) {
			allocField = 0;
			fields[field_number] = strdup(p);
			f = d = fields[field_number];
		}
		if( enclosed_in_quotes ) {
			if( *p == '"' && !escaped ) {
				enclosed_in_quotes = 0;
				f = d; 	// move start ptr for trimming to last char before quote
			} else if( *p == '\\' && !escaped) {
				escaped = 1;
			} else {
				if( justAfterDelim && (*p == ' ' || *p == '\t') ) {
					justAfterDelim = 0;
				} else {
					*d++ = *p;	// copy char to target
					escaped = 0;
					justAfterDelim = 0;
				}
			}
		} else { // not in quotes
			if( *p == '"' && !escaped ) {
				enclosed_in_quotes = 1;
			} else if( *p == c->delimiter && !escaped ) {
				// terminate current field
				*d = 0;
				trim(f,d);
				// next field
				field_number++;
				allocField = 1;
				justAfterDelim = 1;
			} else if( *p == '\\' && !escaped) {
				escaped = 1;
			} else {
				if( justAfterDelim && (*p == ' ' || *p == '\t') ) {
					justAfterDelim = 0;
				} else {
					*d++ = *p;	// copy char to target
					escaped = 0;
					justAfterDelim = 0;
				}
			}
		}

		p++;
	}
	*d = 0;
	trim(f,d);

	if( enclosed_in_quotes ) return CSV_ERROR_LINE_FORMAT; //	 quote still open
	if( escaped ) return CSV_ERROR_LINE_FORMAT; // esc still open

	if( header ) {
		c->header_fields = fields;
		c->n_header_fields = field_number+1;
	} else {
		c->fields = fields;
		c->n_fields = field_number+1;
	}
	return CSV_SUCCESS;
}

int csv_read_header(CsvReader* c) {
	char* buf = NULL;	
	buf = (char*)malloc(4096);
	size_t size = 4096;
	int len = get_line(buf, size, c->f);
	if( len < 0  ) {
		if( buf ) free(buf);
		return CSV_ERROR_HEADER_NOT_FOUND;
	}
	// parse line and look for headers
	parse_line(c, buf, 1 );
	if( buf ) free( buf );
	return 0;
}

int csv_get_colnumber_for_field(CsvReader* c, const char* fieldname) {
	for(int i = 0; i < c->n_header_fields; i++) {
		if( strcmp(c->header_fields[i], fieldname) == 0) return i;
	}
	return CSV_ERROR_NO_SUCH_FIELD;
}

static void free_record(CsvReader* c) {
	for(int i = 0; i < c->n_fields; i++) {
		free(c->fields[i]);
	}
	if( c->n_fields ) free( c->fields );
}

int csv_get_int_field(CsvReader* c, int field_index, int* pValue) {
	if( field_index >= 0 && field_index < c->n_fields ) {
		if( sscanf(c->fields[field_index], "%d", pValue) == 1 ) return 0;
		return CSV_ERROR_LINE_FORMAT;
	}
	return CSV_ERROR_FIELD_INDEX_OUT_OF_RANGE;
}

int csv_get_hex_field(CsvReader* const c, const int field_index, int* pValue) {
	if (field_index >= 0 && field_index < c->n_fields) {
		if (sscanf(c->fields[field_index], "0x%x", pValue) == 1) return 0;
		return CSV_ERROR_LINE_FORMAT;
	}

	return CSV_ERROR_FIELD_INDEX_OUT_OF_RANGE;
}

int csv_get_float_field(CsvReader* c, int field_index, float* pValue) {
	if( field_index >= 0 && field_index < c->n_fields ) {
		if( sscanf(c->fields[field_index], "%f", pValue) == 1 ) return 0;
		return CSV_ERROR_LINE_FORMAT;
	}
	return CSV_ERROR_FIELD_INDEX_OUT_OF_RANGE;
}

int csv_get_str_field(CsvReader* c, int field_index, char** pValue) {
	if( field_index >= 0 && field_index < c->n_fields ) {
		*pValue = c->fields[field_index];
		return 0;
	}
	return CSV_ERROR_FIELD_INDEX_OUT_OF_RANGE;
}

void csv_close(CsvReader* c) {
	if( c ) {
		free_record(c);
		for(int i = 0; i < c->n_header_fields; i++) {
			if( c->header_fields[i] ) free( c->header_fields[i] );
		}
		if( c->n_header_fields > 0 ) free( c->header_fields );
		if( c->f ) fclose(c->f);
		free(c);
	}
}

int csv_read_record(CsvReader* c) {
	char* buf = NULL;
	buf = (char*)malloc(4096);
	size_t size = 4096;
	int len = get_line(buf, size, c->f);

	if( len < 0  ) {
		if( buf ) free(buf);
		return CSV_ERROR_NO_MORE_RECORDS;
	}
	free_record(c);
	// parse line and look for headers
	parse_line(c, buf, 0 );
	if( buf ) free( buf );
	return 0;
}

#if 0
int main(int argc, char** argv ) {
	setLogDevice(stdout);
	CsvReader* c = csv_open("./test.csv", ',');
	if( c ) {
		csv_read_header(c);
		printf("n_headers: %d\n", c->n_header_fields);
		for( int i = 0; i< c->n_header_fields; i++) {
			printf("header[%d]: '%s'\n", i, c->header_fields[i]);
		}
		int idx = csv_get_colnumber_for_field(c, "test1");
		printf("index for test1: %d \n", idx);
		int row = 0;
		while( csv_read_record(c) == 0) {
			printf("row(%d): no of fields: %d\n", row, c->n_fields);
			for( int i = 0; i < c->n_fields; i++) {
				printf("field[%d] = '%s'\n", i, c->fields[i]);
				int val = 0;
				if( csv_get_int_field(c,i,&val) == 0)
					printf("field[%d] as number = %d\n", i, val);
				else
					printf("field[%d] is no number\n", i);
			}
			row++;
		}
		csv_close(c);
	}
}
#endif
