#include "Informer.h"

const int START_MONEY = 2600;
const int START_ROUND = 0;
const int START_SCORE = 0;

// конструктор за замовченн€м
Informer::Informer()
{
	Player player(START_MONEY, START_ROUND, START_SCORE);
	this->player = player;
	for (int i = 0; i < 6; i++)
		this->guardsPlaced[i] = 0;
}

// √≈“≈–»

// отримати вказ≥вник на гравц€
Player* Informer::getPlayerPTR()
{
	return &(this->player);
}

// отримати флаг завершенн€ форми
bool Informer::isFormFinished()
{
	return this->formFinished;
}

// отримати флаг завершенн€ форми створенн€ охоронц€
bool Informer::isEnterFinished()
{
	return this->enterFinished;
}

// отримати флаг завершенн€ форми прив≥танн€
bool Informer::isGreetingFinished()
{
	return this->greetingFinished;
}

// отримати флаг розм≥щенн€ охоронц€
bool Informer::areGuardsPlaced(int index)
{
	return this->guardsPlaced[index];
}

// отримати флаг завершенн€ форми обладнанн€ охоронц€
bool Informer::isEquipmentFinished()
{
	return this->equipmentFinished;
}

// отримати флаг завершенн€ форми обладнанн€ охоронц€ (виклик з ≥нвентарю)
bool Informer::isEquipmentFinishedInvCall()
{
	return this->equipmentFinishedInvCall;
}

// отримати флаг завершенн€ бою
bool Informer::isFightOver()
{
	return this->fightOver;
}

// отримати флаг початку гри заново
bool Informer::isRestartGame()
{
	return this->restartGame;
}

// отримати мульти-вказ≥вник
void* Informer::getPointer()
{
	return this->ptr;
}

// —≈“≈–»

// встановити флаг завершенн€ форми
void Informer::setFormFinished()
{
	if (!formFinished)
		this->formFinished = true;
	else
		this->formFinished = false;
}

// встановити флаг завершенн€ форми створенн€ охоронц€
void Informer::setEnterFinished()
{
	if (!enterFinished)
		this->enterFinished = true;
	else
		this->enterFinished = false;
}

// встановити флаг завершенн€ прив≥танн€
void Informer::setGreetingFinished()
{
	if (!greetingFinished)
		this->greetingFinished = true;
	else
		this->greetingFinished = false;
}

// встановити флаг розм≥щенн€ охоронц€
void Informer::setGuardsPlaced(int index)
{
	if (!guardsPlaced[index])
		this->guardsPlaced[index] = true;
	else
		this->guardsPlaced[index] = false;
}

// встановити флаг завершенн€ форми обладнанн€ охоронц€
void Informer::setEquipmentFinished()
{
	if (!equipmentFinished)
		this->equipmentFinished = true;
	else
		this->equipmentFinished = false;
}

// встановити флаг завершенн€ форми обладнанн€ охоронц€
void Informer::setEquipmentFinishedInvCall()
{
	if (!equipmentFinishedInvCall)
		this->equipmentFinishedInvCall = true;
	else
		this->equipmentFinishedInvCall = false;
}

// встановити флаг завершенн€ бою
void Informer::setFightOver()
{
	if (!fightOver)
		this->fightOver = true;
	else
		this->fightOver = false;
}

// встановити флаг початку гри заново
void Informer::setRestartGame()
{
	if (!restartGame)
		this->restartGame = true;
	else
		this->restartGame = false;
}

// встановити мульти-вказ≥вник
void Informer::setPointer(void* ptr)
{
	this->ptr = ptr;
}
