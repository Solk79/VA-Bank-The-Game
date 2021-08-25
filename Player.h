#pragma once
#include <iostream>
#include "Security.h"
#include <map>

typedef std::map<int, ::Security(*)> GuardsContainer;
// клас користувача-гравц€
class Player
{
private:
	::Security guards[10];				// ус≥ охоронц≥ гравц€
	GuardsContainer guardsContainer;	// контейнер охоронц≥в (map) на пол≥

	short guardsAmount = 0; // к≥льк≥сть охоронц≥в гравц€
	int money;				// в≥ртуальна валюта, €ку маЇ гравець
	short currentRound;		// поточний раунд
	int score;				// к≥льк≥сть очок

public:
	// конструктор за замовченн€м
	Player();
	// конструктор з параметрами
	Player(int money, short currentRound, int score);
	// деструктор
	~Player();

	// √≈“≈–»

	// отримати охоронц€
	::Security getGuard(int index);
	// отримати охоронц€ (вказ≥вник)
	::Security* getGuardPTR(int index);
	// отримати вказ≥вник на контейнер охоронц≥в
	GuardsContainer* getGuardsContainerPTR();
	// отримати к≥льк≥сть охоронц≥в на€вних у гравц€
	short getGuardsAmount();
	// отримати к≥льк≥сть грошей
	int getMoney();
	// отримати поточний раунд
	short getCurrentRound();
	// отримати к≥льк≥сть очок
	int getScore();

	// —≈“≈–»

	// встановити охоронц€
	void setGuard(int index, ::Security guard);
	// встановити к≥льк≥сть охоронц≥в на€вних у гравц€
	void setGuardsAmount(short amount);
	// встановити к≥льк≥сть грошей
	void setMoney(int money);
	// встановити поточний раунд
	void setCurrentRound(short currentRound);
	// встановити к≥льк≥сть очок
	void setScore(int score);

	// ‘”Ќ ÷≤ѓ
	// зм≥щенн€ охоронц≥в гравц€ вл≥во в≥д вказаного ≥ндексу
	//		це необх≥дно дл€ коректного виведенн€ к≥лькост≥ ≥снуючих охоронц≥в гравц€
	void pushGuards();
};

