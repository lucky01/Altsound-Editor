#pragma once

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tchar.h>
#include <conio.h>
#include "csvreader.h"
#include <iostream>
#include "bass.h"


typedef struct _pin_samples { // holds data for all sound files found
	int* ID;
	char** filename;
	char** description;
	signed char* channel;
	signed char* gain;
	signed char* ducking;
	unsigned char* loop;
	unsigned char* stop;
	int num_files;
} Pin_samples;

FILE *csvfile;
char* srcfileName;
CsvReader* c;
static Pin_samples psd;
bool backupOriginal = false;
int device = -1; // Default Sounddevice
int freq = 44100; // Sample rate (Hz)
HSTREAM streamHandle; // Handle for open stream




namespace AltSoundEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}




	protected:










	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::ComboBox^ ID;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ CHANNEL;
	private: System::Windows::Forms::ComboBox^ DUCK;
	private: System::Windows::Forms::ComboBox^ GAIN;
	private: System::Windows::Forms::ComboBox^ LOOP;
	private: System::Windows::Forms::ComboBox^ STOP;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ NAME;
	private: System::Windows::Forms::TextBox^ FNAME;
	private: System::Windows::Forms::Button^ btnPLAY;
	private: System::Windows::Forms::Button^ btnSTOP;
	private: System::Windows::Forms::Button^ btnMUSIC;
	private: System::Windows::Forms::Button^ btnVOICE;
	private: System::Windows::Forms::Button^ btnSFX;
	private: System::Windows::Forms::Button^ btnSINGLE;
	private: System::Windows::Forms::Button^ btnJINGLE;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnDel;











	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->ID = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->CHANNEL = (gcnew System::Windows::Forms::ComboBox());
			this->DUCK = (gcnew System::Windows::Forms::ComboBox());
			this->GAIN = (gcnew System::Windows::Forms::ComboBox());
			this->LOOP = (gcnew System::Windows::Forms::ComboBox());
			this->STOP = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->NAME = (gcnew System::Windows::Forms::TextBox());
			this->FNAME = (gcnew System::Windows::Forms::TextBox());
			this->btnPLAY = (gcnew System::Windows::Forms::Button());
			this->btnSTOP = (gcnew System::Windows::Forms::Button());
			this->btnMUSIC = (gcnew System::Windows::Forms::Button());
			this->btnVOICE = (gcnew System::Windows::Forms::Button());
			this->btnSFX = (gcnew System::Windows::Forms::Button());
			this->btnSINGLE = (gcnew System::Windows::Forms::Button());
			this->btnJINGLE = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ID
			// 
			this->ID->FormattingEnabled = true;
			this->ID->Location = System::Drawing::Point(12, 49);
			this->ID->Name = L"ID";
			this->ID->Size = System::Drawing::Size(53, 21);
			this->ID->TabIndex = 1;
			this->ID->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ID_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(71, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"CHANNEL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(135, 33);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"DUCK";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(196, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"GAIN";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(314, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"STOP";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(376, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"NAME";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(523, 33);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"FNAME";
			// 
			// CHANNEL
			// 
			this->CHANNEL->FormattingEnabled = true;
			this->CHANNEL->Location = System::Drawing::Point(76, 49);
			this->CHANNEL->Name = L"CHANNEL";
			this->CHANNEL->Size = System::Drawing::Size(53, 21);
			this->CHANNEL->TabIndex = 9;
			this->CHANNEL->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::CHANNEL_SelectedIndexChanged);
			// 
			// DUCK
			// 
			this->DUCK->FormattingEnabled = true;
			this->DUCK->Location = System::Drawing::Point(138, 49);
			this->DUCK->Name = L"DUCK";
			this->DUCK->Size = System::Drawing::Size(53, 21);
			this->DUCK->TabIndex = 10;
			this->DUCK->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::DUCK_SelectedIndexChanged);
			// 
			// GAIN
			// 
			this->GAIN->FormattingEnabled = true;
			this->GAIN->Location = System::Drawing::Point(199, 49);
			this->GAIN->Name = L"GAIN";
			this->GAIN->Size = System::Drawing::Size(53, 21);
			this->GAIN->TabIndex = 11;
			this->GAIN->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::GAIN_SelectedIndexChanged);
			// 
			// LOOP
			// 
			this->LOOP->FormattingEnabled = true;
			this->LOOP->Location = System::Drawing::Point(258, 49);
			this->LOOP->Name = L"LOOP";
			this->LOOP->Size = System::Drawing::Size(53, 21);
			this->LOOP->TabIndex = 12;
			this->LOOP->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::LOOP_SelectedIndexChanged);
			// 
			// STOP
			// 
			this->STOP->FormattingEnabled = true;
			this->STOP->Location = System::Drawing::Point(317, 49);
			this->STOP->Name = L"STOP";
			this->STOP->Size = System::Drawing::Size(53, 21);
			this->STOP->TabIndex = 13;
			this->STOP->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::STOP_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(255, 33);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(36, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"LOOP";
			// 
			// NAME
			// 
			this->NAME->Location = System::Drawing::Point(379, 49);
			this->NAME->Name = L"NAME";
			this->NAME->Size = System::Drawing::Size(141, 20);
			this->NAME->TabIndex = 15;
			this->NAME->TextChanged += gcnew System::EventHandler(this, &MyForm::NAME_TextChanged);
			// 
			// FNAME
			// 
			this->FNAME->Location = System::Drawing::Point(526, 50);
			this->FNAME->Name = L"FNAME";
			this->FNAME->ReadOnly = true;
			this->FNAME->Size = System::Drawing::Size(139, 20);
			this->FNAME->TabIndex = 16;
			this->FNAME->Click += gcnew System::EventHandler(this, &MyForm::FNAME_Click);
			// 
			// btnPLAY
			// 
			this->btnPLAY->Location = System::Drawing::Point(12, 92);
			this->btnPLAY->Name = L"btnPLAY";
			this->btnPLAY->Size = System::Drawing::Size(60, 23);
			this->btnPLAY->TabIndex = 17;
			this->btnPLAY->Text = L"PLAY";
			this->btnPLAY->UseVisualStyleBackColor = true;
			this->btnPLAY->Click += gcnew System::EventHandler(this, &MyForm::btnPLAY_Click);
			// 
			// btnSTOP
			// 
			this->btnSTOP->Location = System::Drawing::Point(78, 92);
			this->btnSTOP->Name = L"btnSTOP";
			this->btnSTOP->Size = System::Drawing::Size(60, 23);
			this->btnSTOP->TabIndex = 18;
			this->btnSTOP->Text = L"STOP";
			this->btnSTOP->UseVisualStyleBackColor = true;
			this->btnSTOP->Click += gcnew System::EventHandler(this, &MyForm::btnSTOP_Click);
			// 
			// btnMUSIC
			// 
			this->btnMUSIC->Location = System::Drawing::Point(169, 92);
			this->btnMUSIC->Name = L"btnMUSIC";
			this->btnMUSIC->Size = System::Drawing::Size(60, 23);
			this->btnMUSIC->TabIndex = 19;
			this->btnMUSIC->Text = L"MUSIC";
			this->btnMUSIC->UseVisualStyleBackColor = true;
			this->btnMUSIC->Click += gcnew System::EventHandler(this, &MyForm::btnMUSIC_Click);
			// 
			// btnVOICE
			// 
			this->btnVOICE->Location = System::Drawing::Point(235, 92);
			this->btnVOICE->Name = L"btnVOICE";
			this->btnVOICE->Size = System::Drawing::Size(60, 23);
			this->btnVOICE->TabIndex = 20;
			this->btnVOICE->Text = L"VOICE";
			this->btnVOICE->UseVisualStyleBackColor = true;
			this->btnVOICE->Click += gcnew System::EventHandler(this, &MyForm::btnVOICE_Click);
			// 
			// btnSFX
			// 
			this->btnSFX->Location = System::Drawing::Point(301, 92);
			this->btnSFX->Name = L"btnSFX";
			this->btnSFX->Size = System::Drawing::Size(60, 23);
			this->btnSFX->TabIndex = 21;
			this->btnSFX->Text = L"SFX";
			this->btnSFX->UseVisualStyleBackColor = true;
			this->btnSFX->Click += gcnew System::EventHandler(this, &MyForm::btnSFX_Click);
			// 
			// btnSINGLE
			// 
			this->btnSINGLE->Location = System::Drawing::Point(367, 92);
			this->btnSINGLE->Name = L"btnSINGLE";
			this->btnSINGLE->Size = System::Drawing::Size(60, 23);
			this->btnSINGLE->TabIndex = 22;
			this->btnSINGLE->Text = L"SINGLE";
			this->btnSINGLE->UseVisualStyleBackColor = true;
			this->btnSINGLE->Click += gcnew System::EventHandler(this, &MyForm::btnSINGLE_Click);
			// 
			// btnJINGLE
			// 
			this->btnJINGLE->Location = System::Drawing::Point(433, 92);
			this->btnJINGLE->Name = L"btnJINGLE";
			this->btnJINGLE->Size = System::Drawing::Size(60, 23);
			this->btnJINGLE->TabIndex = 23;
			this->btnJINGLE->Text = L"JINGLE";
			this->btnJINGLE->UseVisualStyleBackColor = true;
			this->btnJINGLE->Click += gcnew System::EventHandler(this, &MyForm::btnJINGLE_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(677, 24);
			this->menuStrip1->TabIndex = 24;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(539, 92);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(60, 23);
			this->btnAdd->TabIndex = 25;
			this->btnAdd->Text = L"ADD";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnDel
			// 
			this->btnDel->Location = System::Drawing::Point(605, 92);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(60, 23);
			this->btnDel->TabIndex = 26;
			this->btnDel->Text = L"DEL";
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &MyForm::btnDel_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 136);
			this->Controls->Add(this->btnDel);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->btnJINGLE);
			this->Controls->Add(this->btnSINGLE);
			this->Controls->Add(this->btnSFX);
			this->Controls->Add(this->btnVOICE);
			this->Controls->Add(this->btnMUSIC);
			this->Controls->Add(this->btnSTOP);
			this->Controls->Add(this->btnPLAY);
			this->Controls->Add(this->FNAME);
			this->Controls->Add(this->NAME);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->STOP);
			this->Controls->Add(this->LOOP);
			this->Controls->Add(this->GAIN);
			this->Controls->Add(this->DUCK);
			this->Controls->Add(this->CHANNEL);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ID);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"AltsoundEditor";
			this->Closed += gcnew System::EventHandler(this, &MyForm::MyForm_Closed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void MyForm_Closed (System::Object^  sender, System::EventArgs^  e) {
	BASS_Free();
	if (srcfileName)
		Marshal::FreeHGlobal((IntPtr)srcfileName);
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	BASS_Init(device, freq, 0, 0, NULL);
	for (int i = 0; i <= 1; i++) {
		CHANNEL->Items->Add(i.ToString());
		STOP->Items->Add(i.ToString());
	}
	CHANNEL->Items->Add("auto");
	for (int i = 0; i <= 100; i++) {
		DUCK->Items->Add(i.ToString());
		GAIN->Items->Add(i.ToString());
		LOOP->Items->Add(i.ToString());
	}
	ID->Sorted = false;
	CHANNEL->SelectedIndex = 0;
	DUCK->SelectedIndex = 0;
	GAIN->SelectedIndex = 0;
	LOOP->SelectedIndex = 0;
	STOP->SelectedIndex = 0;
}

private: System::Void loadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	backupOriginal = false;

	ID->Items->Clear();

	if (psd.num_files > 0)
	{
		for (int i = 0; i < psd.num_files; ++i)
		{
			free(psd.filename[i]);
			psd.filename[i] = 0;
			free(psd.description[i]);
			psd.description[i] = 0;
		}
		free(psd.ID);
		psd.ID = 0;
		free(psd.filename);
		psd.filename = 0;
		free(psd.description);
		psd.description = 0;
		free(psd.gain);
		psd.gain = 0;
		free(psd.ducking);
		psd.ducking = 0;
		free(psd.channel);
		psd.channel = 0;
		free(psd.loop);
		psd.loop = 0;
		free(psd.stop);
		psd.stop = 0;
		psd.num_files = 0;
	}

	openFileDialog1->Filter = "altsound.csv|*.csv;";

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		srcfileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
		fopen_s(&csvfile, srcfileName, "r");

		c = csv_open(srcfileName, ',');

		if (c) {
			int colID, colCHANNEL, colDUCK, colGAIN, colLOOP, colSTOP, colFNAME, colNAME;
			long pos;
			csv_read_header(c);
			colID = csv_get_colnumber_for_field(c, "ID");
			colCHANNEL = csv_get_colnumber_for_field(c, "CHANNEL");
			colDUCK = csv_get_colnumber_for_field(c, "DUCK");
			colGAIN = csv_get_colnumber_for_field(c, "GAIN");
			colLOOP = csv_get_colnumber_for_field(c, "LOOP");
			colSTOP = csv_get_colnumber_for_field(c, "STOP");
			colFNAME = csv_get_colnumber_for_field(c, "FNAME");
			colNAME = csv_get_colnumber_for_field(c, "NAME");

			pos = ftell(c->f);

			while (csv_read_record(c) == 0) {
				int val;
				csv_get_hex_field(c, colID, &val);
				csv_get_int_field(c, colCHANNEL, &val);
				csv_get_int_field(c, colDUCK, &val);
				csv_get_int_field(c, colGAIN, &val);
				csv_get_int_field(c, colLOOP, &val);
				csv_get_int_field(c, colSTOP, &val);
				psd.num_files++;
			}

			if (psd.num_files > 0)
			{
				psd.ID = (int*)malloc(psd.num_files * sizeof(int));
				psd.channel = (signed char*)malloc(psd.num_files * sizeof(signed char));
				psd.gain = (signed char*)malloc(psd.num_files * sizeof(float));
				psd.ducking = (signed char*)malloc(psd.num_files * sizeof(signed char));
				psd.loop = (unsigned char*)malloc(psd.num_files * sizeof(unsigned char));
				psd.stop = (unsigned char*)malloc(psd.num_files * sizeof(unsigned char));
				psd.filename = (char**)malloc(psd.num_files * sizeof(char*));
				psd.description = (char**)malloc(psd.num_files * sizeof(char*));
			}
			else {
				psd.filename = NULL;
				return;
			}
			

			fseek(c->f, pos, SEEK_SET);

			for (int i = 0; i < psd.num_files; ++i) {

				int val = 0;
				csv_read_record(c);
				csv_get_hex_field(c, colID, &val);
				psd.ID[i] = val;
				ID->Items->Add(val.ToString("X4"));
				val = 0;
				psd.channel[i] = csv_get_int_field(c, colCHANNEL, &val) ? 2 : val;
				val = 0;
				csv_get_int_field(c, colDUCK, &val);
				psd.ducking[i] = min(val, (int)100);
				val = 0;
				csv_get_int_field(c, colGAIN, &val);
				psd.gain[i] = min(val, (int)100);
				val = 0;
				csv_get_int_field(c, colLOOP, &val);
				psd.loop[i] = min(val, (int)100);
				val = 0;
				csv_get_int_field(c, colSTOP, &val);
				psd.stop[i] = val;
				char* tmpStr;
				csv_get_str_field(c, colNAME, &tmpStr);
				psd.description[i] = (char*)malloc(1024);
				strcpy(psd.description[i], tmpStr);
				csv_get_str_field(c, colFNAME, &tmpStr);
				psd.filename[i] = (char*)malloc(1024);
				strcpy(psd.filename[i], tmpStr);
			}

			csv_close(c);

			if (csvfile)
				fclose(csvfile);

			ID->SelectedIndex = 0;
		}
	}
}
	private: System::Void ID_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		btnMUSIC->ForeColor = System::Drawing::Color::Black;
		btnVOICE->ForeColor = System::Drawing::Color::Black;
		btnSFX->ForeColor = System::Drawing::Color::Black;
		btnSINGLE->ForeColor = System::Drawing::Color::Black;
		btnJINGLE->ForeColor = System::Drawing::Color::Black;


		int index = ID->SelectedIndex;
		CHANNEL->SelectedIndex = psd.channel[index];
		DUCK->SelectedIndex = psd.ducking[index];
		GAIN->SelectedIndex = psd.gain[index];
		LOOP->SelectedIndex = psd.loop[index];
		STOP->SelectedIndex = psd.stop[index];
		String^ strNew = gcnew String(psd.description[index]);
		NAME->Text = strNew;
		strNew = gcnew String(psd.filename[index]);
		FNAME->Text = strNew;

		if (CHANNEL->SelectedIndex == 0)
			btnMUSIC->ForeColor = System::Drawing::Color::Red;

		if (CHANNEL->SelectedIndex == 2 && DUCK->SelectedIndex > 70)
			btnSFX->ForeColor = System::Drawing::Color::Red;

		if (CHANNEL->SelectedIndex == 2 && DUCK->SelectedIndex <= 70)
			btnVOICE->ForeColor = System::Drawing::Color::Red;

		if (CHANNEL->SelectedIndex == 1 && STOP->SelectedIndex == 0)
			btnJINGLE->ForeColor = System::Drawing::Color::Red;

		if (CHANNEL->SelectedIndex == 1 && STOP->SelectedIndex == 1)
			btnSINGLE->ForeColor = System::Drawing::Color::Red;


		BASS_ChannelStop(streamHandle);
	}
	
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!backupOriginal) {
		char bakfileName[4096];
		strcpy(bakfileName, srcfileName);
		char* ptr = strrchr(bakfileName, '.');
		strcpy(ptr + 1, "bak");
		wchar_t* bakFile = new wchar_t[4096];
		wchar_t* srcFile = new wchar_t[4096];
		MultiByteToWideChar(CP_ACP, 0, srcfileName, -1, srcFile, 4096);
		MultiByteToWideChar(CP_ACP, 0, bakfileName, -1, bakFile, 4096);
		CopyFile(srcFile, bakFile, false);
		backupOriginal = true;
	}

	fopen_s(&csvfile, srcfileName, "w+");

	if (csvfile && psd.num_files > 0) {
		fprintf(csvfile, "ID,CHANNEL,DUCK,GAIN,LOOP,STOP,NAME,FNAME\n");
		for (int i = 0; i < psd.num_files; ++i) {
			fprintf(csvfile, "0x%4X,", psd.ID[i]);
			if (psd.channel[i] == 2)
				fprintf(csvfile, ",");
			else
				fprintf(csvfile, "%d,", psd.channel[i]);
			fprintf(csvfile, "%d,", psd.ducking[i]);
			fprintf(csvfile, "%d,", psd.gain[i]);
			fprintf(csvfile, "%d,", psd.loop[i]);
			fprintf(csvfile, "%d,", psd.stop[i]);
			fprintf(csvfile, "%s,", psd.description[i]);
			fprintf(csvfile, "%s", psd.filename[i]);
			fprintf(csvfile, "\n");
		}
		fclose(csvfile);
	}
}
private: System::Void CHANNEL_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	psd.channel[index] = CHANNEL->SelectedIndex;
}
private: System::Void DUCK_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	psd.ducking[index] = DUCK->SelectedIndex;
}
private: System::Void GAIN_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	psd.gain[index] = GAIN->SelectedIndex;
}
private: System::Void LOOP_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	psd.loop[index] = LOOP->SelectedIndex;
}
private: System::Void STOP_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	psd.stop[index] = STOP->SelectedIndex;
}
private: System::Void NAME_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	char* description = (char*)Marshal::StringToHGlobalAnsi(NAME->Text).ToPointer();
	strcpy(psd.description[index], description);
}
private: System::Void btnMUSIC_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	CHANNEL->SelectedIndex = psd.channel[index] = 0;
	DUCK->SelectedIndex = psd.ducking[index] = 100;
	GAIN->SelectedIndex = psd.gain[index] = 50;
	LOOP->SelectedIndex = psd.loop[index] = 100;
	STOP->SelectedIndex = psd.stop[index] = 0;

	btnMUSIC->ForeColor = System::Drawing::Color::Red;
	btnVOICE->ForeColor = System::Drawing::Color::Black;
	btnSFX->ForeColor = System::Drawing::Color::Black;
	btnSINGLE->ForeColor = System::Drawing::Color::Black;
	btnJINGLE->ForeColor = System::Drawing::Color::Black;

}
private: System::Void btnVOICE_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	CHANNEL->SelectedIndex = psd.channel[index] = 2;
	DUCK->SelectedIndex = psd.ducking[index] = 65;
	GAIN->SelectedIndex = psd.gain[index] = 50;
	LOOP->SelectedIndex = psd.loop[index] = 0;
	STOP->SelectedIndex = psd.stop[index] = 0;

	btnMUSIC->ForeColor = System::Drawing::Color::Black;
	btnVOICE->ForeColor = System::Drawing::Color::Red;
	btnSFX->ForeColor = System::Drawing::Color::Black;
	btnSINGLE->ForeColor = System::Drawing::Color::Black;
	btnJINGLE->ForeColor = System::Drawing::Color::Black;

}
private: System::Void btnSFX_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	CHANNEL->SelectedIndex = psd.channel[index] = 2;
	DUCK->SelectedIndex = psd.ducking[index] = 80;
	GAIN->SelectedIndex = psd.gain[index] = 50;
	LOOP->SelectedIndex = psd.loop[index] = 0;
	STOP->SelectedIndex = psd.stop[index] = 0;

	btnMUSIC->ForeColor = System::Drawing::Color::Black;
	btnVOICE->ForeColor = System::Drawing::Color::Black;
	btnSFX->ForeColor = System::Drawing::Color::Red;
	btnSINGLE->ForeColor = System::Drawing::Color::Black;
	btnJINGLE->ForeColor = System::Drawing::Color::Black;

}
private: System::Void btnSINGLE_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	CHANNEL->SelectedIndex = psd.channel[index] = 1;
	DUCK->SelectedIndex = psd.ducking[index] = 10;
	GAIN->SelectedIndex = psd.gain[index] = 50;
	LOOP->SelectedIndex = psd.loop[index] = 0;
	STOP->SelectedIndex = psd.stop[index] = 1;

	btnMUSIC->ForeColor = System::Drawing::Color::Black;
	btnVOICE->ForeColor = System::Drawing::Color::Black;
	btnSFX->ForeColor = System::Drawing::Color::Black;
	btnSINGLE->ForeColor = System::Drawing::Color::Red;
	btnJINGLE->ForeColor = System::Drawing::Color::Black;

}
private: System::Void btnJINGLE_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	CHANNEL->SelectedIndex = psd.channel[index] = 1;
	DUCK->SelectedIndex = psd.ducking[index] = 10;
	GAIN->SelectedIndex = psd.gain[index] = 50;
	LOOP->SelectedIndex = psd.loop[index] = 0;
	STOP->SelectedIndex = psd.stop[index] = 0;

	btnMUSIC->ForeColor = System::Drawing::Color::Black;
	btnVOICE->ForeColor = System::Drawing::Color::Black;
	btnSFX->ForeColor = System::Drawing::Color::Black;
	btnSINGLE->ForeColor = System::Drawing::Color::Black;
	btnJINGLE->ForeColor = System::Drawing::Color::Red;

}
private: System::Void btnPLAY_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	int index = ID->SelectedIndex;
	char* soundFile;
	soundFile = (char*)malloc(strlen(srcfileName) + strlen(psd.filename[index]));
	strcpy(soundFile, srcfileName);
	char* ptr = strrchr(soundFile, '\\');
	strcpy(ptr + 1, psd.filename[index]);
	streamHandle = BASS_StreamCreateFile(FALSE, soundFile, 0, 0, 0);
	BASS_ChannelPlay(streamHandle, FALSE);
	free(soundFile);
}
private: System::Void btnSTOP_Click(System::Object^ sender, System::EventArgs^ e) {
	BASS_ChannelStop(streamHandle);
}
private: System::Void FNAME_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		int index = ID->SelectedIndex;
		char* soundFile = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
		char* ptr = strrchr(soundFile, '\\');
		strcpy(psd.filename[index], ptr + 1);
		String^ strNew = gcnew String(psd.filename[index]);
		FNAME->Text = strNew;
	}
}
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	Pin_samples tmp;
	Pin_samples old = psd;

	tmp.num_files = psd.num_files + 1;
	tmp.ID = (int*)malloc((psd.num_files + 1) * sizeof(int));
	tmp.channel = (signed char*)malloc((psd.num_files + 1) * sizeof(signed char));
	tmp.gain = (signed char*)malloc((psd.num_files + 1) * sizeof(float));
	tmp.ducking = (signed char*)malloc((psd.num_files + 1) * sizeof(signed char));
	tmp.loop = (unsigned char*)malloc((psd.num_files + 1) * sizeof(unsigned char));
	tmp.stop = (unsigned char*)malloc((psd.num_files + 1) * sizeof(unsigned char));
	tmp.filename = (char**)malloc((psd.num_files + 1) * sizeof(char*));
	tmp.description = (char**)malloc((psd.num_files + 1) * sizeof(char*));
	

	int k = 0;
	for (int i = 0; i < tmp.num_files; i++)
	{
		if (i < ID->SelectedIndex) {
			k = i;
			tmp.ID[i] = psd.ID[k];
			tmp.channel[i] = psd.channel[k];
			tmp.gain[i] = psd.gain[k];
			tmp.ducking[i] = psd.ducking[k];
			tmp.loop[i] = psd.loop[k];
			tmp.stop[i] = psd.stop[k];
			tmp.filename[i] = psd.filename[k];
			tmp.description[i] = psd.description[k];
		}
		if (i == ID->SelectedIndex) {
			tmp.ID[i] = psd.ID[i];
			tmp.channel[i] = psd.channel[i];
			tmp.gain[i] = psd.gain[i];
			tmp.ducking[i] = psd.ducking[i];
			tmp.loop[i] = psd.loop[i];
			tmp.stop[i] = psd.stop[i];
			tmp.description[i] = (char*)malloc(1024);
			strcpy(tmp.description[i], psd.description[i]);
			tmp.filename[i] = (char*)malloc(1024);
			strcpy(tmp.filename[i], psd.filename[i]);
		}
		if (i > ID->SelectedIndex) {
			k = i - 1;
			tmp.ID[i] = psd.ID[k];
			tmp.channel[i] = psd.channel[k];
			tmp.gain[i] = psd.gain[k];
			tmp.ducking[i] = psd.ducking[k];
			tmp.loop[i] = psd.loop[k];
			tmp.stop[i] = psd.stop[k];
			tmp.filename[i] = psd.filename[k];
			tmp.description[i] = psd.description[k];
		}
	}

	psd = tmp;

	free(old.ID);
	old.ID = 0;
	free(old.filename);
	old.filename = 0;
	free(old.description);
	old.description = 0;
	free(old.gain);
	old.gain = 0;
	free(old.ducking);
	old.ducking = 0;
	free(old.channel);
	old.channel = 0;
	free(old.loop);
	old.loop = 0;
	free(old.stop);
	old.stop = 0;
	old.num_files = 0;

	ID->Items->Clear();
	for (int i = 0; i < psd.num_files; i++)
		ID->Items->Add(psd.ID[i].ToString("X4"));
}
private: System::Void btnDel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ID->SelectedIndex == -1)
		return;
	Pin_samples tmp;
	Pin_samples old = psd;

	tmp.num_files = psd.num_files - 1;
	tmp.ID = (int*)malloc((psd.num_files - 1) * sizeof(int));
	tmp.channel = (signed char*)malloc((psd.num_files - 1) * sizeof(signed char));
	tmp.gain = (signed char*)malloc((psd.num_files - 1) * sizeof(float));
	tmp.ducking = (signed char*)malloc((psd.num_files - 1) * sizeof(signed char));
	tmp.loop = (unsigned char*)malloc((psd.num_files - 1) * sizeof(unsigned char));
	tmp.stop = (unsigned char*)malloc((psd.num_files - 1) * sizeof(unsigned char));
	tmp.filename = (char**)malloc((psd.num_files - 1) * sizeof(char*));
	tmp.description = (char**)malloc((psd.num_files - 1) * sizeof(char*));


	int k = 0;
	for (int i = 0; i < psd.num_files; i++)
	{
		if (i < ID->SelectedIndex) {
			k = i;
			tmp.ID[i] = psd.ID[k];
			tmp.channel[i] = psd.channel[k];
			tmp.gain[i] = psd.gain[k];
			tmp.ducking[i] = psd.ducking[k];
			tmp.loop[i] = psd.loop[k];
			tmp.stop[i] = psd.stop[k];
			tmp.filename[i] = psd.filename[k];
			tmp.description[i] = psd.description[k];
		}
		if (i > ID->SelectedIndex) {
			k = i - 1;
			tmp.ID[k] = psd.ID[i];
			tmp.channel[k] = psd.channel[i];
			tmp.gain[k] = psd.gain[i];
			tmp.ducking[k] = psd.ducking[i];
			tmp.loop[k] = psd.loop[i];
			tmp.stop[k] = psd.stop[i];
			tmp.filename[k] = psd.filename[i];
			tmp.description[k] = psd.description[i];
		}
	}

	psd = tmp;

	free(old.filename[ID->SelectedIndex]);
	free(old.description[ID->SelectedIndex]);
	free(old.ID);
	old.ID = 0;
	free(old.filename);
	old.filename = 0;
	free(old.description);
	old.description = 0;
	free(old.gain);
	old.gain = 0;
	free(old.ducking);
	old.ducking = 0;
	free(old.channel);
	old.channel = 0;
	free(old.loop);
	old.loop = 0;
	free(old.stop);
	old.stop = 0;
	old.num_files = 0;

	ID->Items->Clear();
	for (int i = 0; i < psd.num_files; i++)
		ID->Items->Add(psd.ID[i].ToString("X4"));

	ID->SelectedIndex = 0;
}
};
}
