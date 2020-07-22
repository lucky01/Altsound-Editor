/*
 * csvreader.h
 *
 */

#ifndef CSVREADER_H_
#define CSVREADER_H_

#include <stdio.h>

typedef struct _csvreader {
	FILE* f;
	int delimiter;
	int n_header_fields;
	char** header_fields;			// header split in fields
	int n_fields;
	char** fields;				// current row split in fields
} CsvReader;

CsvReader* csv_open(const char* filename, int delimiter);

void csv_close(CsvReader* csv);

int csv_read_header(CsvReader* c);

int csv_get_colnumber_for_field(CsvReader* c, const char* fieldname);

int csv_read_record(CsvReader* c);

int csv_get_int_field(CsvReader* c, int field_index, int* pValue);

int csv_get_hex_field(CsvReader* const c, const int field_index, int* pValue);

int csv_get_str_field(CsvReader* c, int field_index, char** pValue);

int csv_get_float_field(CsvReader* c, int field_index, float* pValue);

int parse_line( CsvReader* c, char* line, int header );

#define CSV_SUCCESS 0
#define CSV_ERROR_NO_SUCH_FIELD -1
#define CSV_ERROR_HEADER_NOT_FOUND -2
#define CSV_ERROR_NO_MORE_RECORDS -3
#define CSV_ERROR_FIELD_INDEX_OUT_OF_RANGE -4
#define CSV_ERROR_FILE_NOT_FOUND -5
#define CSV_ERROR_LINE_FORMAT -6

#endif /* CSVREADER_H_ */

