#pragma once
#include "math.h"

#include "Security.h"
#include "Informer.h"
#include "EnterGuard.h"
#include "LoadoutWindow.h"

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ SecurityInventory
	/// </summary>

	public ref class SecurityInventory : public System::Windows::Forms::Form
	{
	private:
		Informer* transferer = nullptr;
		int button_index;
	private: System::Windows::Forms::Button^ buttonCancel;

	private: System::Windows::Forms::Label^ labelMoney;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonHelp;

	private: System::Windows::Forms::Timer^ timer1;
	public:
		SecurityInventory(Informer* transferer, int button_index)
		{
			InitializeComponent();
			this->transferer = transferer;
			this->button_index = button_index;

			buttonPlace->Enabled = false;
			buttonPlace->BackColor = System::Drawing::Color::DarkGray;
			buttonEquipment->Enabled = false;
			buttonEquipment->BackColor = System::Drawing::Color::DarkGray;

			labelMoney->Text = gcnew String((std::to_string((transferer->getPlayerPTR()->getMoney())).c_str()));
			labelMoney->Text += gcnew String(("$"));
			labelNAME->Text = "CHOOSE";
			labelSURNAME->Text = "SECURITY";

			labelHP->Text = "-";
			labelAP->Text = "-";
			labelDamage->Text = "-";
			labelPrecision->Text = "-";
			labelRank->Text = "-";
			labelWins->Text = "-";


			Player* player_ptr = this->transferer->getPlayerPTR();
			for (int i = 0; i < player_ptr->getGuardsAmount(); i++)
			{
				::Security buff_s = player_ptr->getGuard(i);
				std::string buff_str;
				// €кщо охоронець зайн€тий (знаходитьс€ на позиц≥њ)
				if (buff_s.isOnPosition())
				{
					buff_str = "[X] ";
				}
				else
				{
					buff_str = std::to_string((i + 1)) + ". ";
				}
				buff_str += buff_s.getName();
				buff_str += " ";
				buff_str += buff_s.getSurname();
				listBox1->Items->Add(gcnew String((buff_str.c_str())));
			}

			//
			//TODO: добавьте код конструктора
			//
		}


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SecurityInventory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelNAME;
	private: System::Windows::Forms::Label^ labelSURNAME;


	private: System::Windows::Forms::Label^ labelHP;
	private: System::Windows::Forms::Label^ labelAP;
	private: System::Windows::Forms::Label^ labelDamage;
	private: System::Windows::Forms::Label^ labelPrecision;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ labelRank;
	private: System::Windows::Forms::Label^ labelWins;
	private: System::Windows::Forms::Button^ buttonEquipment;
	private: System::Windows::Forms::Button^ buttonPlace;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;





	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SecurityInventory::typeid));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelNAME = (gcnew System::Windows::Forms::Label());
			this->labelSURNAME = (gcnew System::Windows::Forms::Label());
			this->labelHP = (gcnew System::Windows::Forms::Label());
			this->labelAP = (gcnew System::Windows::Forms::Label());
			this->labelDamage = (gcnew System::Windows::Forms::Label());
			this->labelPrecision = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelRank = (gcnew System::Windows::Forms::Label());
			this->labelWins = (gcnew System::Windows::Forms::Label());
			this->buttonEquipment = (gcnew System::Windows::Forms::Button());
			this->buttonPlace = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelMoney = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 22;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(134, 202);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &SecurityInventory::listBox1_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(152, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(190, 306);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(348, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Health:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(348, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Armor:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(348, 156);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 18);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Damage:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(348, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 18);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Precision:";
			// 
			// labelNAME
			// 
			this->labelNAME->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNAME->Location = System::Drawing::Point(356, 17);
			this->labelNAME->Name = L"labelNAME";
			this->labelNAME->Size = System::Drawing::Size(115, 19);
			this->labelNAME->TabIndex = 6;
			this->labelNAME->Text = L"NAME";
			this->labelNAME->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelSURNAME
			// 
			this->labelSURNAME->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSURNAME->Location = System::Drawing::Point(356, 38);
			this->labelSURNAME->Name = L"labelSURNAME";
			this->labelSURNAME->Size = System::Drawing::Size(115, 19);
			this->labelSURNAME->TabIndex = 7;
			this->labelSURNAME->Text = L"SURNAME";
			this->labelSURNAME->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelSURNAME->Click += gcnew System::EventHandler(this, &SecurityInventory::labelSURNAME_Click);
			// 
			// labelHP
			// 
			this->labelHP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP->ForeColor = System::Drawing::Color::Red;
			this->labelHP->Location = System::Drawing::Point(437, 99);
			this->labelHP->Name = L"labelHP";
			this->labelHP->Size = System::Drawing::Size(40, 18);
			this->labelHP->TabIndex = 8;
			this->labelHP->Text = L"hp";
			this->labelHP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelHP->Click += gcnew System::EventHandler(this, &SecurityInventory::labelHP_Click);
			// 
			// labelAP
			// 
			this->labelAP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP->Location = System::Drawing::Point(437, 128);
			this->labelAP->Name = L"labelAP";
			this->labelAP->Size = System::Drawing::Size(40, 18);
			this->labelAP->TabIndex = 9;
			this->labelAP->Text = L"ap";
			this->labelAP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelDamage
			// 
			this->labelDamage->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDamage->ForeColor = System::Drawing::Color::Coral;
			this->labelDamage->Location = System::Drawing::Point(437, 156);
			this->labelDamage->Name = L"labelDamage";
			this->labelDamage->Size = System::Drawing::Size(40, 18);
			this->labelDamage->TabIndex = 10;
			this->labelDamage->Text = L"dmg";
			this->labelDamage->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelDamage->Click += gcnew System::EventHandler(this, &SecurityInventory::labelDamage_Click);
			// 
			// labelPrecision
			// 
			this->labelPrecision->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelPrecision->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelPrecision->Location = System::Drawing::Point(437, 185);
			this->labelPrecision->Name = L"labelPrecision";
			this->labelPrecision->Size = System::Drawing::Size(40, 18);
			this->labelPrecision->TabIndex = 11;
			this->labelPrecision->Text = L"prcsn";
			this->labelPrecision->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(348, 212);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 18);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Wins:";
			// 
			// labelRank
			// 
			this->labelRank->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelRank->ForeColor = System::Drawing::Color::Gray;
			this->labelRank->Location = System::Drawing::Point(356, 57);
			this->labelRank->Name = L"labelRank";
			this->labelRank->Size = System::Drawing::Size(117, 18);
			this->labelRank->TabIndex = 14;
			this->labelRank->Text = L"guardRank";
			this->labelRank->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelWins
			// 
			this->labelWins->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelWins->ForeColor = System::Drawing::Color::Gray;
			this->labelWins->Location = System::Drawing::Point(440, 212);
			this->labelWins->Name = L"labelWins";
			this->labelWins->Size = System::Drawing::Size(37, 18);
			this->labelWins->TabIndex = 15;
			this->labelWins->Text = L"wins";
			this->labelWins->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// buttonEquipment
			// 
			this->buttonEquipment->BackColor = System::Drawing::Color::Gold;
			this->buttonEquipment->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonEquipment->Location = System::Drawing::Point(348, 235);
			this->buttonEquipment->Name = L"buttonEquipment";
			this->buttonEquipment->Size = System::Drawing::Size(129, 25);
			this->buttonEquipment->TabIndex = 16;
			this->buttonEquipment->Text = L"Equipment";
			this->buttonEquipment->UseVisualStyleBackColor = false;
			this->buttonEquipment->Click += gcnew System::EventHandler(this, &SecurityInventory::buttonEquipment_Click);
			// 
			// buttonPlace
			// 
			this->buttonPlace->BackColor = System::Drawing::Color::LimeGreen;
			this->buttonPlace->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonPlace->Location = System::Drawing::Point(348, 266);
			this->buttonPlace->Name = L"buttonPlace";
			this->buttonPlace->Size = System::Drawing::Size(129, 25);
			this->buttonPlace->TabIndex = 17;
			this->buttonPlace->Text = L"Place!";
			this->buttonPlace->UseVisualStyleBackColor = false;
			this->buttonPlace->Click += gcnew System::EventHandler(this, &SecurityInventory::buttonPlace_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::YellowGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(12, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 39);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Hire New Guard (1000$)";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SecurityInventory::buttonHire_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &SecurityInventory::timer1_Tick);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonCancel->Location = System::Drawing::Point(348, 297);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(129, 23);
			this->buttonCancel->TabIndex = 19;
			this->buttonCancel->Text = L"Close";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &SecurityInventory::buttonCancel_Click);
			// 
			// labelMoney
			// 
			this->labelMoney->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelMoney->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMoney->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelMoney->Location = System::Drawing::Point(79, 302);
			this->labelMoney->Name = L"labelMoney";
			this->labelMoney->Size = System::Drawing::Size(66, 18);
			this->labelMoney->TabIndex = 40;
			this->labelMoney->Text = L"money";
			this->labelMoney->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 299);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 22);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Money:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonHelp
			// 
			this->buttonHelp->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHelp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHelp.Image")));
			this->buttonHelp->Location = System::Drawing::Point(29, 219);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(95, 35);
			this->buttonHelp->TabIndex = 51;
			this->buttonHelp->Text = L"Help";
			this->buttonHelp->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &SecurityInventory::buttonHelp_Click);
			// 
			// SecurityInventory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(483, 330);
			this->ControlBox = false;
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->labelMoney);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->buttonPlace);
			this->Controls->Add(this->buttonEquipment);
			this->Controls->Add(this->labelWins);
			this->Controls->Add(this->labelRank);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->labelPrecision);
			this->Controls->Add(this->labelDamage);
			this->Controls->Add(this->labelAP);
			this->Controls->Add(this->labelHP);
			this->Controls->Add(this->labelSURNAME);
			this->Controls->Add(this->labelNAME);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->listBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"SecurityInventory";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VA-BANK! Inventory";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SecurityInventory::SecurityInventory_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SecurityInventory::SecurityInventory_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (listBox1->SelectedIndex != -1)
		{
			::Security guard = this->transferer->getPlayerPTR()->getGuard(listBox1->SelectedIndex);
			
			labelNAME->Text = gcnew String((guard.getName()).c_str());
			labelSURNAME->Text = gcnew String((guard.getSurname()).c_str());
			labelHP->Text = gcnew String((std::to_string((guard.getHealthPoints() + guard.getStuff().getBonusHP()))).c_str());
			labelAP->Text = gcnew String((std::to_string((guard.getArmorPoints() + guard.getStuff().getBonusAP()))).c_str());
			labelDamage->Text = gcnew String((std::to_string((guard.getDamage() + guard.getWeapon().getDamage() + guard.getStuff().getBonusDamage()))).c_str());
			// ќ –”√Ћ≈ЌЌя
			labelPrecision->Text = ((Math::Round((guard).getPrecision(), 2))).ToString();
			labelRank->Text = gcnew String((guard.getRank()).c_str());
			labelWins->Text = gcnew String((std::to_string((guard.getWins()))).c_str());

			if (guard.isOnPosition())
			{
				buttonPlace->Enabled = false;
				buttonPlace->BackColor = System::Drawing::Color::DarkGray;
			}
			else
			{
				buttonPlace->Enabled = true;
				buttonPlace->BackColor = System::Drawing::Color::LimeGreen;
			}
			buttonEquipment->Enabled = true;
			buttonEquipment->BackColor = System::Drawing::Color::Gold;
		}
	}
	private: System::Void SecurityInventory_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelSURNAME_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelDamage_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelHP_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonPlace_Click(System::Object^ sender, System::EventArgs^ e) {
		GuardsContainer* gc_ptr = transferer->getPlayerPTR()->getGuardsContainerPTR();
		::Security* sec_ptr = transferer->getPlayerPTR()->getGuardPTR(listBox1->SelectedIndex);

		// встановлюЇмо в ≥нформатор≥ у контейнер≥ охоронц≥в нового охоронц€ на м≥сце, з €кого викликано форму
		gc_ptr->insert(std::make_pair(Convert::ToInt32(this->button_index), sec_ptr));
		// охоронець стаЇ "зайн€тим"
		sec_ptr->setOnPosition();
		// видаЇмо флаг дл€ ≥нформатора €к такий, що розм≥щенн€ в≥дбулос€
		transferer->setGuardsPlaced(Convert::ToInt32(this->button_index));

		transferer->setFormFinished();
		this->Close();
	}
	private: System::Void buttonHire_Click(System::Object^ sender, System::EventArgs^ e) {
		Player* player_ptr = transferer->getPlayerPTR();

		if (player_ptr->getGuardsAmount() != 10 && player_ptr->getMoney() - 1000 >= 0)
		{
			this->Enabled = false;

			EnterGuard^ window = gcnew EnterGuard(transferer);
			window->Show();
		}
		else if (player_ptr->getMoney() - 1000 < 0)
		{
			MessageBox::Show("Not enough money!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (player_ptr->getGuardsAmount() == 10)
		{
			MessageBox::Show("You can't hire more than 10 guards!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
						
	}
	private: System::Void SecurityInventory_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (transferer->isEnterFinished())
		{ 
			if (transferer->getPointer() != nullptr)
			{
				Player* player_ptr = transferer->getPlayerPTR();
				::Security* sec_ptr = player_ptr->getGuardPTR(player_ptr->getGuardsAmount());
				*sec_ptr = *(::Security*)transferer->getPointer();
				player_ptr->setGuard(player_ptr->getGuardsAmount(), *sec_ptr);
				player_ptr->setGuardsAmount(player_ptr->getGuardsAmount() + 1);

				std::string buffer = std::to_string(player_ptr->getGuardsAmount()) + ". ";
				buffer += player_ptr->getGuardPTR(player_ptr->getGuardsAmount() - 1)->getName();
				buffer += " ";
				buffer += player_ptr->getGuardPTR(player_ptr->getGuardsAmount() - 1)->getSurname();
				this->listBox1->Items->Add(gcnew String(buffer.c_str()));

				// оновленн€ рахунку
				labelMoney->Text = gcnew String((std::to_string((transferer->getPlayerPTR()->getMoney())).c_str()));
				labelMoney->Text += gcnew String(("$"));
			}
			this->Enabled = true;
			this->Select();

			transferer->setEnterFinished();
		}
		if (transferer->isEquipmentFinishedInvCall())
		{
			::Security guard = transferer->getPlayerPTR()->getGuard(listBox1->SelectedIndex);

			labelHP->Text = gcnew String((std::to_string((guard.getHealthPoints() + guard.getStuff().getBonusHP()))).c_str());
			labelAP->Text = gcnew String((std::to_string((guard.getArmorPoints() + guard.getStuff().getBonusAP()))).c_str());
			labelDamage->Text = gcnew String((std::to_string((guard.getDamage() + guard.getWeapon().getDamage() + guard.getStuff().getBonusDamage()))).c_str());

			// оновленн€ рахунку
			labelMoney->Text = gcnew String((std::to_string((transferer->getPlayerPTR()->getMoney())).c_str()));
			labelMoney->Text += gcnew String(("$"));

			this->Enabled = true;
			this->Select();
			transferer->setEquipmentFinishedInvCall();
		}

	}
private: System::Void buttonEquipment_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadoutWindow^ window = gcnew LoadoutWindow(transferer, Convert::ToInt32(listBox1->SelectedIndex), 1);
	window->Show();
	this->Enabled = false;
}
private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	transferer->setFormFinished();
	this->Close();
}
private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("\nIf you need guards - press 'Hire New Guard' button. To place a guard, select it from list"
		+ " at the left and press 'Place!' button.\nIf you need to see loadout of your guard - press 'Equipment' "
		+ "button. Pressing this button, you can also buy new items for him.'\n\nSTATS:\nHealth - how many damage "
		+ "unit can take.\nArmor - takes damage first. If ends - health takes instead.\nPrecision - multiplier of "
		+ "critical damage (doesn't depend on body parts).\nWins - how many rounds guard has won.",
		"Help", MessageBoxButtons::OK, MessageBoxIcon::Question);
}
};
}
