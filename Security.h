#pragma once
#include "Weapon.h"
#include "Equipment.h"
#include "GameActor.h"

class Terrorist;

// клас-нащадок класу ≥грового актора - охоронець
class Security : public GameActor
{
private:
	Weapon weapon;		// основна збор€
	Equipment stuff;	// спор€дженн€

	std::string rank;	// званн€ охоронц€
	float precision;	// точн≥сть атаки (шанс атакувати)
	short wins;			// перемоги у поЇдинках
	bool onPosition;	// чи зайн€в позиц≥ю охоронець	

public:
	// конструктор за замовченн€м (на основ≥ базового класу)
	Security();
	// конструктор з параметрами (на основ≥ базового класу)
	Security(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, float precision, std::string rank, short wins);
	// деструктор
	~Security();

	// √≈“≈–»

	// отримати основну зброю
	Weapon getWeapon();
	// отримати спор€дженн€
	Equipment getStuff();
	// отримати званн€ охоронц€
	std::string getRank();
	// отримати точн≥сть
	float getPrecision();
	// отримати перемоги у поЇдинках
	short getWins();
	// отримати позиц≥ю
	bool isOnPosition();

	// —≈“≈–»

	// встановити основну зброю
	void setWeapon(Weapon primaryW);
	// встановити спор€дженн€
	void setStuff(Equipment stuff);
	// встановити званн€ охоронц€
	void setRank(std::string rank);
	// встановити точн≥сть
	void setPrecision(float precision);
	// встановити перемоги у поЇдинках
	void setWins(short wins);
	// встановити позиц≥ю
	void setOnPosition();

	// ‘”Ќ ÷≤ѓ

	// в≥дкрити вогонь по ц≥л≥
	// вх≥дн≥ дан≥: об'Їкт ц≥л≥ - enemy, ц≥ль-голова? - isHead, - ц≥ль-захищена? - isDefended
	// вих≥дн≥ дан≥: чи в≥дбувс€ критичний постр≥л - critHit
	// return: ск≥льки житт≥в в≥дн€то
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool& blocked);
	// п≥двищенн€ охоронц€ (перев≥рка)
	void rankUp();
	// пор≥вн€нн€ охоронц≥в
	bool equalsTo(const Security& right);
};