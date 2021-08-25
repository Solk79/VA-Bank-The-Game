#pragma once
#include "Player.h"

// клас ≥нформатор, що несе в соб≥ необх≥дну ≥нформац≥ю
class Informer
{
private:
	Player player;						// гравець
	bool guardsPlaced[6];				// чи розташован≥ охоронц≥ на певних позиц≥€х на форм≥

	bool formFinished = 0;				// флаг дл€ позначенн€ к≥нц€ роботи з формою
	bool enterFinished = 0;				// флаг дл€ позначенн€ к≥нц€ роботи з формою створенн€ охоронц€
	bool greetingFinished = 0;			// флаг дл€ позначенн€ к≥нц€ роботи прив≥тальноњ форми
	bool equipmentFinished = 0;			// флаг дл€ позначенн€ к≥нц€ роботи з формою обладнанн€ охоронц€
	bool equipmentFinishedInvCall = 0;	// флаг дл€ позначенн€ к≥нц€ роботи з формою обладнанн€ охоронц€ (виклик з ≥нвентарю)  
	bool fightOver = 0;					// флаг дл€ позначенн€ к≥нц€ бою (незалежно в≥д результату поЇдинку)
	bool restartGame = 0;				// флаг дл€ позначенн€ бажанн€ гравц€ почати гру заново

	void* ptr = nullptr;				// мульти-вказ≥вник дл€ будь-€ких задач

public:
	// конструктор за замовченн€м
	Informer();

	// √≈“≈–»

	// отримати вказ≥вник на гравц€
	Player* getPlayerPTR();
	// отримати флаг завершенн€ форми
	bool isFormFinished();
	// отримати флаг завершенн€ форми створенн€ охоронц€
	bool isEnterFinished();
	// отримати флаг завершенн€ форми прив≥танн€
	bool isGreetingFinished();
	// отримати флаг розм≥щенн€ охоронц€
	bool areGuardsPlaced(int index);
	// отримати флаг завершенн€ форми обладнанн€ охоронц€
	bool isEquipmentFinished();
	// отримати флаг завершенн€ форми обладнанн€ охоронц€ (виклик з ≥нвентарю)
	bool isEquipmentFinishedInvCall();
	// отримати флаг завершенн€ бою
	bool isFightOver();
	// отримати флаг початку гри заново
	bool isRestartGame();
	// отримати мульти-вказ≥вник
	void* getPointer();

	// —≈“≈–»

	// встановити флаг завершенн€ форми
	void setFormFinished();
	// встановити флаг завершенн€ форми створенн€ охоронц€
	void setEnterFinished();
	// встановити флаг завершенн€ форми прив≥танн€
	void setGreetingFinished();
	// встановити флаг розм≥щенн€ охоронц€
	void setGuardsPlaced(int index);
	// встановити флаг завершенн€ форми обладнанн€ охоронц€
	void setEquipmentFinished();
	// встановити флаг завершенн€ форми обладнанн€ охоронц€
	void setEquipmentFinishedInvCall();
	// встановити флаг завершенн€ бою
	void setFightOver();
	// встановити флаг початку гри заново
	void setRestartGame();
	// встановити мульти-вказ≥вник
	void setPointer(void *ptr);

};