#pragma once
#include <iostream>

// базовий клас - ігровий актор
class GameActor
{
protected:
	std::string name;		// ім'я актора
	std::string surname;	// прізвище актора

	short healthPoints;		// здоров'я актора
	short armorPoints;		// броня актора
	short damage;			// кількість здоров'я, яку може відняти актор у цілі при атаці (шкода)

	// внутрішня функція по обробці шкоди, що наноситься
	// використовується лише у класі і недоступна ззовні
	void proceedDamage(GameActor* enemy, int damageDone);

public:
	// конструктор за замовченням
	GameActor();
	// конструктор з параметрами (ініціалізація)
	GameActor(std::string name, std::string surname, short healthPoints, short armorPoints, short damage);
	// деструктор
	~GameActor();

	// ГЕТЕРИ

	// отримати ім'я
	std::string getName();
	// отримати прізвище
	std::string getSurname();
	// отримати кількість здоров'я
	short getHealthPoints();
	// отримати кількість броні
	short getArmorPoints();
	// отримати наносиму шкоду
	short getDamage();

	// СЕТЕРИ

	// встановити ім'я
	void setName(std::string name);
	// встановити прізвище
	void setSurname(std::string surname);
	// встановити кількість здоров'я
	void setHealthPoints(short healthPoints);
	// встановити кількість броні
	void setArmorPoints(short armorPoints);
	// встановити наносиму шкоду
	void setDamage(short damage);

	// відкрити вогонь по цілі
	// вхідні дані: об'єкт цілі - enemy, ціль-голова? - isHead, - ціль-захищена? - isDefended
	// вихідні дані: чи відбувся критичний постріл - critHit
	// return: скільки життів віднято
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked) = 0;
};

