#include "Player.h"

const int MAX_GUARDS = 10;

// конструктор за замовченн€м
Player::Player()
{
	this->money = 0;
	this->currentRound = 0;
	this->score = 0;
}

// конструктор з параметрами
Player::Player(int money, short currentRound, int score)
{
	this->money = money;
	this->currentRound = currentRound;
	this->score = score;
}

// деструктор
Player::~Player() {}

// √≈“≈–»

// отримати охоронц€
::Security Player::getGuard(int index)
{
	return this->guards[index];
}

// отримати охоронц€ (вказ≥вник)
::Security* Player::getGuardPTR(int index)
{
	return &this->guards[index];
}

// отримати вказ≥вник на контейнер охоронц≥в
GuardsContainer* Player::getGuardsContainerPTR()
{
	return &(this->guardsContainer);
}

// отримати к≥льк≥сть охоронц≥в на€вних у гравц€
short Player::getGuardsAmount()
{
	return this->guardsAmount;
}

// отримати к≥льк≥сть грошей
int Player::getMoney()
{
	return this->money;
}

// отримати поточний раунд
short Player::getCurrentRound()
{
	return this->currentRound;
}

// отримати к≥льк≥сть очок
int Player::getScore()
{
	return this->score;
}

// —≈“≈–»

// встановити охоронц€
void Player::setGuard(int index, ::Security guard)
{
	this->guards[index] = guard;
}

// встановити к≥льк≥сть охоронц≥в на€вних у гравц€
void Player::setGuardsAmount(short amount)
{
	this->guardsAmount = amount;
}


// встановити к≥льк≥сть грошей
void Player::setMoney(int money)
{
	this->money = money;
}

// встановити поточний раунд
void Player::setCurrentRound(short currentRound)
{
	this->currentRound = currentRound;
}

// встановити к≥льк≥сть очок
void Player::setScore(int score)
{
	this->score = score;
}

// ‘”Ќ ÷≤ѓ

// зм≥щенн€ охоронц≥в гравц€ вл≥во в≥д вказаного ≥ндексу
//		це необх≥дно дл€ коректного виведенн€ к≥лькост≥ ≥снуючих охоронц≥в гравц€
void Player::pushGuards()
{
	for (int i = 0; i < MAX_GUARDS - 1; i++)
	{
		if (guards[i].getHealthPoints() <= 0) // €кщо вбитий охоронець у ≥нвентар≥
		{
			for (int j = i; j < MAX_GUARDS - 1; j++) // зсув в≥д нього
			{
				// п≥дставл€Їмо значенн€ з container
				for (int k = 0; k < 6; k++)
				{
					if (guardsContainer.count(k) == 1)
						if (guards[j+1].equalsTo(*(guardsContainer.find(k)->second))) // €кщо на нього вказуЇ container
						{
							// зсув вказ≥вника контейнеру разом з ≥нвентарем
							guardsContainer.find(k)->second = &guards[j];
							break;
						}
				}
				this->guards[j] = this->guards[j + 1];
			}
			// останн≥й у зсув≥ - пустий
			Security empty;
			this->guards[MAX_GUARDS - 1] = empty;
		}
	}
}
