#include "GameActor.h"

// внутрішня функція по обробці шкоди, що наноситься
void GameActor::proceedDamage(GameActor* enemy, int damageDone)
{
	// перший удар по броні
	if (enemy->getArmorPoints() > 0)
	{
		enemy->setArmorPoints(enemy->getArmorPoints() - damageDone);
		// якщо атака сильніша за кількість броні
		if (enemy->getArmorPoints() < 0)
		{
			// удар по здоров'ю
			enemy->setHealthPoints(enemy->getHealthPoints() - enemy->getArmorPoints() * (-1));
			enemy->setArmorPoints(0);
		}
	}
	// якщо немає броні, то по здоров'ю
	else
		enemy->setHealthPoints(enemy->getHealthPoints() - damageDone);
}

// конструктор за замовченням
GameActor::GameActor()
{
	this->name = "";
	this->surname = "";

	this->healthPoints = 1;
	this->armorPoints = 0;
	this->damage = 0;
}

// конструктор з параметрами
GameActor::GameActor(std::string name, std::string surname, short healthPoints, short armorPoints, short damage)
{
	this->name = name;
	this->surname = surname;
	this->healthPoints = healthPoints;
	this->armorPoints = armorPoints;
	this->damage = damage;
}

// деструктор
GameActor::~GameActor() {}

// ГЕТЕРИ

// отримати ім'я
std::string GameActor::getName()
{
	return this->name;
}

// отримати прізвище
std::string GameActor::getSurname()
{
	return this->surname;
}

// отримати кількість здоров'я
short GameActor::getHealthPoints()
{
	return this->healthPoints;
}

// отримати кількість броні
short GameActor::getArmorPoints()
{
	return this->armorPoints;
}

// отримати наносиму шкоду
short GameActor::getDamage()
{
	return this->damage;
}

// СЕТЕРИ

// встановити ім'я
void GameActor::setName(std::string name)
{
	this->name = name;
}

// встановити прізвище
void GameActor::setSurname(std::string surname)
{
	this->surname = surname;
}

// встановити кількість здоров'я
void GameActor::setHealthPoints(short healthPoints)
{
	this->healthPoints = healthPoints;
}

// встановити кількість броні
void GameActor::setArmorPoints(short armorPoints)
{
	this->armorPoints = armorPoints;
}

// встановити наносиму шкоду
void GameActor::setDamage(short damage)
{
	this->damage = damage;
}
