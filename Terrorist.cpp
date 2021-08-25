#include "Terrorist.h"

// конструктор за замовченням (на основі базового класу)
Terrorist::Terrorist(): GameActor()
{
}

// конструктор з параметрами (на основі базового класу)
Terrorist::Terrorist(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, bool boss): GameActor(name, surname, healthPoints, armorPoints, damage)
{
	this->boss = boss;
}

// деструктор
Terrorist::~Terrorist() {}

// ГЕТЕРИ

// чи є босом
bool Terrorist::isBoss()
{
	return boss;
}

// СЕТЕРИ

// встановити босом
void Terrorist::setBoss()
{
	this->boss = true;
}

// ФУНКЦІЇ

// відкрити вогонь по цілі
// вхідні дані: об'єкт цілі - enemy, ціль-голова? - isHead, - ціль-захищена? - isDefended
// вихідні дані: чи відбувся критичний постріл - critHit
// return: скільки життів віднято
int Terrorist::fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked)
{
	int damageDone;
	if (isHead)
	{
		// 25% критичного попадання у голову (х1.5 шкоди)
		double headCritCasino = 0 + (double)rand() / (double)RAND_MAX;
		if (headCritCasino <= 0.25) // випавше число - у районі від 0 до 25
		{
			if (isDefended)
			{ 
				// зменшення по захищеній частині шкоди на 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// шкода з критичним попаданням x1.5
				damageDone = this->damage * 1.5;
				critHit = true;
			}
		}
		// якщо не випало
		else
		{
			if (isDefended)
			{
				// зменшення по захищеній частині шкоди на 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// звичайна шкода
				damageDone = this->damage;
			}
		}
	}
	// якщо не голова
	else
	{
		if (isDefended)
		{
			// зменшення по захищеній частині шкоди на 80%
			damageDone = this->damage - this->damage * 0.8;
			blocked = true;
		}
		else
		{
			// звичайна шкода
			damageDone = this->damage;
		}
	}
	proceedDamage(enemy, damageDone);

	return damageDone;

}