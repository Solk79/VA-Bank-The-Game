#include "Security.h"
#include "Security.h"

// конструктор за замовченн€м (на основ≥ базового класу)
Security::Security(): GameActor()
{
	this->rank = "";
	this->precision = 1;
	this->wins = 0;
}

// конструктор з параметрами (на основ≥ базового класу)
Security::Security(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, float precision, std::string rank, short wins) : GameActor(name, surname, healthPoints, armorPoints, damage)
{
	this->rank = rank;
	this->precision = precision;
	this->wins = wins;
	this->onPosition = 0;
}

// деструктор
Security::~Security() {}

// √≈“≈–»

// отримати основну зброю
Weapon Security::getWeapon()
{
	return this->weapon;
}
// отримати спор€дженн€
Equipment Security::getStuff()
{
	return this->stuff;
}

// отримати званн€ охоронц€
std::string Security::getRank()
{
	return this->rank;
}

// отримати точн≥сть
float Security::getPrecision()
{
	return this->precision;
}

// отримати перемоги у поЇдинках
short Security::getWins()
{
	return this->wins;
}

// отримати позиц≥ю
bool Security::isOnPosition()
{
	return this->onPosition;
}

// —≈“≈–»

// встановити основну зброю
void Security::setWeapon(Weapon primaryW)
{
	this->weapon = primaryW;
}

// встановити спор€дженн€
void Security::setStuff(Equipment stuff)
{
	this->stuff = stuff;
}

// встановити званн€ охоронц€
void Security::setRank(std::string rank)
{
	this->rank = rank;
}

// встановити точн≥сть
void Security::setPrecision(float precision)
{
	this->precision = precision;
}

// встановити перемоги у поЇдинках
void Security::setWins(short wins)
{
	this->wins = wins;
}

// встановити позиц≥ю
void Security::setOnPosition()
{
	if (!(this->onPosition))
		this->onPosition = true;
	else
		this->onPosition = false;
}

// ‘”Ќ ÷≤ѓ

// в≥дкрити вогонь по ц≥л≥
// вх≥дн≥ дан≥: об'Їкт ц≥л≥ - enemy, ц≥ль-голова? - isHead, - ц≥ль-захищена? - isDefended
// вих≥дн≥ дан≥: чи в≥дбувс€ критичний постр≥л - critHit
// return: ск≥льки житт≥в в≥дн€то
int Security::fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked)
{
	int damageDone;		// наносима шкода
	double critCasino;	// шанс що випав
	if (isHead)
	{
		// 25% критичного попаданн€ у голову (х1.5 шкоди)
		critCasino = 0 + (double)rand() / (double)RAND_MAX;
		if (critCasino <= 0.25) // випавше число - у район≥ в≥д 0 до 25
		{
			if (isDefended)
			{
				// зменшенн€ по захищен≥й частин≥ шкоди на 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// (10 + 5*к≥льк≥сть перемог) в≥дсотк≥в шансу нанести власне крит попаданн€
				double chance = (10 + 5 * this->wins) / 100.0;
				critCasino = 0 + (double)rand() / (double)RAND_MAX;
				if (critCasino <= chance) // випавше число - у район≥ в≥д 0 до шансу
				{
					// шкода з критичним попаданн€м precision та по голов≥ (х1.5)
					damageDone = this->damage * 1.5 * precision;
				}
				// €кщо не випало
				else
				{
					// критичне попаданн€ по голов≥ (х1.5)
					damageDone = this->damage * 1.5;
				}
				critHit = true;
			}
		}
		// €кщо не випало
		else
		{
			// (10 + 5*к≥льк≥сть перемог) в≥дсотк≥в шансу нанести власне крит попаданн€
			double chance = (10 + 5 * this->wins) / 100.0;
			critCasino = 0 + (double)rand() / (double)RAND_MAX;;
			if (critCasino <= chance) // випавше число - у район≥ в≥д 0 до шансу
			{
				// шкода з критичним попаданн€м precision
				damageDone = this->damage * precision;
				critHit = true;
			}
			// €кщо не випало
			else
			{
				// звичайна шкода
				damageDone = this->damage;
			}
		}
	}
	// €кщо не голова
	else
	{
		if (isDefended)
		{
			// зменшенн€ по захищен≥й частин≥ шкоди на 80%
			damageDone = this->damage - this->damage * 0.8;
			blocked = true;
		}
		else
		{
			// (10 + 5*к≥льк≥сть перемог) в≥дсотк≥в шансу нанести власне крит попаданн€
			double chance = (10 + 5 * this->wins) / 100.0;
			critCasino = 0 + (double)rand() / (double)RAND_MAX;
			if (critCasino <= chance) // випавше число - у район≥ в≥д 0 до шансу
			{
				// шкода з критичним попаданн€м precision
				damageDone = this->damage * precision;
				critHit = true;
			}
			// €кщо не випало
			else
			{
				// звичайна шкода
				damageDone = this->damage;
			}
		}
	}
	proceedDamage(enemy, damageDone);

	return damageDone;
}

// п≥двищенн€ охоронц€ (перев≥рка)
void Security::rankUp()
{
	switch (this->wins)
	{
	case 3:
		this->rank = "sergeant";
		break;
	case 5:
		this->rank = "lieutenant";
		break;
	case 7:
		this->rank = "captain";
		break;
	}
}

// пор≥вн€нн€ охоронц≥в
bool Security::equalsTo(const Security& right)
{
	return ((this->name == right.name) && (this->surname == this->surname));
}
