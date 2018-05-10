#pragma once
#include "Adult9.h"
#include <iostream>
#include <fstream>

namespace Lab9Form {

	using namespace System;
	using namespace System::Globalization;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			myCI = gcnew CultureInfo("en-US", false);
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

	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::Label^  inputLabel;
	private: System::Windows::Forms::Button^  writeBut;
	private: System::Windows::Forms::TextBox^  outputBox;
	private: System::Windows::Forms::Button^  printBut;
	private: System::Windows::Forms::Button^  clearOutputBut;
	private: System::Windows::Forms::Label^  outputLabel;
	private: System::Windows::Forms::Button^  clearTXTBut;
	private: CultureInfo ^ myCI;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->inputLabel = (gcnew System::Windows::Forms::Label());
			this->writeBut = (gcnew System::Windows::Forms::Button());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->printBut = (gcnew System::Windows::Forms::Button());
			this->clearOutputBut = (gcnew System::Windows::Forms::Button());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->clearTXTBut = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// inputBox
			// 
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputBox->Location = System::Drawing::Point(70, 60);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(240, 360);
			this->inputBox->TabIndex = 0;
			// 
			// inputLabel
			// 
			this->inputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->inputLabel->Location = System::Drawing::Point(135, 37);
			this->inputLabel->Name = L"inputLabel";
			this->inputLabel->Size = System::Drawing::Size(109, 20);
			this->inputLabel->TabIndex = 1;
			this->inputLabel->Text = L"Type info here";
			// 
			// writeBut
			// 
			this->writeBut->Location = System::Drawing::Point(235, 423);
			this->writeBut->Name = L"writeBut";
			this->writeBut->Size = System::Drawing::Size(75, 25);
			this->writeBut->TabIndex = 2;
			this->writeBut->Text = L"Write";
			this->writeBut->UseVisualStyleBackColor = true;
			this->writeBut->Click += gcnew System::EventHandler(this, &MyForm::writeBut_Click);
			// 
			// outputBox
			// 
			this->outputBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->outputBox->Location = System::Drawing::Point(330, 60);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->Size = System::Drawing::Size(240, 360);
			this->outputBox->TabIndex = 3;
			// 
			// printBut
			// 
			this->printBut->Location = System::Drawing::Point(495, 423);
			this->printBut->Name = L"printBut";
			this->printBut->Size = System::Drawing::Size(75, 25);
			this->printBut->TabIndex = 4;
			this->printBut->Text = L"Print here";
			this->printBut->UseVisualStyleBackColor = true;
			this->printBut->Click += gcnew System::EventHandler(this, &MyForm::printBut_Click);
			// 
			// clearOutputBut
			// 
			this->clearOutputBut->Location = System::Drawing::Point(414, 423);
			this->clearOutputBut->Name = L"clearOutputBut";
			this->clearOutputBut->Size = System::Drawing::Size(75, 25);
			this->clearOutputBut->TabIndex = 5;
			this->clearOutputBut->Text = L"Clear output";
			this->clearOutputBut->UseVisualStyleBackColor = true;
			this->clearOutputBut->Click += gcnew System::EventHandler(this, &MyForm::clearOutputBut_Click);
			// 
			// outputLabel
			// 
			this->outputLabel->AutoSize = true;
			this->outputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->outputLabel->Location = System::Drawing::Point(380, 37);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(140, 20);
			this->outputLabel->TabIndex = 6;
			this->outputLabel->Text = L"Output file content";
			// 
			// clearTXTBut
			// 
			this->clearTXTBut->Location = System::Drawing::Point(333, 423);
			this->clearTXTBut->Name = L"clearTXTBut";
			this->clearTXTBut->Size = System::Drawing::Size(75, 25);
			this->clearTXTBut->TabIndex = 7;
			this->clearTXTBut->Text = L"Clear txt file";
			this->clearTXTBut->UseVisualStyleBackColor = true;
			this->clearTXTBut->Click += gcnew System::EventHandler(this, &MyForm::clearTXTBut_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 480);
			this->Controls->Add(this->clearTXTBut);
			this->Controls->Add(this->outputLabel);
			this->Controls->Add(this->clearOutputBut);
			this->Controls->Add(this->printBut);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->writeBut);
			this->Controls->Add(this->inputLabel);
			this->Controls->Add(this->inputBox);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Lab8";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void writeBut_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			String^ temp;
			Abstract** humArr = new Abstract*[15];
			std::ofstream fout("output.txt", std::ios::app);
			if (!fout) {
				throw std::invalid_argument("Bad output stream in writeBut_Click");
			}
			if (this->inputBox->Text != "") {
				array<System::String^>^ strArr = this->inputBox->Text->Split('\n');
				array<System::String^>^ arr = gcnew array<System::String^>(0);
				char* name;
				for (int i = 0; i < strArr->Length; i++) {
					arr = strArr[i]->Split(',');
					name = new char[arr[0]->Length + 1];
					for (int j = 0; j < arr[0]->Length; j++) {
						name[j] = arr[0][j];
					}
					name[arr[0]->Length] = '\0';
					if (arr->Length == 4) {
						Adult* ad = new Adult(name, Double::Parse(arr[1], myCI->NumberFormat), Double::Parse(arr[2], myCI->NumberFormat), Int32::Parse(arr[3]));
						humArr[i] = ad;
					}
					else if (arr->Length == 3) {
						Human* hum = new Human(name, Double::Parse(arr[1], myCI->NumberFormat), Double::Parse(arr[2], myCI->NumberFormat));
						humArr[i] = hum;
					}
					humArr[i]->print(fout);
					fout << std::endl;
					delete[] name;
				}
				this->inputBox->Text = "";
			}
		}
		catch (std::invalid_argument ia) {
			MessageBox::Show(%String(ia.what()));
		}
	}
	private: System::Void printBut_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			std::ifstream fin("output.txt");
			if (!fin) {
				throw std::invalid_argument("Bad input stream in printBut_click");
			}
			bool read = false;
			char* temp = new char[255];
			while (fin.getline(temp, 254)) {
				read = true;
				this->outputBox->Text += %String(temp) + "\r\n";
			}
			if (read) {
				this->outputBox->Text += "\r\n";
			}
			else {
				this->outputBox->Text += "File is empty.\r\n";
			}
			delete[] temp;
		}
		catch (std::invalid_argument ia) {
			MessageBox::Show(%String(ia.what()));
		}
	}
	private: System::Void clearOutputBut_Click(System::Object^  sender, System::EventArgs^  e) {
		this->outputBox->Text = "";
	}

	private: System::Void clearTXTBut_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			std::ofstream fout("output.txt");
			if (!fout) {
				throw std::invalid_argument("Bad output stream in writeBut_Click");
			}
			this->outputBox->Text = "";
			fout << "";
		}
		catch (std::invalid_argument ia) {
			MessageBox::Show(%String(ia.what()));
		}
	}
	};
}
