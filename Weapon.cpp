#include "Weapon.h"

// конструктор за замовченням (на основі базового класу)
Weapon::Weapon() : Items()
{
	this->name = "Baton";
	this->damage = 10;
}

// конструктор з параметрами (на основі базового класу)
Weapon::Weapon(std::string name, int price, short damage): Items(name, price)
{
	this->damage = damage;
}

// деструктор
Weapon::~Weapon() {}

// ГЕТЕРИ

// отримати наносиму шкоду зброєю
short Weapon::getDamage()
{
	return this->damage;
}

// СЕТЕРИ

// встановити наносиму шкоду зброєю
void Weapon::setDamage(short damage)
{
	this->damage = damage;
}
