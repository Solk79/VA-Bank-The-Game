#pragma once
#include "GameActor.h"

// клас-нащадок класу ігрового актора - терорист
class Terrorist : public GameActor
{
	bool boss;	// ознака боса
public:
	// конструктор за замовченням (на основі базового класу)
	Terrorist();
	// конструктор з параметрами (на основі базового класу)
	Terrorist(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, bool boss);
	// деструктор
	~Terrorist();

	// ГЕТЕРИ

	// чи є босом
	bool isBoss();

	// СЕТЕРИ

	// встановити босом
	void setBoss();
	
	// ФУНКЦІЇ

	// відкрити вогонь по цілі
	// вхідні дані: об'єкт цілі - enemy, ціль-голова? - isHead, - ціль-захищена? - isDefended
	// вихідні дані: чи відбувся критичний постріл - critHit
	// return: скільки життів віднято
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked);
};

