#pragma once
#include "Items.h"

// клас-нащадок класу предмету - зброя
class Weapon : public Items
{
private:
	short damage;	// кількість здоров'я, яке може зменшити зброя (шкода)

public:
	// конструктор за замовченням (на основі базового класу)
	Weapon();
	// конструктор з параметрами (на основі базового класу)
	Weapon(std::string name, int price, short damage);
	// деструктор
	~Weapon();

	// ГЕТЕРИ

	// отримати наносиму шкоду зброєю
	short getDamage();

	// СЕТЕРИ

	// встановити наносиму шкоду зброєю
	void setDamage(short damage);
};

