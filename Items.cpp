#include "Items.h"

// конструктор за замовченням
Items::Items()
{
	this->name = "";
	this->price = 0;
}

// конструктор з параметрами (ініціалізація)
Items::Items(std::string name, int price)
{
	this->name = name;
	this->price = price;
}

// деструктор
Items::~Items() {}

// ГЕТЕРИ

// отримати наіменування предмету
std::string Items::getName()
{
	return this->name;
}

// отримати ціну
int Items::getPrice()
{
	return this->price;
}

// СЕТЕРИ

// встановити наіменування предмету
void Items::setName(std::string name)
{
	this->name = name;
}

// встановити ціну
void Items::setPrice()
{
	this->price = price;
}
