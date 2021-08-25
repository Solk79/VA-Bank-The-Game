#include "Equipment.h"

// конструктор за замовченням (на основі базового класу)
Equipment::Equipment(): Items()
{
	this->name = "None";
	this->bonusHP = 0;
	this->bonusAP = 0;
	this->bonusDamage = 0;
}

// конструктор з параметрами (на основі базового класу)
Equipment::Equipment(std::string name, int price, short bonusHP, short bonusAP, short bonusDamage) : Items(name, price)
{
	this->bonusHP = bonusHP;
	this->bonusAP = bonusAP;
	this->bonusDamage = bonusDamage;
}

// деструктор
Equipment::~Equipment() {}

// ГЕТЕРИ

// отримати кількість бонусу здоров'я
short Equipment::getBonusHP()
{
	return this->bonusHP;
}

// отримати кількість бонусу броні
short Equipment::getBonusAP()
{
	return this->bonusAP;
}

// отримати кількість бонусу атаки
short Equipment::getBonusDamage()
{
	return this->bonusDamage;
}

// СЕТЕРИ

// встановити кількість бонусу здоров'я
void Equipment::setBonusHP(short bonusHP)
{
	this->bonusHP = bonusHP;
}

// встановити кількість бонусу броні
void Equipment::setBonusAP(short bonusAP)
{
	this->bonusAP = bonusAP;
}

// встановити кількість бонусу атаки
void Equipment::setBonusDamage(short bonusDamage)
{
	this->bonusDamage = bonusDamage;
}

