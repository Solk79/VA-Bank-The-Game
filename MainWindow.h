#pragma once
#include "Begin.h"
#include "Informer.h"

#include "SecurityInventory.h"
#include "LoadoutWindow.h"
#include "FightWindow.h"
#include "VictoryWindow.h"

typedef std::map<int, ::Security(*)> GuardsContainer;

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainWindow
	/// </summary>

	static Informer transferer; // основний передатчик ≥нформац≥њ м≥ж формами
	std::string recomText[10] =
	{ "This is your first enemy. He may be weak, but dont hesitate eliminating him. Place two guards for better result!",
	  "To win this round, you should upgrade some of your guards. Your enemies might be stronger than previous one, so be careful.",
	  "Alright, now add more guards to your bank, but dont spend all your money on it, because more enemies incoming!",
	  "Dont forget about upgrading weapons and equipment of your guards - this is essential!",
	  "Our forces reporting about strong mafia boss incoming - you should buy the best weapons for your guards!",
	  "Congratulations! You dealt with him! Now make sure that you have enough guardians on the field. Lock n' Load!",
	  "Secret information from our forces - ninja turtles (what???) incoming!",
	  "Dont forget that blocking damage is an important option. This is a key for good damage trading!",
	  "OK i actually dont know what to write here. Wish you good luck!",
	  "Final round! Spend all your money, they won't be saved after this fight. Show them no mercy!" };

	public ref class MainWindow : public System::Windows::Forms::Form
	{
	private:
	private: System::Windows::Forms::Label^ labelScore;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelRound;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelMoney;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ buttonGo;
	private: System::Windows::Forms::GroupBox^ groupBoxRI;
	private: System::Windows::Forms::Label^ labelTerrNum;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBoxRec;
	private: System::Windows::Forms::Label^ labelRecom;
	private: System::Windows::Forms::Button^ buttonHelp;
	private: System::Windows::Forms::Button^ buttonAbout;
	private: System::Windows::Forms::Label^ labelSalary;
	private: System::Windows::Forms::Label^ label6;

	private:
		bool stageFlag = false;
		void Swapper()
		{
			GuardsContainer* gcont_ptr = transferer.getPlayerPTR()->getGuardsContainerPTR();

			if (!stageFlag)
			{
				// перех≥д у UNDERGROUND
				buttonPlaceGuard1->Hide();
				buttonPlaceGuard2->Hide();
				buttonPlaceGuard3->Hide();
				buttonPlaceGuard4->Hide();

				pictureBoxUnderground->Show();
				pictureBoxFirstFloor->Hide();

				buttonPlaceGuard5->Show();
				buttonPlaceGuard6->Show();

				if (gcont_ptr->find(0) != gcont_ptr->end())
				{
					buttonGuard1->Hide();
				}
				if (gcont_ptr->find(1) != gcont_ptr->end())
				{
					buttonGuard2->Hide();
				}
				if (gcont_ptr->find(2) != gcont_ptr->end())
				{
					buttonGuard3->Hide();
				}
				if (gcont_ptr->find(3) != gcont_ptr->end())
				{
					buttonGuard4->Hide();
				}

				labelFloor->Text = "UNDERGROUND";
				buttonSwap->Text = "Swap to FIRST FLOOR";

				stageFlag = 1;
			}
			else
			{
				// перех≥д у FIRST FLOOR
				buttonPlaceGuard5->Hide();
				buttonPlaceGuard6->Hide();

				pictureBoxFirstFloor->Show();
				pictureBoxUnderground->Hide();

				buttonPlaceGuard1->Show();
				buttonPlaceGuard2->Show();
				buttonPlaceGuard3->Show();
				buttonPlaceGuard4->Show();

				if (gcont_ptr->find(4) != gcont_ptr->end())
				{
					buttonGuard5->Hide();
				}
				if (gcont_ptr->find(5) != gcont_ptr->end())
				{
					buttonGuard5->Hide();
				}

				labelFloor->Text = "FIRST FLOOR";
				buttonSwap->Text = "Swap to UNDERGROUND";

				stageFlag = 0;
			}
		}
	public:
		MainWindow()
		{
			Begin^ start = gcnew Begin(&transferer);
			start->Show();
			this->Enabled = false;

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBoxFirstFloor;
	private: System::Windows::Forms::GroupBox^ groupBoxStats;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBoxUnderground;
	private: System::Windows::Forms::Button^ buttonSwap;
	private: System::Windows::Forms::Label^ labelFloor;
	private: System::Windows::Forms::Button^ buttonPlaceGuard1;
	private: System::Windows::Forms::Button^ buttonPlaceGuard2;
	private: System::Windows::Forms::Button^ buttonPlaceGuard4;
	private: System::Windows::Forms::Button^ buttonPlaceGuard3;
	private: System::Windows::Forms::Button^ buttonPlaceGuard5;
	private: System::Windows::Forms::Button^ buttonPlaceGuard6;
	private: System::Windows::Forms::Button^ buttonGuard2;
	private: System::Windows::Forms::Button^ buttonGuard1;
	private: System::Windows::Forms::Button^ buttonGuard3;
	private: System::Windows::Forms::Button^ buttonGuard4;
	private: System::Windows::Forms::Button^ buttonGuard6;
	private: System::Windows::Forms::Button^ buttonGuard5;
	private: System::Windows::Forms::Timer^ timerRefresher;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->pictureBoxFirstFloor = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxStats = (gcnew System::Windows::Forms::GroupBox());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelRound = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelMoney = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonSwap = (gcnew System::Windows::Forms::Button());
			this->pictureBoxUnderground = (gcnew System::Windows::Forms::PictureBox());
			this->labelFloor = (gcnew System::Windows::Forms::Label());
			this->buttonPlaceGuard1 = (gcnew System::Windows::Forms::Button());
			this->buttonPlaceGuard2 = (gcnew System::Windows::Forms::Button());
			this->buttonPlaceGuard4 = (gcnew System::Windows::Forms::Button());
			this->buttonPlaceGuard3 = (gcnew System::Windows::Forms::Button());
			this->buttonPlaceGuard5 = (gcnew System::Windows::Forms::Button());
			this->buttonPlaceGuard6 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard2 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard1 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard3 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard4 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard6 = (gcnew System::Windows::Forms::Button());
			this->buttonGuard5 = (gcnew System::Windows::Forms::Button());
			this->timerRefresher = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->groupBoxRI = (gcnew System::Windows::Forms::GroupBox());
			this->labelSalary = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->labelTerrNum = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBoxRec = (gcnew System::Windows::Forms::GroupBox());
			this->labelRecom = (gcnew System::Windows::Forms::Label());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->buttonAbout = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFirstFloor))->BeginInit();
			this->groupBoxStats->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUnderground))->BeginInit();
			this->groupBoxRI->SuspendLayout();
			this->groupBoxRec->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxFirstFloor
			// 
			this->pictureBoxFirstFloor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBoxFirstFloor->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxFirstFloor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxFirstFloor.Image")));
			this->pictureBoxFirstFloor->Location = System::Drawing::Point(32, 76);
			this->pictureBoxFirstFloor->Name = L"pictureBoxFirstFloor";
			this->pictureBoxFirstFloor->Size = System::Drawing::Size(800, 600);
			this->pictureBoxFirstFloor->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxFirstFloor->TabIndex = 0;
			this->pictureBoxFirstFloor->TabStop = false;
			// 
			// groupBoxStats
			// 
			this->groupBoxStats->Controls->Add(this->labelScore);
			this->groupBoxStats->Controls->Add(this->label2);
			this->groupBoxStats->Controls->Add(this->labelRound);
			this->groupBoxStats->Controls->Add(this->label1);
			this->groupBoxStats->Controls->Add(this->labelMoney);
			this->groupBoxStats->Controls->Add(this->label5);
			this->groupBoxStats->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxStats->Location = System::Drawing::Point(838, 62);
			this->groupBoxStats->Name = L"groupBoxStats";
			this->groupBoxStats->Size = System::Drawing::Size(159, 134);
			this->groupBoxStats->TabIndex = 1;
			this->groupBoxStats->TabStop = false;
			this->groupBoxStats->Text = L"Statistics";
			// 
			// labelScore
			// 
			this->labelScore->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelScore->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelScore->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->labelScore->Location = System::Drawing::Point(73, 106);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(66, 18);
			this->labelScore->TabIndex = 46;
			this->labelScore->Text = L"score";
			this->labelScore->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 22);
			this->label2->TabIndex = 45;
			this->label2->Text = L"Score:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelRound
			// 
			this->labelRound->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelRound->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelRound->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelRound->Location = System::Drawing::Point(73, 77);
			this->labelRound->Name = L"labelRound";
			this->labelRound->Size = System::Drawing::Size(66, 18);
			this->labelRound->TabIndex = 44;
			this->labelRound->Text = L"round";
			this->labelRound->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(6, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 22);
			this->label1->TabIndex = 43;
			this->label1->Text = L"Round:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelMoney
			// 
			this->labelMoney->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelMoney->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMoney->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelMoney->Location = System::Drawing::Point(73, 27);
			this->labelMoney->Name = L"labelMoney";
			this->labelMoney->Size = System::Drawing::Size(66, 18);
			this->labelMoney->TabIndex = 42;
			this->labelMoney->Text = L"money";
			this->labelMoney->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(6, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 22);
			this->label5->TabIndex = 41;
			this->label5->Text = L"Money:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// buttonSwap
			// 
			this->buttonSwap->BackColor = System::Drawing::Color::Gold;
			this->buttonSwap->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSwap->ForeColor = System::Drawing::SystemColors::ControlText;
			this->buttonSwap->Location = System::Drawing::Point(126, 687);
			this->buttonSwap->Name = L"buttonSwap";
			this->buttonSwap->Size = System::Drawing::Size(619, 36);
			this->buttonSwap->TabIndex = 0;
			this->buttonSwap->Text = L"swap";
			this->buttonSwap->UseVisualStyleBackColor = false;
			this->buttonSwap->Click += gcnew System::EventHandler(this, &MainWindow::buttonSwap_Click);
			// 
			// pictureBoxUnderground
			// 
			this->pictureBoxUnderground->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxUnderground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxUnderground.Image")));
			this->pictureBoxUnderground->Location = System::Drawing::Point(32, 76);
			this->pictureBoxUnderground->Name = L"pictureBoxUnderground";
			this->pictureBoxUnderground->Size = System::Drawing::Size(800, 600);
			this->pictureBoxUnderground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxUnderground->TabIndex = 2;
			this->pictureBoxUnderground->TabStop = false;
			this->pictureBoxUnderground->Visible = false;
			// 
			// labelFloor
			// 
			this->labelFloor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelFloor->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFloor->Location = System::Drawing::Point(32, 33);
			this->labelFloor->Name = L"labelFloor";
			this->labelFloor->Size = System::Drawing::Size(800, 37);
			this->labelFloor->TabIndex = 3;
			this->labelFloor->Text = L"label";
			this->labelFloor->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelFloor->Click += gcnew System::EventHandler(this, &MainWindow::labelFloor_Click);
			// 
			// buttonPlaceGuard1
			// 
			this->buttonPlaceGuard1->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard1.Image")));
			this->buttonPlaceGuard1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard1->Location = System::Drawing::Point(82, 550);
			this->buttonPlaceGuard1->Name = L"buttonPlaceGuard1";
			this->buttonPlaceGuard1->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard1->TabIndex = 4;
			this->buttonPlaceGuard1->Text = L"Place Guard";
			this->buttonPlaceGuard1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard1->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard1->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard1_Click);
			// 
			// buttonPlaceGuard2
			// 
			this->buttonPlaceGuard2->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard2.Image")));
			this->buttonPlaceGuard2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard2->Location = System::Drawing::Point(557, 550);
			this->buttonPlaceGuard2->Name = L"buttonPlaceGuard2";
			this->buttonPlaceGuard2->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard2->TabIndex = 5;
			this->buttonPlaceGuard2->Text = L"Place Guard";
			this->buttonPlaceGuard2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard2->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard2->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard2_Click);
			// 
			// buttonPlaceGuard4
			// 
			this->buttonPlaceGuard4->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard4.Image")));
			this->buttonPlaceGuard4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard4->Location = System::Drawing::Point(276, 164);
			this->buttonPlaceGuard4->Name = L"buttonPlaceGuard4";
			this->buttonPlaceGuard4->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard4->TabIndex = 6;
			this->buttonPlaceGuard4->Text = L"Place Guard";
			this->buttonPlaceGuard4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard4->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard4->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard4_Click);
			// 
			// buttonPlaceGuard3
			// 
			this->buttonPlaceGuard3->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard3.Image")));
			this->buttonPlaceGuard3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard3->Location = System::Drawing::Point(560, 245);
			this->buttonPlaceGuard3->Name = L"buttonPlaceGuard3";
			this->buttonPlaceGuard3->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard3->TabIndex = 7;
			this->buttonPlaceGuard3->Text = L"Place Guard";
			this->buttonPlaceGuard3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard3->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard3->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard3_Click);
			// 
			// buttonPlaceGuard5
			// 
			this->buttonPlaceGuard5->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard5.Image")));
			this->buttonPlaceGuard5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard5->Location = System::Drawing::Point(545, 174);
			this->buttonPlaceGuard5->Name = L"buttonPlaceGuard5";
			this->buttonPlaceGuard5->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard5->TabIndex = 8;
			this->buttonPlaceGuard5->Text = L"Place Guard";
			this->buttonPlaceGuard5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard5->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard5->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard5_Click);
			// 
			// buttonPlaceGuard6
			// 
			this->buttonPlaceGuard6->BackColor = System::Drawing::SystemColors::Control;
			this->buttonPlaceGuard6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonPlaceGuard6.Image")));
			this->buttonPlaceGuard6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonPlaceGuard6->Location = System::Drawing::Point(545, 559);
			this->buttonPlaceGuard6->Name = L"buttonPlaceGuard6";
			this->buttonPlaceGuard6->Size = System::Drawing::Size(62, 35);
			this->buttonPlaceGuard6->TabIndex = 9;
			this->buttonPlaceGuard6->Text = L"Place Guard";
			this->buttonPlaceGuard6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonPlaceGuard6->UseVisualStyleBackColor = false;
			this->buttonPlaceGuard6->Click += gcnew System::EventHandler(this, &MainWindow::buttonPlaceGuard6_Click);
			// 
			// buttonGuard2
			// 
			this->buttonGuard2->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard2.Image")));
			this->buttonGuard2->Location = System::Drawing::Point(569, 535);
			this->buttonGuard2->Name = L"buttonGuard2";
			this->buttonGuard2->Size = System::Drawing::Size(42, 64);
			this->buttonGuard2->TabIndex = 10;
			this->buttonGuard2->UseVisualStyleBackColor = false;
			this->buttonGuard2->Visible = false;
			this->buttonGuard2->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard2_Click);
			// 
			// buttonGuard1
			// 
			this->buttonGuard1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard1.Image")));
			this->buttonGuard1->Location = System::Drawing::Point(91, 535);
			this->buttonGuard1->Name = L"buttonGuard1";
			this->buttonGuard1->Size = System::Drawing::Size(42, 64);
			this->buttonGuard1->TabIndex = 11;
			this->buttonGuard1->UseVisualStyleBackColor = false;
			this->buttonGuard1->Visible = false;
			this->buttonGuard1->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard1_Click);
			// 
			// buttonGuard3
			// 
			this->buttonGuard3->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard3.Image")));
			this->buttonGuard3->Location = System::Drawing::Point(569, 230);
			this->buttonGuard3->Name = L"buttonGuard3";
			this->buttonGuard3->Size = System::Drawing::Size(42, 64);
			this->buttonGuard3->TabIndex = 12;
			this->buttonGuard3->UseVisualStyleBackColor = false;
			this->buttonGuard3->Visible = false;
			this->buttonGuard3->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard3_Click);
			// 
			// buttonGuard4
			// 
			this->buttonGuard4->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard4.Image")));
			this->buttonGuard4->Location = System::Drawing::Point(287, 149);
			this->buttonGuard4->Name = L"buttonGuard4";
			this->buttonGuard4->Size = System::Drawing::Size(42, 64);
			this->buttonGuard4->TabIndex = 13;
			this->buttonGuard4->UseVisualStyleBackColor = false;
			this->buttonGuard4->Visible = false;
			this->buttonGuard4->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard4_Click);
			// 
			// buttonGuard6
			// 
			this->buttonGuard6->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard6.Image")));
			this->buttonGuard6->Location = System::Drawing::Point(556, 540);
			this->buttonGuard6->Name = L"buttonGuard6";
			this->buttonGuard6->Size = System::Drawing::Size(42, 64);
			this->buttonGuard6->TabIndex = 14;
			this->buttonGuard6->UseVisualStyleBackColor = false;
			this->buttonGuard6->Visible = false;
			this->buttonGuard6->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard6_Click);
			// 
			// buttonGuard5
			// 
			this->buttonGuard5->BackColor = System::Drawing::Color::LightSkyBlue;
			this->buttonGuard5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGuard5.Image")));
			this->buttonGuard5->Location = System::Drawing::Point(556, 161);
			this->buttonGuard5->Name = L"buttonGuard5";
			this->buttonGuard5->Size = System::Drawing::Size(42, 64);
			this->buttonGuard5->TabIndex = 15;
			this->buttonGuard5->UseVisualStyleBackColor = false;
			this->buttonGuard5->Visible = false;
			this->buttonGuard5->Click += gcnew System::EventHandler(this, &MainWindow::buttonGuard5_Click);
			// 
			// timerRefresher
			// 
			this->timerRefresher->Enabled = true;
			this->timerRefresher->Tick += gcnew System::EventHandler(this, &MainWindow::timerRefresher_Tick);
			// 
			// buttonGo
			// 
			this->buttonGo->BackColor = System::Drawing::Color::LimeGreen;
			this->buttonGo->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonGo->Location = System::Drawing::Point(838, 687);
			this->buttonGo->Name = L"buttonGo";
			this->buttonGo->Size = System::Drawing::Size(159, 36);
			this->buttonGo->TabIndex = 16;
			this->buttonGo->Text = L"START";
			this->buttonGo->UseVisualStyleBackColor = false;
			this->buttonGo->Click += gcnew System::EventHandler(this, &MainWindow::buttonGo_Click);
			// 
			// groupBoxRI
			// 
			this->groupBoxRI->Controls->Add(this->labelSalary);
			this->groupBoxRI->Controls->Add(this->label6);
			this->groupBoxRI->Controls->Add(this->labelTerrNum);
			this->groupBoxRI->Controls->Add(this->label3);
			this->groupBoxRI->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxRI->Location = System::Drawing::Point(838, 207);
			this->groupBoxRI->Name = L"groupBoxRI";
			this->groupBoxRI->Size = System::Drawing::Size(159, 142);
			this->groupBoxRI->TabIndex = 17;
			this->groupBoxRI->TabStop = false;
			this->groupBoxRI->Text = L"Round Info";
			// 
			// labelSalary
			// 
			this->labelSalary->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSalary->ForeColor = System::Drawing::Color::YellowGreen;
			this->labelSalary->Location = System::Drawing::Point(91, 95);
			this->labelSalary->Name = L"labelSalary";
			this->labelSalary->Size = System::Drawing::Size(63, 33);
			this->labelSalary->TabIndex = 50;
			this->labelSalary->Text = L"num";
			this->labelSalary->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(10, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 56);
			this->label6->TabIndex = 49;
			this->label6->Text = L"Salary for win:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelTerrNum
			// 
			this->labelTerrNum->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTerrNum->ForeColor = System::Drawing::Color::Red;
			this->labelTerrNum->Location = System::Drawing::Point(95, 37);
			this->labelTerrNum->Name = L"labelTerrNum";
			this->labelTerrNum->Size = System::Drawing::Size(58, 33);
			this->labelTerrNum->TabIndex = 48;
			this->labelTerrNum->Text = L"num";
			this->labelTerrNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelTerrNum->Click += gcnew System::EventHandler(this, &MainWindow::labelTerrNum_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 59);
			this->label3->TabIndex = 47;
			this->label3->Text = L"Amount of terrorists:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &MainWindow::label3_Click);
			// 
			// groupBoxRec
			// 
			this->groupBoxRec->Controls->Add(this->labelRecom);
			this->groupBoxRec->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxRec->Location = System::Drawing::Point(838, 363);
			this->groupBoxRec->Name = L"groupBoxRec";
			this->groupBoxRec->Size = System::Drawing::Size(159, 190);
			this->groupBoxRec->TabIndex = 49;
			this->groupBoxRec->TabStop = false;
			this->groupBoxRec->Text = L"Recommendations";
			// 
			// labelRecom
			// 
			this->labelRecom->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelRecom->Location = System::Drawing::Point(10, 31);
			this->labelRecom->Name = L"labelRecom";
			this->labelRecom->Size = System::Drawing::Size(143, 145);
			this->labelRecom->TabIndex = 47;
			this->labelRecom->Text = L"text";
			this->labelRecom->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelRecom->Click += gcnew System::EventHandler(this, &MainWindow::labelRecom_Click);
			// 
			// buttonHelp
			// 
			this->buttonHelp->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHelp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHelp.Image")));
			this->buttonHelp->Location = System::Drawing::Point(868, 568);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(95, 42);
			this->buttonHelp->TabIndex = 50;
			this->buttonHelp->Text = L"Help";
			this->buttonHelp->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &MainWindow::buttonHelp_Click);
			// 
			// buttonAbout
			// 
			this->buttonAbout->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAbout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAbout.Image")));
			this->buttonAbout->Location = System::Drawing::Point(838, 631);
			this->buttonAbout->Name = L"buttonAbout";
			this->buttonAbout->Size = System::Drawing::Size(159, 42);
			this->buttonAbout->TabIndex = 51;
			this->buttonAbout->Text = L"About author";
			this->buttonAbout->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonAbout->UseVisualStyleBackColor = true;
			this->buttonAbout->Click += gcnew System::EventHandler(this, &MainWindow::buttonAbout_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1004, 726);
			this->Controls->Add(this->buttonAbout);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->groupBoxRec);
			this->Controls->Add(this->groupBoxRI);
			this->Controls->Add(this->buttonGo);
			this->Controls->Add(this->labelFloor);
			this->Controls->Add(this->buttonSwap);
			this->Controls->Add(this->groupBoxStats);
			this->Controls->Add(this->buttonGuard4);
			this->Controls->Add(this->buttonGuard3);
			this->Controls->Add(this->buttonGuard1);
			this->Controls->Add(this->buttonGuard2);
			this->Controls->Add(this->buttonPlaceGuard4);
			this->Controls->Add(this->buttonPlaceGuard3);
			this->Controls->Add(this->buttonPlaceGuard1);
			this->Controls->Add(this->buttonPlaceGuard2);
			this->Controls->Add(this->pictureBoxFirstFloor);
			this->Controls->Add(this->buttonGuard5);
			this->Controls->Add(this->buttonGuard6);
			this->Controls->Add(this->buttonPlaceGuard5);
			this->Controls->Add(this->buttonPlaceGuard6);
			this->Controls->Add(this->pictureBoxUnderground);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VA-BANK! The Game";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFirstFloor))->EndInit();
			this->groupBoxStats->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUnderground))->EndInit();
			this->groupBoxRI->ResumeLayout(false);
			this->groupBoxRec->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {		
		buttonPlaceGuard5->Hide();
		buttonPlaceGuard6->Hide();

		labelFloor->Text = "FIRST FLOOR";
		buttonSwap->Text = "Swap to UNDERGROUND";
	}
	private: System::Void buttonSwap_Click(System::Object^ sender, System::EventArgs^ e) {
		Swapper();
	}

	private: System::Void buttonPlaceGuard1_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 0);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonPlaceGuard2_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 1);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonPlaceGuard3_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 2);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonPlaceGuard4_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 3);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonPlaceGuard5_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 4);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonPlaceGuard6_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityInventory^ window = gcnew SecurityInventory(&transferer, 5);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void timerRefresher_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (!stageFlag)
		{
			// first floor check
			for (int i = 0; i < 4; i++)
			{
				if (transferer.areGuardsPlaced(i))
				{
					switch (i)
					{
					case 0:
						buttonPlaceGuard1->Hide();
						buttonGuard1->Show();
						break;
					case 1:
						buttonPlaceGuard2->Hide();
						buttonGuard2->Show();
						break;
					case 2:
						buttonPlaceGuard3->Hide();
						buttonGuard3->Show();
						break;
					case 3:
						buttonPlaceGuard4->Hide();
						buttonGuard4->Show();
						break;
					}
				}
			}
		}
		else
		{
			// underground check
			for (int i = 4; i < 6; i++)
			{
				if (transferer.areGuardsPlaced(i))
				{
					switch (i)
					{
					case 4:
						buttonPlaceGuard5->Hide();
						buttonGuard5->Show();
						break;
					case 5:
						buttonPlaceGuard6->Hide();
						buttonGuard6->Show();
						break;
					}
				}
			}
		}
		// check на завершенн€ роботи з формою розм≥щенн€
		if (transferer.isFormFinished())
		{
			Player* pl_ptr = transferer.getPlayerPTR();

			labelMoney->Text = gcnew String((std::to_string((pl_ptr->getMoney()))).c_str());
			labelMoney->Text += gcnew String(("$"));
			this->Enabled = true;
			this->Select();
			transferer.setFormFinished();
		}
		// check на завершенн€ роботи форми прив≥танн€
		else if (transferer.isGreetingFinished())
		{
			Player* pl_ptr = transferer.getPlayerPTR();

			labelMoney->Text = gcnew String((std::to_string((pl_ptr->getMoney()))).c_str());
			labelMoney->Text += gcnew String(("$"));
			labelScore->Text = gcnew String((std::to_string((pl_ptr->getScore()))).c_str());
			labelRound->Text = gcnew String((std::to_string((pl_ptr->getCurrentRound()+1))).c_str());
			labelRecom->Text = gcnew String((recomText[pl_ptr->getCurrentRound()]).c_str());
			labelTerrNum->Text = gcnew String((std::to_string((ENEMIES_COUNT[pl_ptr->getCurrentRound()])).c_str()));
			labelSalary->Text = gcnew String((std::to_string((WIN_REWARD[pl_ptr->getCurrentRound()])).c_str()));
			labelSalary->Text += gcnew String(("$"));

			this->Enabled = true;
			this->Select();
			transferer.setGreetingFinished();
		}
		// check на завершенн€ роботи з формою обладнанн€ охоронц€
		else if (transferer.isEquipmentFinished())
		{
			Player* pl_ptr = transferer.getPlayerPTR();

			labelMoney->Text = gcnew String((std::to_string((pl_ptr->getMoney()))).c_str());
			labelMoney->Text += gcnew String(("$"));
			this->Enabled = true;
			this->Select();
			transferer.setEquipmentFinished();
		}
		// check на завершенн€ бою
		else if (transferer.isFightOver())
		{
			Player* pl_ptr = transferer.getPlayerPTR();
			// к≥нець гри €кщо вс≥х охоронц≥в вбито
			if (pl_ptr->getGuardsContainerPTR()->empty())
			{
				Application::Exit();
			}
			// к≥нець гри €кщо дойшов до останнього раунду
			else if (pl_ptr->getCurrentRound() == 9)
			{
				VictoryWindow^ window = gcnew VictoryWindow(transferer.getPlayerPTR());
				window->Show();
				this->Enabled = false;
				transferer.setFightOver();
			}
			// штатний режим
			else
			{
				// оновленн€ охоронц≥в
				for (int i = 0; i < 6; i++)
				{
					if (transferer.areGuardsPlaced(i))
					{
						// оновленн€ перемог охоронц≥в
						::Security* sec_ptr = pl_ptr->getGuardsContainerPTR()->find(i)->second;
						sec_ptr->setWins(sec_ptr->getWins() + 1);
						sec_ptr->rankUp();

						// за кожного охоронц€ що вижив - +100 додаткових очк≥в дл€ гравц€
						pl_ptr->setScore(pl_ptr->getScore() + 100);
					}
					else
					{
						// в≥зуальне в≥дображенн€ (корекц≥€ у зв'€зку ≥з гибеллю охоронц≥в)
						switch (i)
						{
						case 0:
							buttonPlaceGuard1->Show();
							buttonGuard1->Hide();
						case 1:
							buttonPlaceGuard2->Show();
							buttonGuard2->Hide();
						case 2:
							buttonPlaceGuard3->Show();
							buttonGuard3->Hide();
						case 3:
							buttonPlaceGuard4->Show();
							buttonGuard4->Hide();
						case 4:
							buttonPlaceGuard5->Show();
							buttonGuard5->Hide();
						case 5:
							buttonPlaceGuard6->Show();
							buttonGuard6->Hide();
						}
					}
				}
				// отриманн€ винагороди
				pl_ptr->setMoney(pl_ptr->getMoney() + WIN_REWARD[pl_ptr->getCurrentRound()]);

				labelMoney->Text = gcnew String((std::to_string((pl_ptr->getMoney()))).c_str());
				labelMoney->Text += gcnew String(("$"));
				labelScore->Text = gcnew String((std::to_string((pl_ptr->getScore()))).c_str());

				// оновленн€ раунду
				pl_ptr->setCurrentRound(pl_ptr->getCurrentRound() + 1);

				labelRound->Text = gcnew String((std::to_string((pl_ptr->getCurrentRound() + 1))).c_str());
				// оновленн€ запису к≥лькост≥ ворог≥в на наступному раунд≥
				labelTerrNum->Text = gcnew String((std::to_string((ENEMIES_COUNT[pl_ptr->getCurrentRound()])).c_str()));
				// оновленн€ запису нагороди на наступному раунд≥
				labelSalary->Text = gcnew String((std::to_string((WIN_REWARD[pl_ptr->getCurrentRound()])).c_str()));
				labelSalary->Text += gcnew String(("$"));
				// оновленн€ тексту рекомендац≥й
				labelRecom->Text = gcnew String((recomText[pl_ptr->getCurrentRound()]).c_str());

				this->Enabled = true;
				this->Select();
				transferer.setFightOver();

				// оновленн€ списку охоронц≥в у гравц€ (≥нвентар)
				pl_ptr->pushGuards();

				if (stageFlag)
					Swapper();
			}
		}
		/// check на перезапуск гри
		else if (transferer.isRestartGame())
		{
			buttonPlaceGuard1->Show();
			buttonGuard1->Hide();
			buttonPlaceGuard2->Show();
			buttonGuard2->Hide();
			buttonPlaceGuard3->Show();
			buttonGuard3->Hide();
			buttonPlaceGuard4->Show();
			buttonGuard4->Hide();
			buttonPlaceGuard5->Show();
			buttonGuard5->Hide();
			buttonPlaceGuard6->Show();
			buttonGuard6->Hide();


			transferer = Informer();
			this->Enabled = true;
			this->Select();

			Player* pl_ptr = transferer.getPlayerPTR();
			labelMoney->Text = gcnew String((std::to_string((pl_ptr->getMoney()))).c_str());
			labelMoney->Text += gcnew String(("$"));
			labelScore->Text = gcnew String((std::to_string((pl_ptr->getScore()))).c_str());
			labelRound->Text = gcnew String((std::to_string((pl_ptr->getCurrentRound() + 1))).c_str());
			labelRecom->Text = gcnew String((recomText[pl_ptr->getCurrentRound()]).c_str());
			labelTerrNum->Text = gcnew String((std::to_string((ENEMIES_COUNT[pl_ptr->getCurrentRound()])).c_str()));
			labelSalary->Text = gcnew String((std::to_string((WIN_REWARD[pl_ptr->getCurrentRound()])).c_str()));
			labelSalary->Text += gcnew String(("$"));

			if (stageFlag)
				Swapper();
		}
	}
	private: System::Void buttonGuard1_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 0, 0);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonGuard2_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 1, 0);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonGuard3_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 2, 0);
		window->Show();
		this->Enabled = false;
	}
	private: System::Void buttonGuard4_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 3, 0);
		window->Show();
		this->Enabled = false;
	}
private: System::Void buttonGuard5_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 4, 0);
	window->Show();
	this->Enabled = false;
}
private: System::Void buttonGuard6_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadoutWindow^ window = gcnew LoadoutWindow(&transferer, 5, 0);
	window->Show();
	this->Enabled = false;
}
private: System::Void labelTerrNum_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonGo_Click(System::Object^ sender, System::EventArgs^ e) {
	if (transferer.getPlayerPTR()->getGuardsContainerPTR()->empty())
		MessageBox::Show("You need to place at least one guard in bank!", "Woops...", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else
	{
		FightWindow^ window = gcnew FightWindow(&transferer);
		window->Show();
		this->Enabled = false;
	}
}
private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Place a guard by clicking on 'Place Guard' button, then choose or hire a security guard from new window and press 'Place!' button.\n\nPress on guard icon after placement to upgrade them.\n\nIf all your placed guards will die - you'll lose!\n\nWhen you're ready - press 'START!' button.",
		"Help", MessageBoxButtons::OK, MessageBoxIcon::Question);
}
private: System::Void buttonAbout_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Designed by V.Dieiev, DIIT student\nContact me on valentyn.dieiev@gmail.com", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void labelFloor_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void labelRecom_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
