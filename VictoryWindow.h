#pragma once
#include "Player.h"
namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ VictoryWindow
	/// </summary>
	public ref class VictoryWindow : public System::Windows::Forms::Form
	{
	public:
		VictoryWindow(Player* player)
		{
			InitializeComponent();
			std::string text = "Score: ";
			text += std::to_string(player->getScore());

			labelScore->Text = gcnew String(text.c_str());
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~VictoryWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelEnding;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ labelScore;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VictoryWindow::typeid));
			this->labelEnding = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelEnding
			// 
			this->labelEnding->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelEnding->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEnding->ForeColor = System::Drawing::Color::LimeGreen;
			this->labelEnding->Location = System::Drawing::Point(151, 21);
			this->labelEnding->Name = L"labelEnding";
			this->labelEnding->Size = System::Drawing::Size(160, 34);
			this->labelEnding->TabIndex = 57;
			this->labelEnding->Text = L"YOU WIN!";
			this->labelEnding->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::LemonChiffon;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 352);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(396, 24);
			this->label1->TabIndex = 58;
			this->label1->Text = L"Thanks for playing \"VA-BANK!\"";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(192, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(76, 33);
			this->button1->TabIndex = 59;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VictoryWindow::button1_Click);
			// 
			// labelScore
			// 
			this->labelScore->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelScore->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->labelScore->Location = System::Drawing::Point(158, 61);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(147, 24);
			this->labelScore->TabIndex = 60;
			this->labelScore->Text = L"Score: scorenum";
			this->labelScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// VictoryWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(450, 397);
			this->ControlBox = false;
			this->Controls->Add(this->labelScore);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelEnding);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"VictoryWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Victory!!!";
			this->Load += gcnew System::EventHandler(this, &VictoryWindow::VictoryWindow_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VictoryWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
