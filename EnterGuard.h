#pragma once
#include <msclr/marshal_cppstd.h>

#include "Security.h"
#include "Informer.h"

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ EnterGuard
	/// </summary>
	public ref class EnterGuard : public System::Windows::Forms::Form
	{
	private:
		Informer* transferer = nullptr;
	public:
		EnterGuard(Informer* transferer)
		{
			InitializeComponent();
			this->transferer = transferer;
			buttonOK->Select();
			transferer->setPointer(nullptr);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~EnterGuard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxSurname;
	protected:

	protected:

	private: System::Windows::Forms::Button^ buttonOK;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonCancel;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::GroupBox^ groupBox1;










	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSurname = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(94, 54);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(159, 20);
			this->textBoxName->TabIndex = 0;
			this->textBoxName->TextChanged += gcnew System::EventHandler(this, &EnterGuard::textBoxName_TextChanged);
			// 
			// textBoxSurname
			// 
			this->textBoxSurname->Location = System::Drawing::Point(94, 89);
			this->textBoxSurname->Name = L"textBoxSurname";
			this->textBoxSurname->Size = System::Drawing::Size(159, 20);
			this->textBoxSurname->TabIndex = 1;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(251, 129);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(71, 23);
			this->buttonOK->TabIndex = 2;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &EnterGuard::buttonOK_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label1->Location = System::Drawing::Point(5, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"NAME";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label2->Location = System::Drawing::Point(5, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"SURNAME";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label3->Location = System::Drawing::Point(12, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(228, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Enter new guard\'s info below!";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(328, 129);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(71, 23);
			this->buttonCancel->TabIndex = 3;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &EnterGuard::buttonCancel_Click);
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label7->Location = System::Drawing::Point(66, 40);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 18);
			this->label7->TabIndex = 19;
			this->label7->Text = L"10";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Coral;
			this->label9->Location = System::Drawing::Point(66, 58);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 18);
			this->label9->TabIndex = 19;
			this->label9->Text = L"15+10";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label9->Click += gcnew System::EventHandler(this, &EnterGuard::label9_Click);
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(10, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 18);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Armor:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(1, 77);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(68, 18);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Precision:";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(66, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 18);
			this->label5->TabIndex = 19;
			this->label5->Text = L"100";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::YellowGreen;
			this->label11->Location = System::Drawing::Point(66, 77);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(40, 18);
			this->label11->TabIndex = 19;
			this->label11->Text = L"2,2";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(7, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 18);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Health:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label4->Click += gcnew System::EventHandler(this, &EnterGuard::label4_Click);
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(10, 58);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 18);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Damage:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::Color::SaddleBrown;
			this->groupBox1->Location = System::Drawing::Point(278, 21);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(118, 100);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Starting stats";
			// 
			// EnterGuard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 164);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBoxSurname);
			this->Controls->Add(this->textBoxName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"EnterGuard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VA-BANK! Hire Guard";
			this->Load += gcnew System::EventHandler(this, &EnterGuard::EnterGuard_Load);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((textBoxName->Text == "" || textBoxName->Text == " ") || (textBoxSurname->Text == "" || textBoxSurname->Text == " "))
		MessageBox::Show("Error: fill text fields first!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
	{
		::Security* ptr = new ::Security(msclr::interop::marshal_as<std::string>(textBoxName->Text), msclr::interop::marshal_as<std::string>(textBoxSurname->Text), 100, 10, 15, 2.2, "private", 0);

		transferer->getPlayerPTR()->setMoney(transferer->getPlayerPTR()->getMoney() - 1000);
		transferer->setPointer(ptr);
		transferer->setEnterFinished();

		this->Close();
	}
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {

	transferer->setEnterFinished();
	this->Close();
}
private: System::Void textBoxName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EnterGuard_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
