#pragma once
#include "Items.h"

// клас-нащадок класу предмету - спорядження
class Equipment : public Items
{
private:
	short bonusHP;		// бонус здоров'я
	short bonusAP;		// бонус броні
	short bonusDamage;	// бонус атаки

public:
	// конструктор за замовченням (на основі базового класу)
	Equipment();
	// конструктор з параметрами (на основі базового класу)
	Equipment(std::string name, int price, short bonusHP, short bonusAP, short bonusDamage);
	// деструктор
	~Equipment();

	// ГЕТЕРИ

	// отримати кількість бонусу здоров'я
	short getBonusHP();
	// отримати кількість бонусу броні
	short getBonusAP();
	// отримати кількість бонусу атаки
	short getBonusDamage();

	// СЕТЕРИ

	// встановити кількість бонусу здоров'я
	void setBonusHP(short bonusHP);
	// встановити кількість бонусу броні
	void setBonusAP(short bonusAP);
	// встановити кількість бонусу атаки
	void setBonusDamage(short bonusDamage);
};

