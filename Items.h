#pragma once
#include <iostream>

// базовий клас - предмети
class Items
{
protected:
	std::string name;	// наіменування предмету
	int price;			// ціна предмету (в магазині)

public:
	// конструктор за замовченням
	Items();
	// конструктор з параметрами (ініціалізація)
	Items(std::string name, int price);
	// деструктор
	~Items();

	// ГЕТЕРИ

	// отримати наіменування предмету
	std::string getName();
	// отримати ціну
	int getPrice();

	// СЕТЕРИ
	
	// встановити наіменування предмету
	void setName(std::string name);
	// встановити ціну
	void setPrice();
};