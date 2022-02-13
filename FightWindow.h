#pragma once
#include <ctime>

#include "Informer.h"
#include "Terrorist.h"

const int ENEMIES_COUNT[] = { 1, 1, 2, 3, 4, 3, 4, 3, 4, 6 };							// константа: к≥льк≥сть ворог≥в на кожному раунд≥
const int WIN_REWARD[] = { 2100, 2800, 3500, 4100, 5700, 5300, 6000, 5100, 6200, 0};	// константа: нагорода за перемогу

namespace CourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ FightWindow
	/// </summary>

	public ref class FightWindow : public System::Windows::Forms::Form
	{
	private:
		Informer* transferer = nullptr;

		// терористи-вороги
		Terrorist* enemies;
		// терорист ворога, що зараз б'Їтьс€
		Terrorist* opponent;

		// охоронець гравц€, що зараз б'Їтьс€
		::Security* fighter;
		short fighterIndex;
		// початков≥ значенн€ охоронц€
		//		це необх≥дно, так €к у бою характеристики накладаютьс€ ≥з
		//		знар€дд€м та зброЇю, тому п≥сл€ бою ц≥ параметри не збер≥гаютьс€
		int nonbonusHP;
		int nonbonusAP;
		int nonbonusDMG;

		// прапори д≥й
		bool attackHead = 0;
		bool attackBody = 0;
		bool attackLegs = 0;

		bool protectHead = 0;
		bool protectBody = 0;
		bool protectLegs = 0;

		// л≥чильники к≥лькост≥ юн≥т≥в (гравц€ та ворога)
		short enemiesCount;	
	private: System::Windows::Forms::Button^ buttonRestart;
		   short guardsCount;
		  
		// внутр≥шньо-класовий в≥зуал≥затор
		void Visualizer(bool side, int unitNum)
		{
			// оновлювач дл€ гравц€
			if (side == 0)
			{
				fighter = this->transferer->getPlayerPTR()->getGuardsContainerPTR()->find(unitNum)->second;

				// збер≥ганн€ даних про початков≥ характеристики
				nonbonusHP = fighter->getHealthPoints();
				nonbonusAP = fighter->getArmorPoints();
				nonbonusDMG = fighter->getDamage();
				// врахуванн€ бонус≥в
				fighter->setHealthPoints(fighter->getHealthPoints() + fighter->getStuff().getBonusHP());
				fighter->setArmorPoints(fighter->getArmorPoints() + fighter->getStuff().getBonusAP());
				fighter->setDamage(fighter->getDamage() + fighter->getWeapon().getDamage() + fighter->getStuff().getBonusDamage());


				// лейбели
				labelNAME_SURNAME_S->Text = gcnew String((fighter->getName()).c_str());
				labelNAME_SURNAME_S->Text += gcnew String(" ");
				labelNAME_SURNAME_S->Text += gcnew String((fighter->getSurname()).c_str());
				labelHP_MAX_S->Text = gcnew String((std::to_string(fighter->getHealthPoints())).c_str());
				labelAP_MAX_S->Text = gcnew String((std::to_string(fighter->getArmorPoints())).c_str());
				labelHP_CUR_S->Text = labelHP_MAX_S->Text;
				labelAP_CUR_S->Text = labelAP_MAX_S->Text;
				labelDMG_S->Text = gcnew String((std::to_string(fighter->getDamage())).c_str());
			}
			// оновлювач дл€ ворога
			else
			{
				opponent = &this->enemies[unitNum];

				if (opponent->isBoss())
					labelBOSS->Show();
				else
					labelBOSS->Hide();

				labelNAME_SURNAME_T->Text = gcnew String((opponent->getName()).c_str());
				labelNAME_SURNAME_T->Text += gcnew String(" ");
				labelNAME_SURNAME_T->Text += gcnew String((opponent->getSurname()).c_str());

				labelHP_MAX_T->Text = gcnew String((std::to_string(opponent->getHealthPoints())).c_str());
				labelAP_MAX_T->Text = gcnew String((std::to_string(opponent->getArmorPoints())).c_str());
				labelHP_CUR_T->Text = labelHP_MAX_T->Text;
				labelAP_CUR_T->Text = labelAP_MAX_T->Text;

				labelDMG_R->Text = gcnew String((std::to_string(opponent->getDamage())).c_str());
			}
				
		}
		
		// внутр≥шньо-класовий логгер поЇдинку: вступ до бою
		void LogJoin(GameActor* actor)
		{
			textBoxLog->Text += Environment::NewLine;
			textBoxLog->Text += gcnew String(actor->getName().c_str());
			textBoxLog->Text += gcnew String(" ");
			textBoxLog->Text += gcnew String(actor->getSurname().c_str());
			textBoxLog->Text += gcnew String((" comes into fight!"));
		}

		// внутр≥шньо-класовий логгер поЇдинку: атака
		void LogAttack(bool side, int damageDone, bool critHit, bool blocked, short part_T)
		{
			if (side == 0)
			{
				textBoxLog->Text += Environment::NewLine;
				textBoxLog->Text += gcnew String(fighter->getName().c_str());
				textBoxLog->Text += gcnew String(" ");
				textBoxLog->Text += gcnew String(fighter->getSurname().c_str());
				textBoxLog->Text += gcnew String(" attacks");

				if (blocked)
					textBoxLog->Text += gcnew String(" BLOCKED");

				if (attackHead)
					textBoxLog->Text += gcnew String(" HEAD");
				else if (attackBody)
					textBoxLog->Text += gcnew String(" BODY");
				else
					textBoxLog->Text += gcnew String(" LEGS");

				textBoxLog->Text += gcnew String(" and deals ");
				if (critHit)
				{
					textBoxLog->Text += gcnew String("CRITICAL ");

					// критичний удар - +50 додаткових очк≥в гравцю
					transferer->getPlayerPTR()->setScore(transferer->getPlayerPTR()->getScore() + 50);
				}
				textBoxLog->Text += gcnew String((std::to_string(damageDone)).c_str());
				textBoxLog->Text += gcnew String(" damage!");
			}
			else
			{
				textBoxLog->Text += Environment::NewLine;
				textBoxLog->Text += gcnew String(opponent->getName().c_str());
				textBoxLog->Text += gcnew String(" ");
				textBoxLog->Text += gcnew String(opponent->getSurname().c_str());
				textBoxLog->Text += gcnew String(" attacks");
				
				if (blocked)
				{
					textBoxLog->Text += gcnew String(" BLOCKED");

					// заблокований удар - +25 додаткових очк≥в гравцю
					transferer->getPlayerPTR()->setScore(transferer->getPlayerPTR()->getScore() + 25);
				}

				if (part_T == 0)
					textBoxLog->Text += gcnew String(" HEAD");
				else if (part_T == 1)
					textBoxLog->Text += gcnew String(" BODY");
				else if (part_T == 2)
					textBoxLog->Text += gcnew String(" LEGS");

				textBoxLog->Text += gcnew String(" and deals ");
				if (critHit)
					textBoxLog->Text += gcnew String("CRITICAL ");

				textBoxLog->Text += gcnew String((std::to_string(damageDone)).c_str());
				textBoxLog->Text += gcnew String(" damage!");
			}
		}

		// внутр≥шньо-класовий логгер поЇдинку: захист
		void LogDefend(GameActor* actor, bool side, short part_T)
		{
			textBoxLog->Text += Environment::NewLine;
			textBoxLog->Text += gcnew String(actor->getName().c_str());
			textBoxLog->Text += gcnew String(" ");
			textBoxLog->Text += gcnew String(actor->getSurname().c_str());
			textBoxLog->Text += gcnew String(" protects his ");

			if (side == 0)
			{
				if (protectHead)
					textBoxLog->Text += gcnew String("HEAD!");
				else if (protectBody)
					textBoxLog->Text += gcnew String("BODY!");
				else
					textBoxLog->Text += gcnew String("LEGS!");
			}
			else
			{
				if (part_T == 0)
					textBoxLog->Text += gcnew String("HEAD!");
				else if (part_T == 1)
					textBoxLog->Text += gcnew String("BODY!");
				else if (part_T == 2)
					textBoxLog->Text += gcnew String("LEGS!");
			}
		}

		// внутр≥шньо-класовий логгер поЇдинку: вбивство
		void LogKill(bool side)
		{
			// дл€ сторони охоронц€ (чи в≥н вбив свого ворога)
			if (side == 0)
			{
				if (opponent->getHealthPoints() <= 0)
				{
					textBoxLog->Text += Environment::NewLine;
					textBoxLog->Text += gcnew String(opponent->getName().c_str());
					textBoxLog->Text += gcnew String(" ");
					textBoxLog->Text += gcnew String(opponent->getSurname().c_str());
					textBoxLog->Text += gcnew String(" dies...");

					// прибиранн€ напису BOSS
					if (opponent->isBoss())
						labelBOSS->Hide();
					
					// €кщо Ї ще вороги
					if (enemiesCount - 1 != 0)
					{
						enemiesCount--;
						labelTLeft->Text = gcnew String((std::to_string(enemiesCount)).c_str());

						Visualizer(1, enemiesCount - 1);
						LogJoin(opponent);
					}
					// €кщо цей ворог був останн≥м
					else
					{
						labelHP_CUR_T->Text = "0";
						// поверненн€ статистик без бонус≥в
						fighter->setHealthPoints(nonbonusHP);
						fighter->setArmorPoints(nonbonusAP);
						fighter->setDamage(nonbonusDMG);

						// пов≥домленн€ про к≥нець
						labelEnding->Text = "VICTORY!";
						labelEnding->ForeColor = Color::Green;
						labelEnding->Show();

						buttonRestart->Show();
						buttonClose->Show();
					}
				}
			}
			// дл€ сторони терориста (чи в≥н вбив свого ворога)
			else
			{
				if (fighter->getHealthPoints() <= 0)
				{
					textBoxLog->Text += Environment::NewLine;
					textBoxLog->Text += gcnew String(fighter->getName().c_str());
					textBoxLog->Text += gcnew String(" ");
					textBoxLog->Text += gcnew String(fighter->getSurname().c_str());
					textBoxLog->Text += gcnew String(" dies...");
					// €кщо Ї ще охоронц≥
					if (guardsCount - 1 != 0)
					{
						guardsCount--;
						transferer->getPlayerPTR()->setGuardsAmount(transferer->getPlayerPTR()->getGuardsAmount() - 1);
						labelGLeft->Text = gcnew String((std::to_string(guardsCount)).c_str());
						int n = this->fighterIndex;
						// видал€Їмо охоронц€ з контейнеру
						transferer->getPlayerPTR()->getGuardsContainerPTR()->erase(n);
						transferer->setGuardsPlaced(this->fighterIndex);
						// отриманн€ випадкового охоронц€ з розташованих
						int* randArray = new int[guardsCount];
						int randIndex = 0;
						for (int i = 0; i < 6; i++)
						{
							if (transferer->areGuardsPlaced(i))
							{
								randArray[randIndex] = i;
								randIndex++;
							}
						}
						this->fighterIndex = randArray[0 + rand() % guardsCount];
						delete[] randArray;

						n = this->fighterIndex;
						Visualizer(0, n);
						LogJoin(fighter);
					}
					// €кщо цей охоронець був останн≥м
					else
					{
						labelHP_CUR_S->Text = "0";
						int n = this->fighterIndex;
						transferer->getPlayerPTR()->getGuardsContainerPTR()->erase(n);
						// пов≥домленн€ про к≥нець
						labelEnding->Text = "DEFEAT!";
						labelEnding->ForeColor = Color::Red;
						labelEnding->Show();

						buttonRestart->Show();
						buttonRestart->Enabled = true;
						buttonClose->Show();
					}
				}
			}
		}

		// внутр≥шньо-класовий тр≥ггер бою
		void Trigger()
		{
			if ((attackHead || attackBody || attackLegs) && (protectHead || protectBody || protectLegs))
			{
				// основна бойова система

				// вимикаЇмо кнопки
				buttonAtHead->Enabled = false;
				buttonAtBody->Enabled = false;
				buttonAtLegs->Enabled = false;
				buttonDefHead->Enabled = false;
				buttonDefBody->Enabled = false;
				buttonDefLegs->Enabled = false;
				Sleep(300);
				// пов≥домл€Їмо про захист стор≥н
				// guard
				LogDefend(fighter, 0, -1);

				// terrorist
				short protectTerPart = 0 + rand() % 3;
				LogDefend(opponent, 1, protectTerPart);

				// атака стор≥н
				// guard
				bool isDefended = false;
				if (attackHead && protectTerPart == 0)
					isDefended = true;
				else if (attackBody && protectTerPart == 1)
					isDefended = true;
				else if (attackLegs && protectTerPart == 2)
					isDefended = true;

				bool critHit = false;
				bool blocked = false;

				// пов≥домл€Їмо про атаку стор≥н
				// guard
				LogAttack(0, fighter->fire(opponent, attackHead, isDefended, critHit, blocked), critHit, blocked, -1);
				labelHP_CUR_T->Text = gcnew String((std::to_string(opponent->getHealthPoints())).c_str());
				labelAP_CUR_T->Text = gcnew String((std::to_string(opponent->getArmorPoints())).c_str());

				// чи вижив терорист
				LogKill(0);
				if (opponent->getHealthPoints() > 0)
				{
					// атака стор≥н
					// terrorist
					short attackTerPart = 0 + rand() % 3;
					bool selectedPart = false;
					if (attackTerPart == 0 && protectHead)
						selectedPart = true;
					else if (attackTerPart == 1 && protectBody)
						selectedPart = true;
					else if (attackTerPart == 2 && protectLegs)
						selectedPart = true;

					bool isHead = false;
					if (attackTerPart == 0)
						isHead = true;

					critHit = false;
					blocked = false;
					// пов≥домл€Їмо про атаку стор≥н
					// terrorist
					LogAttack(1, opponent->fire(fighter, isHead, selectedPart, critHit, blocked), critHit, blocked, attackTerPart);
					labelHP_CUR_S->Text = gcnew String((std::to_string(fighter->getHealthPoints())).c_str());
					labelAP_CUR_S->Text = gcnew String((std::to_string(fighter->getArmorPoints())).c_str());

					// чи вижив охоронець
					LogKill(1);
					if (fighter->getHealthPoints() > 0)
					{
						buttonAtHead->Enabled = true;
						buttonAtBody->Enabled = true;
						buttonAtLegs->Enabled = true;
						buttonDefHead->Enabled = true;
						buttonDefBody->Enabled = true;
						buttonDefLegs->Enabled = true;

						attackHead = 0;
						attackBody = 0;
						attackLegs = 0;
						protectHead = 0;
						protectBody = 0;
						protectLegs = 0;
					}
				}
			}
		}

	public:
		FightWindow(Informer* transferer)
		{
			InitializeComponent();
			srand(time(0));
			this->transferer = transferer;
			this->guardsCount = 0;

			for (int i = 0; i < 6; i++)
			{
				if (this->transferer->areGuardsPlaced(i))
					guardsCount++;
			}
			
			// ≥н≥ц≥ал≥зац≥€ ворог≥в на основ≥ даного раунду
			switch (transferer->getPlayerPTR()->getCurrentRound())
			{
			case 0:
				enemiesCount = ENEMIES_COUNT[0];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Stealthy", "Andy", 150, 25, 17, 0);
			
				break;
			case 1:
				enemiesCount = ENEMIES_COUNT[1];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Heavy", "Joe", 50, 215, 20, 0);

				break;
			case 2:
				enemiesCount = ENEMIES_COUNT[2];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Mike", "Fernandes", 150, 130, 28, 0);
				enemies[1] = Terrorist("Killer", "Bee", 100, 180, 25, 0);

				break;
			case 3:
				enemiesCount = ENEMIES_COUNT[3];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Andrea", "Bokacchi", 250, 100, 20, 0);
				enemies[1] = Terrorist("Phil", "Cooker", 150, 100, 31, 0);
				enemies[2] = Terrorist("Bill", "Gates", 100, 200, 30, 0);

				break;
			case 4:
				enemiesCount = ENEMIES_COUNT[4];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Pedro", "Whiskey King", 300, 350, 35, 1);
				enemies[1] = Terrorist("Ralph", "Skworetsky", 150, 180, 29, 0);
				enemies[2] = Terrorist("Arctur", "Mengsk", 125, 150, 27, 0);
				enemies[3] = Terrorist("Gerard", "De'Partie", 250, 50, 28, 0);

				break;
			case 5:
				enemiesCount = ENEMIES_COUNT[5];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Iron", "Man", 25, 450, 37, 0);
				enemies[1] = Terrorist("Frederik", "Schulz", 75, 175, 40, 0);
				enemies[2] = Terrorist("Michael", "Capone", 100, 75, 45, 0);

				break;
			case 6:
				enemiesCount = ENEMIES_COUNT[6];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Leonardo", "The Robber", 300, 75, 35, 0);
				enemies[1] = Terrorist("Donatello", "The Robber", 300, 75, 35, 0);
				enemies[2] = Terrorist("Raphael", "The Robber", 300, 75, 35, 0);
				enemies[3] = Terrorist("Michelangelo", "The Robber", 300, 75, 35, 0);

				break;
			case 7:
				enemiesCount = ENEMIES_COUNT[7];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Brian", "Richards", 330, 50, 33, 0);
				enemies[1] = Terrorist("Evan", "Gobs", 250, 195, 44, 0);
				enemies[2] = Terrorist("Tony", "Montana", 200, 225, 37, 0);

				break;
			case 8:
				enemiesCount = ENEMIES_COUNT[8];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("Demitry", "The Drunk", 200, 160, 33, 0);
				enemies[1] = Terrorist("Demitry", "The Black", 250, 190, 29, 0);
				enemies[2] = Terrorist("Maximus", "Prime", 175, 175, 34, 0);
				enemies[3] = Terrorist("Valencius", "Kilivnius", 300, 100, 31, 0);

				break;
			case 9:
				enemiesCount = ENEMIES_COUNT[9];
				this->enemies = new Terrorist[enemiesCount];
				enemies[0] = Terrorist("OK! No", "jokes here!", 750, 750, 50, 1);
				enemies[1] = Terrorist("Write me on", "my gmail", 100, 50, 45, 0);
				enemies[2] = Terrorist("Let me know", "your opinion", 100, 50, 45, 0);
				enemies[3] = Terrorist("I hope you", "liked this game", 100, 50, 45, 0);
				enemies[4] = Terrorist("Im glad that", "you made it", 100, 50, 45, 0);
				enemies[5] = Terrorist("Greetings,", "player!", 100, 50, 45, 0);

				break;
			}

			// вив≥д на лейбли к≥лькост≥ юн≥т≥в
			labelGLeft->Text = gcnew String((std::to_string(guardsCount)).c_str());
			labelTLeft->Text = gcnew String((std::to_string(enemiesCount)).c_str());

			// отриманн€ випадкового охоронц€ з розташованих
			int* randArray = new int [guardsCount];
			int randIndex = 0;
			// отриманн€ ≥ндекс≥в охоронц≥в
			for (int i = 0; i < 6; i++)
			{
				if (transferer->areGuardsPlaced(i))
				{
					randArray[randIndex] = i;
					randIndex++;
				}
			}
			this->fighterIndex = randArray[0 + rand() % guardsCount];
			delete[] randArray;

			// вставка на форму охоронц€ та терориста
			Visualizer(0, fighterIndex);
			Visualizer(1, enemiesCount-1);

			// вв≥д у лог ≥нформац≥њ про б≥й
			textBoxLog->Text = gcnew String("A duel between ");
			textBoxLog->Text += gcnew String(fighter->getName().c_str());
			textBoxLog->Text += gcnew String(" ");
			textBoxLog->Text += gcnew String(fighter->getSurname().c_str());
			textBoxLog->Text += gcnew String(" and ");
			textBoxLog->Text += gcnew String(opponent->getName().c_str());
			textBoxLog->Text += gcnew String(" ");
			textBoxLog->Text += gcnew String(opponent->getSurname().c_str());
			textBoxLog->Text += gcnew String(" has begun!");

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FightWindow()
		{
			delete[] enemies;
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelEnding;
	private: System::Windows::Forms::Label^ labelBOSS;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ textBoxLog;
	private: System::Windows::Forms::Button^ buttonAtHead;
	private: System::Windows::Forms::Button^ buttonAtBody;
	private: System::Windows::Forms::Button^ buttonAtLegs;
	private: System::Windows::Forms::Label^ labelNAME_SURNAME_S;
	private: System::Windows::Forms::Label^ labelNAME_SURNAME_T;

	private: System::Windows::Forms::Label^ labelHealthS;
	private: System::Windows::Forms::Label^ labelHP_CUR_S;
	private: System::Windows::Forms::Label^ labelHP_MAX_S;
	private: System::Windows::Forms::Label^ labelSlashS;
	private: System::Windows::Forms::Label^ labelSlashR;
	private: System::Windows::Forms::Label^ labelHP_MAX_T;

	private: System::Windows::Forms::Label^ labelHP_CUR_T;

	private: System::Windows::Forms::Label^ labelHealthR;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelAP_MAX_S;

	private: System::Windows::Forms::Label^ labelAP_CUR_S;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ labelAP_MAX_T;

	private: System::Windows::Forms::Label^ labelAP_CUR_T;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBoxFist1;
	private: System::Windows::Forms::Label^ labelDMG_S;
	private: System::Windows::Forms::Label^ labelDMG_R;
	private: System::Windows::Forms::PictureBox^ pictureBoxFist2;
	private: System::Windows::Forms::Button^ buttonDefHead;
	private: System::Windows::Forms::Button^ buttonDefBody;
	private: System::Windows::Forms::Button^ buttonDefLegs;
	private: System::Windows::Forms::Button^ buttonHelp;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ labelGLeft;
	private: System::Windows::Forms::Label^ labelTLeft;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FightWindow::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBoxLog = (gcnew System::Windows::Forms::TextBox());
			this->buttonAtHead = (gcnew System::Windows::Forms::Button());
			this->buttonAtBody = (gcnew System::Windows::Forms::Button());
			this->buttonAtLegs = (gcnew System::Windows::Forms::Button());
			this->labelNAME_SURNAME_S = (gcnew System::Windows::Forms::Label());
			this->labelNAME_SURNAME_T = (gcnew System::Windows::Forms::Label());
			this->labelHealthS = (gcnew System::Windows::Forms::Label());
			this->labelHP_CUR_S = (gcnew System::Windows::Forms::Label());
			this->labelHP_MAX_S = (gcnew System::Windows::Forms::Label());
			this->labelSlashS = (gcnew System::Windows::Forms::Label());
			this->labelSlashR = (gcnew System::Windows::Forms::Label());
			this->labelHP_MAX_T = (gcnew System::Windows::Forms::Label());
			this->labelHP_CUR_T = (gcnew System::Windows::Forms::Label());
			this->labelHealthR = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelAP_MAX_S = (gcnew System::Windows::Forms::Label());
			this->labelAP_CUR_S = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelAP_MAX_T = (gcnew System::Windows::Forms::Label());
			this->labelAP_CUR_T = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxFist1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelDMG_S = (gcnew System::Windows::Forms::Label());
			this->labelDMG_R = (gcnew System::Windows::Forms::Label());
			this->pictureBoxFist2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonDefHead = (gcnew System::Windows::Forms::Button());
			this->buttonDefBody = (gcnew System::Windows::Forms::Button());
			this->buttonDefLegs = (gcnew System::Windows::Forms::Button());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->labelGLeft = (gcnew System::Windows::Forms::Label());
			this->labelTLeft = (gcnew System::Windows::Forms::Label());
			this->labelEnding = (gcnew System::Windows::Forms::Label());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->labelBOSS = (gcnew System::Windows::Forms::Label());
			this->buttonRestart = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFist1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFist2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(21, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(235, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::IndianRed;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(506, 40);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(235, 270);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// textBoxLog
			// 
			this->textBoxLog->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxLog->Location = System::Drawing::Point(21, 362);
			this->textBoxLog->Multiline = true;
			this->textBoxLog->Name = L"textBoxLog";
			this->textBoxLog->ReadOnly = true;
			this->textBoxLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxLog->Size = System::Drawing::Size(720, 103);
			this->textBoxLog->TabIndex = 2;
			this->textBoxLog->TextChanged += gcnew System::EventHandler(this, &FightWindow::textBoxLog_TextChanged);
			// 
			// buttonAtHead
			// 
			this->buttonAtHead->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAtHead->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAtHead.Image")));
			this->buttonAtHead->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonAtHead->Location = System::Drawing::Point(301, 99);
			this->buttonAtHead->Name = L"buttonAtHead";
			this->buttonAtHead->Size = System::Drawing::Size(113, 43);
			this->buttonAtHead->TabIndex = 3;
			this->buttonAtHead->Text = L"Attack Head";
			this->buttonAtHead->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->buttonAtHead->UseVisualStyleBackColor = true;
			this->buttonAtHead->Click += gcnew System::EventHandler(this, &FightWindow::buttonAtHead_Click);
			// 
			// buttonAtBody
			// 
			this->buttonAtBody->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAtBody->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAtBody.Image")));
			this->buttonAtBody->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonAtBody->Location = System::Drawing::Point(301, 162);
			this->buttonAtBody->Name = L"buttonAtBody";
			this->buttonAtBody->Size = System::Drawing::Size(113, 43);
			this->buttonAtBody->TabIndex = 4;
			this->buttonAtBody->Text = L"Attack Body";
			this->buttonAtBody->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->buttonAtBody->UseVisualStyleBackColor = true;
			this->buttonAtBody->Click += gcnew System::EventHandler(this, &FightWindow::buttonAtBody_Click);
			// 
			// buttonAtLegs
			// 
			this->buttonAtLegs->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonAtLegs->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAtLegs.Image")));
			this->buttonAtLegs->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonAtLegs->Location = System::Drawing::Point(301, 226);
			this->buttonAtLegs->Name = L"buttonAtLegs";
			this->buttonAtLegs->Size = System::Drawing::Size(113, 43);
			this->buttonAtLegs->TabIndex = 5;
			this->buttonAtLegs->Text = L"Attack Legs";
			this->buttonAtLegs->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->buttonAtLegs->UseVisualStyleBackColor = true;
			this->buttonAtLegs->Click += gcnew System::EventHandler(this, &FightWindow::buttonAtLegs_Click);
			// 
			// labelNAME_SURNAME_S
			// 
			this->labelNAME_SURNAME_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNAME_SURNAME_S->Location = System::Drawing::Point(21, 18);
			this->labelNAME_SURNAME_S->Name = L"labelNAME_SURNAME_S";
			this->labelNAME_SURNAME_S->Size = System::Drawing::Size(235, 19);
			this->labelNAME_SURNAME_S->TabIndex = 7;
			this->labelNAME_SURNAME_S->Text = L"NAME_SURNAME_S";
			this->labelNAME_SURNAME_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelNAME_SURNAME_T
			// 
			this->labelNAME_SURNAME_T->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelNAME_SURNAME_T->Location = System::Drawing::Point(506, 18);
			this->labelNAME_SURNAME_T->Name = L"labelNAME_SURNAME_T";
			this->labelNAME_SURNAME_T->Size = System::Drawing::Size(235, 19);
			this->labelNAME_SURNAME_T->TabIndex = 8;
			this->labelNAME_SURNAME_T->Text = L"NAME_SURNAME_T";
			this->labelNAME_SURNAME_T->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHealthS
			// 
			this->labelHealthS->AutoSize = true;
			this->labelHealthS->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHealthS->Location = System::Drawing::Point(22, 316);
			this->labelHealthS->Name = L"labelHealthS";
			this->labelHealthS->Size = System::Drawing::Size(49, 18);
			this->labelHealthS->TabIndex = 9;
			this->labelHealthS->Text = L"Health:";
			// 
			// labelHP_CUR_S
			// 
			this->labelHP_CUR_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP_CUR_S->ForeColor = System::Drawing::Color::Red;
			this->labelHP_CUR_S->Location = System::Drawing::Point(77, 316);
			this->labelHP_CUR_S->Name = L"labelHP_CUR_S";
			this->labelHP_CUR_S->Size = System::Drawing::Size(40, 18);
			this->labelHP_CUR_S->TabIndex = 11;
			this->labelHP_CUR_S->Text = L"hp";
			this->labelHP_CUR_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHP_MAX_S
			// 
			this->labelHP_MAX_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP_MAX_S->ForeColor = System::Drawing::Color::Red;
			this->labelHP_MAX_S->Location = System::Drawing::Point(133, 316);
			this->labelHP_MAX_S->Name = L"labelHP_MAX_S";
			this->labelHP_MAX_S->Size = System::Drawing::Size(40, 18);
			this->labelHP_MAX_S->TabIndex = 12;
			this->labelHP_MAX_S->Text = L"hp";
			this->labelHP_MAX_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelSlashS
			// 
			this->labelSlashS->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSlashS->ForeColor = System::Drawing::Color::Red;
			this->labelSlashS->Location = System::Drawing::Point(119, 316);
			this->labelSlashS->Name = L"labelSlashS";
			this->labelSlashS->Size = System::Drawing::Size(10, 18);
			this->labelSlashS->TabIndex = 13;
			this->labelSlashS->Text = L"/";
			this->labelSlashS->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelSlashR
			// 
			this->labelSlashR->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSlashR->ForeColor = System::Drawing::Color::Red;
			this->labelSlashR->Location = System::Drawing::Point(604, 316);
			this->labelSlashR->Name = L"labelSlashR";
			this->labelSlashR->Size = System::Drawing::Size(10, 18);
			this->labelSlashR->TabIndex = 17;
			this->labelSlashR->Text = L"/";
			this->labelSlashR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHP_MAX_T
			// 
			this->labelHP_MAX_T->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP_MAX_T->ForeColor = System::Drawing::Color::Red;
			this->labelHP_MAX_T->Location = System::Drawing::Point(618, 316);
			this->labelHP_MAX_T->Name = L"labelHP_MAX_T";
			this->labelHP_MAX_T->Size = System::Drawing::Size(40, 18);
			this->labelHP_MAX_T->TabIndex = 16;
			this->labelHP_MAX_T->Text = L"hp";
			this->labelHP_MAX_T->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHP_CUR_T
			// 
			this->labelHP_CUR_T->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHP_CUR_T->ForeColor = System::Drawing::Color::Red;
			this->labelHP_CUR_T->Location = System::Drawing::Point(562, 316);
			this->labelHP_CUR_T->Name = L"labelHP_CUR_T";
			this->labelHP_CUR_T->Size = System::Drawing::Size(40, 18);
			this->labelHP_CUR_T->TabIndex = 15;
			this->labelHP_CUR_T->Text = L"hp";
			this->labelHP_CUR_T->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelHealthR
			// 
			this->labelHealthR->AutoSize = true;
			this->labelHealthR->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelHealthR->Location = System::Drawing::Point(507, 316);
			this->labelHealthR->Name = L"labelHealthR";
			this->labelHealthR->Size = System::Drawing::Size(49, 18);
			this->labelHealthR->TabIndex = 14;
			this->labelHealthR->Text = L"Health:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(22, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 18);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Armor:";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label1->Location = System::Drawing::Point(119, 334);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(10, 18);
			this->label1->TabIndex = 21;
			this->label1->Text = L"/";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAP_MAX_S
			// 
			this->labelAP_MAX_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP_MAX_S->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP_MAX_S->Location = System::Drawing::Point(133, 334);
			this->labelAP_MAX_S->Name = L"labelAP_MAX_S";
			this->labelAP_MAX_S->Size = System::Drawing::Size(40, 18);
			this->labelAP_MAX_S->TabIndex = 20;
			this->labelAP_MAX_S->Text = L"ap";
			this->labelAP_MAX_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAP_CUR_S
			// 
			this->labelAP_CUR_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP_CUR_S->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP_CUR_S->Location = System::Drawing::Point(77, 334);
			this->labelAP_CUR_S->Name = L"labelAP_CUR_S";
			this->labelAP_CUR_S->Size = System::Drawing::Size(40, 18);
			this->labelAP_CUR_S->TabIndex = 19;
			this->labelAP_CUR_S->Text = L"ap";
			this->labelAP_CUR_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DodgerBlue;
			this->label5->Location = System::Drawing::Point(604, 334);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(10, 18);
			this->label5->TabIndex = 25;
			this->label5->Text = L"/";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAP_MAX_T
			// 
			this->labelAP_MAX_T->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP_MAX_T->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP_MAX_T->Location = System::Drawing::Point(618, 334);
			this->labelAP_MAX_T->Name = L"labelAP_MAX_T";
			this->labelAP_MAX_T->Size = System::Drawing::Size(40, 18);
			this->labelAP_MAX_T->TabIndex = 24;
			this->labelAP_MAX_T->Text = L"ap";
			this->labelAP_MAX_T->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelAP_CUR_T
			// 
			this->labelAP_CUR_T->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelAP_CUR_T->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelAP_CUR_T->Location = System::Drawing::Point(562, 334);
			this->labelAP_CUR_T->Name = L"labelAP_CUR_T";
			this->labelAP_CUR_T->Size = System::Drawing::Size(40, 18);
			this->labelAP_CUR_T->TabIndex = 23;
			this->labelAP_CUR_T->Text = L"ap";
			this->labelAP_CUR_T->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(507, 334);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(47, 18);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Armor:";
			// 
			// pictureBoxFist1
			// 
			this->pictureBoxFist1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxFist1.Image")));
			this->pictureBoxFist1->Location = System::Drawing::Point(178, 316);
			this->pictureBoxFist1->Name = L"pictureBoxFist1";
			this->pictureBoxFist1->Size = System::Drawing::Size(39, 36);
			this->pictureBoxFist1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxFist1->TabIndex = 26;
			this->pictureBoxFist1->TabStop = false;
			// 
			// labelDMG_S
			// 
			this->labelDMG_S->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDMG_S->ForeColor = System::Drawing::Color::Coral;
			this->labelDMG_S->Location = System::Drawing::Point(217, 316);
			this->labelDMG_S->Name = L"labelDMG_S";
			this->labelDMG_S->Size = System::Drawing::Size(39, 36);
			this->labelDMG_S->TabIndex = 27;
			this->labelDMG_S->Text = L"dmg";
			this->labelDMG_S->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDMG_R
			// 
			this->labelDMG_R->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed Extra Bold", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelDMG_R->ForeColor = System::Drawing::Color::Coral;
			this->labelDMG_R->Location = System::Drawing::Point(703, 316);
			this->labelDMG_R->Name = L"labelDMG_R";
			this->labelDMG_R->Size = System::Drawing::Size(39, 36);
			this->labelDMG_R->TabIndex = 29;
			this->labelDMG_R->Text = L"dmg";
			this->labelDMG_R->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBoxFist2
			// 
			this->pictureBoxFist2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxFist2.Image")));
			this->pictureBoxFist2->Location = System::Drawing::Point(664, 316);
			this->pictureBoxFist2->Name = L"pictureBoxFist2";
			this->pictureBoxFist2->Size = System::Drawing::Size(39, 36);
			this->pictureBoxFist2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxFist2->TabIndex = 28;
			this->pictureBoxFist2->TabStop = false;
			// 
			// buttonDefHead
			// 
			this->buttonDefHead->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDefHead.Image")));
			this->buttonDefHead->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonDefHead->Location = System::Drawing::Point(420, 99);
			this->buttonDefHead->Name = L"buttonDefHead";
			this->buttonDefHead->Size = System::Drawing::Size(41, 43);
			this->buttonDefHead->TabIndex = 30;
			this->buttonDefHead->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->buttonDefHead->UseVisualStyleBackColor = true;
			this->buttonDefHead->Click += gcnew System::EventHandler(this, &FightWindow::buttonDefHead_Click);
			// 
			// buttonDefBody
			// 
			this->buttonDefBody->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDefBody.Image")));
			this->buttonDefBody->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonDefBody->Location = System::Drawing::Point(420, 162);
			this->buttonDefBody->Name = L"buttonDefBody";
			this->buttonDefBody->Size = System::Drawing::Size(41, 43);
			this->buttonDefBody->TabIndex = 31;
			this->buttonDefBody->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->buttonDefBody->UseVisualStyleBackColor = true;
			this->buttonDefBody->Click += gcnew System::EventHandler(this, &FightWindow::buttonDefBody_Click);
			// 
			// buttonDefLegs
			// 
			this->buttonDefLegs->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDefLegs.Image")));
			this->buttonDefLegs->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->buttonDefLegs->Location = System::Drawing::Point(420, 226);
			this->buttonDefLegs->Name = L"buttonDefLegs";
			this->buttonDefLegs->Size = System::Drawing::Size(41, 43);
			this->buttonDefLegs->TabIndex = 32;
			this->buttonDefLegs->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->buttonDefLegs->UseVisualStyleBackColor = true;
			this->buttonDefLegs->Click += gcnew System::EventHandler(this, &FightWindow::buttonDefLegs_Click);
			// 
			// buttonHelp
			// 
			this->buttonHelp->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHelp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHelp.Image")));
			this->buttonHelp->Location = System::Drawing::Point(333, 29);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(93, 39);
			this->buttonHelp->TabIndex = 51;
			this->buttonHelp->Text = L"Help";
			this->buttonHelp->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &FightWindow::buttonHelp_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::Control;
			this->label9->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(262, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 40);
			this->label9->TabIndex = 52;
			this->label9->Text = L"Guards left";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::SystemColors::Control;
			this->label10->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(428, 8);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(75, 38);
			this->label10->TabIndex = 53;
			this->label10->Text = L"Terrorists left";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelGLeft
			// 
			this->labelGLeft->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelGLeft->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGLeft->ForeColor = System::Drawing::Color::DodgerBlue;
			this->labelGLeft->Location = System::Drawing::Point(262, 49);
			this->labelGLeft->Name = L"labelGLeft";
			this->labelGLeft->Size = System::Drawing::Size(66, 18);
			this->labelGLeft->TabIndex = 54;
			this->labelGLeft->Text = L"num";
			this->labelGLeft->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelTLeft
			// 
			this->labelTLeft->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelTLeft->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTLeft->ForeColor = System::Drawing::Color::Red;
			this->labelTLeft->Location = System::Drawing::Point(432, 49);
			this->labelTLeft->Name = L"labelTLeft";
			this->labelTLeft->Size = System::Drawing::Size(66, 18);
			this->labelTLeft->TabIndex = 55;
			this->labelTLeft->Text = L"num";
			this->labelTLeft->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelEnding
			// 
			this->labelEnding->BackColor = System::Drawing::Color::LemonChiffon;
			this->labelEnding->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEnding->Location = System::Drawing::Point(301, 284);
			this->labelEnding->Name = L"labelEnding";
			this->labelEnding->Size = System::Drawing::Size(160, 24);
			this->labelEnding->TabIndex = 56;
			this->labelEnding->Text = L"text";
			this->labelEnding->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelEnding->Visible = false;
			// 
			// buttonClose
			// 
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClose->Location = System::Drawing::Point(301, 316);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(75, 33);
			this->buttonClose->TabIndex = 57;
			this->buttonClose->Text = L"Close";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Visible = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &FightWindow::buttonClose_Click);
			// 
			// labelBOSS
			// 
			this->labelBOSS->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBOSS->ForeColor = System::Drawing::Color::Red;
			this->labelBOSS->Location = System::Drawing::Point(353, 73);
			this->labelBOSS->Name = L"labelBOSS";
			this->labelBOSS->Size = System::Drawing::Size(61, 19);
			this->labelBOSS->TabIndex = 58;
			this->labelBOSS->Text = L"BOSS!";
			this->labelBOSS->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelBOSS->Visible = false;
			// 
			// buttonRestart
			// 
			this->buttonRestart->Enabled = false;
			this->buttonRestart->Font = (gcnew System::Drawing::Font(L"Tw Cen MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRestart->Location = System::Drawing::Point(386, 316);
			this->buttonRestart->Name = L"buttonRestart";
			this->buttonRestart->Size = System::Drawing::Size(75, 33);
			this->buttonRestart->TabIndex = 59;
			this->buttonRestart->Text = L"Restart";
			this->buttonRestart->UseVisualStyleBackColor = true;
			this->buttonRestart->Visible = false;
			this->buttonRestart->Click += gcnew System::EventHandler(this, &FightWindow::buttonRestart_Click);
			// 
			// FightWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(762, 477);
			this->ControlBox = false;
			this->Controls->Add(this->buttonRestart);
			this->Controls->Add(this->labelBOSS);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->labelEnding);
			this->Controls->Add(this->labelTLeft);
			this->Controls->Add(this->labelGLeft);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->buttonDefLegs);
			this->Controls->Add(this->buttonDefBody);
			this->Controls->Add(this->buttonDefHead);
			this->Controls->Add(this->labelDMG_R);
			this->Controls->Add(this->pictureBoxFist2);
			this->Controls->Add(this->labelDMG_S);
			this->Controls->Add(this->pictureBoxFist1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->labelAP_MAX_T);
			this->Controls->Add(this->labelAP_CUR_T);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelAP_MAX_S);
			this->Controls->Add(this->labelAP_CUR_S);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelSlashR);
			this->Controls->Add(this->labelHP_MAX_T);
			this->Controls->Add(this->labelHP_CUR_T);
			this->Controls->Add(this->labelHealthR);
			this->Controls->Add(this->labelSlashS);
			this->Controls->Add(this->labelHP_MAX_S);
			this->Controls->Add(this->labelHP_CUR_S);
			this->Controls->Add(this->labelHealthS);
			this->Controls->Add(this->labelNAME_SURNAME_T);
			this->Controls->Add(this->labelNAME_SURNAME_S);
			this->Controls->Add(this->buttonAtLegs);
			this->Controls->Add(this->buttonAtBody);
			this->Controls->Add(this->buttonAtHead);
			this->Controls->Add(this->textBoxLog);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"FightWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VA-BANK! Fight";
			this->Load += gcnew System::EventHandler(this, &FightWindow::FightWindow_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFist1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxFist2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAtHead_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->attackBody == 1)
		{
			this->attackBody = 0;
			buttonAtBody->Enabled = true;
		}
		else if (this->attackLegs == 1)
		{
			this->attackLegs = 0;
			buttonAtLegs->Enabled = true;
		}

		this->attackHead = 1;
		buttonAtHead->Enabled = false;
		Trigger();
	}
private: System::Void buttonAtBody_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->attackHead == 1)
	{
		this->attackHead = 0;
		buttonAtHead->Enabled = true;
	}
	else if (this->attackLegs == 1)
	{
		this->attackLegs = 0;
		buttonAtLegs->Enabled = true;
	}

	this->attackBody = 1;
	buttonAtBody->Enabled = false;
	Trigger();
}
private: System::Void buttonAtLegs_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->attackHead == 1)
	{
		this->attackHead = 0;
		buttonAtHead->Enabled = true;
	}
	else if (this->attackBody == 1)
	{
		this->attackBody= 0;
		buttonAtBody->Enabled = true;
	}

	this->attackLegs = 1;
	buttonAtLegs->Enabled = false;
	Trigger();
}
private: System::Void buttonDefHead_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->protectBody == 1)
	{
		this->protectBody = 0;
		buttonDefBody->Enabled = true;
	}
	else if (this->protectLegs == 1)
	{
		this->protectLegs = 0;
		buttonDefLegs->Enabled = true;
	}

	this->protectHead = 1;
	buttonDefHead->Enabled = false;
	Trigger();
}
private: System::Void buttonDefBody_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->protectHead == 1)
	{
		this->protectHead = 0;
		buttonDefHead->Enabled = true;
	}
	else if (this->protectLegs == 1)
	{
		this->protectLegs = 0;
		buttonDefLegs->Enabled = true;
	}

	this->protectBody = 1;
	buttonDefBody->Enabled = false;
	Trigger();
}
private: System::Void buttonDefLegs_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->protectHead == 1)
	{
		this->protectHead = 0;
		buttonDefHead->Enabled = true;
	}
	else if (this->protectBody == 1)
	{
		this->protectBody = 0;
		buttonDefBody->Enabled = true;
	}

	this->protectLegs = 1;
	buttonDefLegs->Enabled = false;
	Trigger();
}
private: System::Void FightWindow_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxLog_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBoxLog->SelectionStart = textBoxLog->Text->Length;
	textBoxLog->ScrollToCaret();
}
private: System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	transferer->setFightOver();
	this->Close();
}
private: System::Void labelNAME_SURNAME_T_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("This is step-by-step fight.\n\nTo make your turn, choose enemy's body part which you wish to attack."
		+ "\nAt this time, you also need to choose which part of yourself you'll protect.\n\nAttacking blocked part "
		+ "reduces dealt damage by 80%.\nAttacking head causes 25% chance of dealing x1.5 damage!\nYour guards can also"
		+ "deal their own critical damage based on their precision: 10% (+5% for each guard's win).\nCrits are stacking."
		+ "\nAttacking blocked part NEVER deals critical damage.\n\nEach turn you attack first, then your enemy attacks."
		+ "If your fighter dies, another one of placed guards will replace him.\nLosing all guards means defeat, " 
		+ "while killing all terrorists - victory!", "Help", MessageBoxButtons::OK, MessageBoxIcon::Question);
}
private: System::Void FightWindow_Load_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonRestart_Click(System::Object^ sender, System::EventArgs^ e) {
	transferer->setRestartGame();
	this->Close();
}
};
}
