#pragma once
#include <string>

#include "Security.h"
#include "Informer.h"
#include "Weapon.h"
#include "Equipment.h"

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// зброя магазину
	Weapon shopWeapons[8] =
	{Weapon("P250", 650, 20), Weapon("Remington 870", 1000, 30), Weapon("XM1014", 1250, 35),
	 Weapon("MP9", 1600, 40), Weapon("UMP-45", 1900, 45), Weapon("FAMAS", 2300, 55),
	 Weapon("Galil", 2600, 60), Weapon("Negev", 3100, 70)};
	
	// обладнання магазину
	Equipment shopEquipment[6] =
	{ Equipment("Light Armor", 400, 0, 20, 0), Equipment("Medium Armor", 800, 0, 50, 0),
	  Equipment("Heavy Armor", 1500, 0, 100, 0), Equipment("Life Support Module", 1700, 75, 50, 0),
	  Equipment("Protein Drink", 300, 0, 0, 10), Equipment("Un-I-mplant", 3500, 100, 100, 30) };

	// опис зброї (форма)
	std::string descriptionsWeapons[8]
	{	"Semi-automatic SIG-Sauer pistol, made in USA. The pistol has high rate of fire and low recoil. Obviously, the most common and inexpensive handgun.",
		"A pump-action shotgun, manufactured by Remington Arms Company. Widely used by law enforcement because of its distinctive reload.",
		"The XM1014 is a poweful fully automatic shotgun, produced by Italian firearm manufacturer Benelli Armi SpA. Used by the armed forces of Italy, the USA and UK.",
		"Manufactured in Switzerland, the cutting-edge MP9 SMG is an ergonomic polymer weapon favored by private security firms. Manufactured by Steyr Mannlicher of Austria.",
		"The misunderstood middle child of the SMG family, the UMP45's small magazine is the only drawback to an otherwise versatile close-quarters automatic. Made by Heckler & Koch.",
		"A cheap option for cash-strapped players, the FAMAS rifle effectively fills the niche between more expensive rifles and the less-effective SMGs.",
		"“Galil AR is a serviceable weapon in medium to long-range combat. Manufactured in Israel, services as analog of russian AK-47.",
		"The Negev is a beast that can keep the enemy at bay with its pin-point supressive fire, provided you have the luxury of time to gain control over it. A deadly weapon with no excuses."
	};
	// опис знаряддя (форма)
	std::string descriptionsEquipment[6]
	{	"A common armor for security guards. Widely used in different private companies.",
		"Used in police forces, this average armor brings decent protection.",
		"A really tough armor, weared by every military soldier and SWAT enforcements. Nearly unbreakable.",
		"Experimental module, invented by modern scientists. Wasn't tested before for effectiveness and safety. As they say, module provides incredible protection.",
		"Favorite drink of every sportsman, that helps you to grow massive muscules, increasing physical power.",
		"Forbidden technology around the world. Invented by the japanese company 'War-Shau-5K1', this implant highly increases human's strength and survivability."
	};;

	/// <summary>
	/// Сводка для LoadoutWindow
	/// </summary>
	public ref class LoadoutWindow : public System::Windows::Forms::Form
	{
	private:
		Informer* transferer = nullptr;
		::Security* current_guard;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox3;
		   bool main;

		// внутрішньо-класовий візуалізатор
		void Visualizer()
		{
			labelHP->Text = gcnew String((std::to_string((this->current_guard->getHealthPoints() + this->current_guard->getStuff().getBonusHP()))).c_str());
			labelAP->Text = gcnew String((std::to_string((this->current_guard->getArmorPoints() + this->current_guard->getStuff().getBonusAP()))).c_str());
			labelDMG->Text = gcnew String((std::to_string((this->current_guard->getDamage() + this->current_guard->getWeapon().getDamage() + this->current_guard->getStuff().getBonusDamage()))).c_str());

			labelWeapon_name->Text = gcnew String((this->current_guard->getWeapon().getName()).c_str());
			labelWeapon_damage->Text = gcnew String(("+"));
			labelWeapon_damage->Text += gcnew String((std::to_string((this->current_guard->getWeapon().getDamage()))).c_str());

			labelEquipment_name->Text = gcnew String((this->current_guard->getStuff().getName()).c_str());
			labelEq_Dmg->Text = gcnew String(("+"));
			labelEq_Dmg->Text += gcnew String((std::to_string((this->current_guard->getStuff().getBonusDamage())).c_str()));
			labelEq_HP->Text = gcnew String(("+"));
			labelEq_HP->Text += gcnew String((std::to_string((this->current_guard->getStuff().getBonusHP())).c_str()));;
			labelEq_AP->Text = gcnew String(("+"));
			labelEq_AP->Text += gcnew String((std::to_string((this->current_guard->getStuff().getBonusAP())).c_str()));;

			labelMoney->Text = gcnew String((std::to_string((transferer->getPlayerPTR()->getMoney()))).c_str());
			labelMoney->Text += gcnew String(("$"));
		}

		// внутрішньо-класовий завантажувач інформації комбо-боксу
		void ComboBoxLoader(bool mode)
		{
			if (mode == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					std::string str = std::to_string(shopWeapons[i].getPrice());
					str += "$ ";
					str += shopWeapons[i].getName();
					comboBox1->Items->Add(gcnew String(str.c_str()));
				}
			}
			else
				for (int i = 0; i < 6; i++)
				{
					std::string str = std::to_string(shopEquipment[i].getPrice());
					str += "$ ";
					str += shopEquipment[i].getName();
					comboBox2->Items->Add(gcnew String(str.c_str()));
				}
		}

	public:
		LoadoutWindow(Informer* transferer, int g_index, bool main)
		{
			InitializeComponent();
			this->transferer = transferer;
			this->main = main;

			// якщо виклик з основної форми
			if (this->main == 0)
				this->current_guard = this->transferer->getPlayerPTR()->getGuardsContainerPTR()->find(g_index)->second;
			// якщо виклик з інвентаря
			else
				this->current_guard = this->transferer->getPlayerPTR()->getGuardPTR(g_index);

			Visualizer();
			labelNAME->Text = gcnew String((this->current_guard->getName()).c_str());
			labelSURNAME->Text = gcnew String((this->current_guard->getSurname()).c_str());
			
			labelPrecision->Text = (Math::Round(this->current_guard->getPrecision(), 2)).ToString();
			labelRank->Text = gcnew String((this->current_guard->getRank()).c_str());
			labelWins->Text = gcnew String((std::to_string((this->current_guard->getWins()))).c_str());

			ComboBoxLoader(0);
			ComboBoxLoader(1);

			comboBox1->SelectedIndex = 0;
			comboBox2->SelectedIndex = 0;

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~LoadoutWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ labelWeapons;
	private: System::Windows::Forms::Label^ labelEquipment;
	private: System::Windows::Forms::Button^ buttonOK;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ labelNAME;
	private: System::Windows::Forms::Label^ labelHealth;
	private: System::Windows::Forms::Label^ labelArmor;
	private: System::Windows::Forms::Label^ labelDamage;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelSURNAME;
	private: System::Windows::Forms::Label^ labelHP;
	private: System::Windows::Forms::Label^ labelAP;
	private: System::Windows::Forms::Label^ labelDMG;
	private: System::Windows::Forms::Label^ labelPrecision;
	private: System::Windows::Forms::Label^ labelRank;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelWins;
	private: System::Windows::Forms::Label^ labelWeapon_name;
	private: System::Windows::Forms::Label^ labelWeapon_damage;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ labelEq_HP;
	private: System::Windows::Forms::Label^ labelEquipment_name;
	private: System::Windows::Forms::Label^ labelEq_Dmg;
	private: System::Windows::Forms::Label^ labelEq_AP;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelMoney;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoadoutWindow::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->labelWeapons = (gcnew System::Windows::Forms::Label());
			this->labelEquipment = (gcnew System::Windows::Forms::Label());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelNAME = (gcnew System::Windows::Forms::Label());
			this->labelHealth = (gcnew System::Windows::Forms::Label());
			this->labelArmor = (gcnew System::Windows::Forms::Label());
			this->labelDamage = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->labelSURNAME = (gcnew System::Windows::Forms::Label());
			this->labelHP = (gcnew System::Windows::Forms::Label());
			this->labelAP = (gcnew System::Windows::Forms::Label());
			this->labelDMG = (gcnew System::Windows::Forms::Label());
			this->labelPrecision = (gcnew System::Windows::Forms::Label());
			this->labelRank = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelWins = (gcnew System::Windows::Forms::Label());
			this->labelWeapon_name = (gcnew System::Windows::Forms::Label());
			this->labelWeapon_damage = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->labelEq_AP = (gcnew System::Windows::Forms::Label());
			this->labelEq_HP = (gcnew System::Windows::Forms::Label());
			this->labelEquipment_name = (gcnew System::Windows::Forms::Label());
			this->labelEq_Dmg = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelMoney = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(16, 303);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(166, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &LoadoutWindow::comboBox1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(16, 449);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(166, 41);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Buy and Equip";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LoadoutWindow::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(214, 449);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(166, 41);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Buy and Equip";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LoadoutWindow::button3_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(214, 303);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(166, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &LoadoutWindow::comboBox2_SelectedIndexChanged);
			// 
			// labelWeapons
			// 
			this->labelWeapons->BackColor = System::Drawing::Color::Orange;
			this->labelWeapons->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelWeapons->Location = System::Drawing::Point(16, 278);
			this->labelWeapons->Name = L"labelWeapons";
			this->labelWeapons->Size = System::Drawing::Size(166, 22);
			this->labelWeapons->TabIndex = 7;
			this->labelWeapons->Text = L"Weapons";
			this->labelWeapons->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelEquipment
			// 
			this->labelEquipment->BackColor = System::Drawing::Color::Orange;
			this->labelEquipment->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEquipment->Location = System::Drawing::Point(214, 278);
			this->labelEquipment->Name = L"labelEquipment";
			this->labelEquipment->Size = System::Drawing::Size(166, 22);
			this->labelEquipment->TabIndex = 8;
			this->labelEquipment->Text = L"Equipment";
			this->labelEquipment->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonOK
			// 
			this->buttonOK->BackColor = System::Drawing::Color::LimeGreen;
			this->buttonOK->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonOK->Location = System::Drawing::Point(214, 497);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(166, 29);
			this->buttonOK->TabIndex = 9;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = false;
			this->buttonOK->Click += gcnew System::EventHandler(this, &LoadoutWindow::buttonOK_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(164, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(71, 210);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &LoadoutWindow::pictureBox1_Click);
			// 
			// labelNAME
			// 
			this->labelNAME->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNAME->Location = System::Drawing::Point(257, 14);
			this->labelNAME->Name = L"labelNAME";
			this->labelNAME->Size = System::Drawing::Size(115, 19);
			this->labelNAME->TabIndex = 23;
			this->labelNAME->Text = L"NAME";
			this->labelNAME->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHealth
			// 
			this->labelHealth->AutoSize = true;
			this->labelHealth->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHealth->Location = System::Drawing::Point(251, 84);
			this->labelHealth->Name = L"labelHealth";
			this->labelHealth->Size = System::Drawing::Size(49, 18);
			this->labelHealth->TabIndex = 19;
			this->labelHealth->Text = L"Health:";
			// 
			// labelArmor
			// 
			this->labelArmor->AutoSize = true;
			this->labelArmor->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelArmor->Location = System::Drawing::Point(251, 113);
			this->labelArmor->Name = L"labelArmor";
			this->labelArmor->Size = System::Drawing::Size(47, 18);
			this->labelArmor->TabIndex = 20;
			this->labelArmor->Text = L"Armor:";
			// 
			// labelDamage
			// 
			this->labelDamage->AutoSize = true;
			this->labelDamage->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDamage->Location = System::Drawing::Point(251, 141);
			this->labelDamage->Name = L"labelDamage";
			this->labelDamage->Size = System::Drawing::Size(57, 18);
			this->labelDamage->TabIndex = 21;
			this->labelDamage->Text = L"Damage:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(251, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 18);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Precision:";
			// 
			// labelSURNAME
			// 
			this->labelSURNAME->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSURNAME->Location = System::Drawing::Point(257, 35);
			this->labelSURNAME->Name = L"labelSURNAME";
			this->labelSURNAME->Size = System::Drawing::Size(115, 19);
			this->labelSURNAME->TabIndex = 24;
			this->labelSURNAME->Text = L"SURNAME";
			this->labelSURNAME->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHP
			// 
			this->labelHP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP->ForeColor = System::Drawing::Color::Red;
			this->labelHP->Location = System::Drawing::Point(342, 84);
			this->labelHP->Name = L"labelHP";
			this->labelHP->Size = System::Drawing::Size(40, 18);
			this->labelHP->TabIndex = 25;
			this->labelHP->Text = L"hp";
			this->labelHP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelAP
			// 
			this->labelAP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP->Location = System::Drawing::Point(342, 113);
			this->labelAP->Name = L"labelAP";
			this->labelAP->Size = System::Drawing::Size(40, 18);
			this->labelAP->TabIndex = 26;
			this->labelAP->Text = L"ap";
			this->labelAP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelDMG
			// 
			this->labelDMG->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDMG->ForeColor = System::Drawing::Color::Coral;
			this->labelDMG->Location = System::Drawing::Point(342, 141);
			this->labelDMG->Name = L"labelDMG";
			this->labelDMG->Size = System::Drawing::Size(40, 18);
			this->labelDMG->TabIndex = 27;
			this->labelDMG->Text = L"dmg";
			this->labelDMG->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelPrecision
			// 
			this->labelPrecision->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelPrecision->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelPrecision->Location = System::Drawing::Point(342, 170);
			this->labelPrecision->Name = L"labelPrecision";
			this->labelPrecision->Size = System::Drawing::Size(40, 18);
			this->labelPrecision->TabIndex = 28;
			this->labelPrecision->Text = L"prcsn";
			this->labelPrecision->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelRank
			// 
			this->labelRank->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelRank->ForeColor = System::Drawing::Color::Gray;
			this->labelRank->Location = System::Drawing::Point(257, 54);
			this->labelRank->Name = L"labelRank";
			this->labelRank->Size = System::Drawing::Size(117, 18);
			this->labelRank->TabIndex = 29;
			this->labelRank->Text = L"guardRank";
			this->labelRank->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox1->Location = System::Drawing::Point(16, 330);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(166, 111);
			this->textBox1->TabIndex = 30;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox2->Location = System::Drawing::Point(214, 330);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(166, 111);
			this->textBox2->TabIndex = 31;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LoadoutWindow::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(251, 198);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 18);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Wins:";
			// 
			// labelWins
			// 
			this->labelWins->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelWins->ForeColor = System::Drawing::Color::Gray;
			this->labelWins->Location = System::Drawing::Point(342, 198);
			this->labelWins->Name = L"labelWins";
			this->labelWins->Size = System::Drawing::Size(37, 18);
			this->labelWins->TabIndex = 20;
			this->labelWins->Text = L"wins";
			this->labelWins->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelWeapon_name
			// 
			this->labelWeapon_name->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelWeapon_name->Location = System::Drawing::Point(6, 25);
			this->labelWeapon_name->Name = L"labelWeapon_name";
			this->labelWeapon_name->Size = System::Drawing::Size(134, 21);
			this->labelWeapon_name->TabIndex = 33;
			this->labelWeapon_name->Text = L"Weapon_Name";
			this->labelWeapon_name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelWeapon_damage
			// 
			this->labelWeapon_damage->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelWeapon_damage->ForeColor = System::Drawing::Color::Coral;
			this->labelWeapon_damage->Location = System::Drawing::Point(51, 56);
			this->labelWeapon_damage->Name = L"labelWeapon_damage";
			this->labelWeapon_damage->Size = System::Drawing::Size(48, 18);
			this->labelWeapon_damage->TabIndex = 34;
			this->labelWeapon_damage->Text = L"+dmg";
			this->labelWeapon_damage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->labelWeapon_name);
			this->groupBox1->Controls->Add(this->labelWeapon_damage);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(146, 89);
			this->groupBox1->TabIndex = 35;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Current weapon";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->labelEq_AP);
			this->groupBox2->Controls->Add(this->labelEq_HP);
			this->groupBox2->Controls->Add(this->labelEquipment_name);
			this->groupBox2->Controls->Add(this->labelEq_Dmg);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(12, 133);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(146, 89);
			this->groupBox2->TabIndex = 36;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Current equipment";
			// 
			// labelEq_AP
			// 
			this->labelEq_AP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelEq_AP->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelEq_AP->Location = System::Drawing::Point(100, 56);
			this->labelEq_AP->Name = L"labelEq_AP";
			this->labelEq_AP->Size = System::Drawing::Size(40, 18);
			this->labelEq_AP->TabIndex = 37;
			this->labelEq_AP->Text = L"+ap";
			this->labelEq_AP->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelEq_HP
			// 
			this->labelEq_HP->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelEq_HP->ForeColor = System::Drawing::Color::Red;
			this->labelEq_HP->Location = System::Drawing::Point(60, 56);
			this->labelEq_HP->Name = L"labelEq_HP";
			this->labelEq_HP->Size = System::Drawing::Size(40, 18);
			this->labelEq_HP->TabIndex = 37;
			this->labelEq_HP->Text = L"+hp";
			this->labelEq_HP->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labelEq_HP->Click += gcnew System::EventHandler(this, &LoadoutWindow::labelEq_HP_Click);
			// 
			// labelEquipment_name
			// 
			this->labelEquipment_name->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEquipment_name->Location = System::Drawing::Point(6, 25);
			this->labelEquipment_name->Name = L"labelEquipment_name";
			this->labelEquipment_name->Size = System::Drawing::Size(134, 21);
			this->labelEquipment_name->TabIndex = 33;
			this->labelEquipment_name->Text = L"Equipment_Name";
			this->labelEquipment_name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelEq_Dmg
			// 
			this->labelEq_Dmg->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelEq_Dmg->ForeColor = System::Drawing::Color::Coral;
			this->labelEq_Dmg->Location = System::Drawing::Point(6, 56);
			this->labelEq_Dmg->Name = L"labelEq_Dmg";
			this->labelEq_Dmg->Size = System::Drawing::Size(48, 18);
			this->labelEq_Dmg->TabIndex = 34;
			this->labelEq_Dmg->Text = L"+dmg";
			this->labelEq_Dmg->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(8, 500);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 22);
			this->label2->TabIndex = 37;
			this->label2->Text = L"Your money:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelMoney
			// 
			this->labelMoney->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelMoney->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMoney->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelMoney->Location = System::Drawing::Point(112, 504);
			this->labelMoney->Name = L"labelMoney";
			this->labelMoney->Size = System::Drawing::Size(66, 18);
			this->labelMoney->TabIndex = 38;
			this->labelMoney->Text = L"money";
			this->labelMoney->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::LemonChiffon;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 241);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(373, 22);
			this->label3->TabIndex = 39;
			this->label3->Text = L"SHOP";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::LemonChiffon;
			this->groupBox3->Location = System::Drawing::Point(12, 266);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(373, 230);
			this->groupBox3->TabIndex = 40;
			this->groupBox3->TabStop = false;
			// 
			// LoadoutWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(397, 534);
			this->ControlBox = false;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelMoney);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->labelWins);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelRank);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->labelPrecision);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->labelDMG);
			this->Controls->Add(this->labelEquipment);
			this->Controls->Add(this->labelAP);
			this->Controls->Add(this->labelWeapons);
			this->Controls->Add(this->labelHP);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->labelSURNAME);
			this->Controls->Add(this->labelNAME);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->labelDamage);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->labelArmor);
			this->Controls->Add(this->labelHealth);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->groupBox3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"LoadoutWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VA-BANK! Loadout";
			this->Load += gcnew System::EventHandler(this, &LoadoutWindow::LoadoutWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void labelEq_HP_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {

	if (this->main == 0)
		transferer->setEquipmentFinished();
	else
		transferer->setEquipmentFinishedInvCall();

	this->Close();
}
private: System::Void LoadoutWindow_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (transferer->getPlayerPTR()->getMoney() - shopWeapons[comboBox1->SelectedIndex].getPrice() < 0)
	{
		MessageBox::Show("Not enough money!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		current_guard->setWeapon(shopWeapons[comboBox1->SelectedIndex]);
		transferer->getPlayerPTR()->setMoney(transferer->getPlayerPTR()->getMoney() - shopWeapons[comboBox1->SelectedIndex].getPrice());

		std::string msg = "You have bought '" + shopWeapons[comboBox1->SelectedIndex].getName() + "' sucessfully!";
		MessageBox::Show(gcnew String(msg.c_str()), "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Visualizer();

		button2->Enabled = false;
	}
}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (transferer->getPlayerPTR()->getMoney() - shopEquipment[comboBox2->SelectedIndex].getPrice() < 0)
		{
			MessageBox::Show("Not enough money!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			current_guard->setStuff(shopEquipment[comboBox2->SelectedIndex]);
			transferer->getPlayerPTR()->setMoney(transferer->getPlayerPTR()->getMoney() - shopEquipment[comboBox2->SelectedIndex].getPrice());
			std::string msg = "You have bought '" + shopEquipment[comboBox2->SelectedIndex].getName() + "' sucessfully!";
			MessageBox::Show(gcnew String(msg.c_str()), "Success!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Visualizer();
			button3->Enabled = false;
		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = gcnew String(descriptionsWeapons[comboBox1->SelectedIndex].c_str());
	textBox1->Text += Environment::NewLine + "+" + shopWeapons[comboBox1->SelectedIndex].getDamage() + " damage";

	if (current_guard->getWeapon().getName() == shopWeapons[comboBox1->SelectedIndex].getName())
		button2->Enabled = false;
	else
		button2->Enabled = true;
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox2->Text = gcnew String(descriptionsEquipment[comboBox2->SelectedIndex].c_str());
	textBox2->Text += Environment::NewLine + "+" + shopEquipment[comboBox2->SelectedIndex].getBonusHP() + " HP";
	textBox2->Text += Environment::NewLine + "+" + shopEquipment[comboBox2->SelectedIndex].getBonusAP() + " AP";
	textBox2->Text += Environment::NewLine + "+" + shopEquipment[comboBox2->SelectedIndex].getBonusDamage() + " damage";

	if (current_guard->getStuff().getName() == shopEquipment[comboBox2->SelectedIndex].getName())
		button3->Enabled = false;
	else
		button3->Enabled = true;
}
};
}
