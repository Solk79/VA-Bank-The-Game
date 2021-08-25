#include "Informer.h"

const int START_MONEY = 2600;
const int START_ROUND = 0;
const int START_SCORE = 0;

// ����������� �� �����������
Informer::Informer()
{
	Player player(START_MONEY, START_ROUND, START_SCORE);
	this->player = player;
	for (int i = 0; i < 6; i++)
		this->guardsPlaced[i] = 0;
}

// ������

// �������� �������� �� ������
Player* Informer::getPlayerPTR()
{
	return &(this->player);
}

// �������� ���� ���������� �����
bool Informer::isFormFinished()
{
	return this->formFinished;
}

// �������� ���� ���������� ����� ��������� ��������
bool Informer::isEnterFinished()
{
	return this->enterFinished;
}

// �������� ���� ���������� ����� ���������
bool Informer::isGreetingFinished()
{
	return this->greetingFinished;
}

// �������� ���� ��������� ��������
bool Informer::areGuardsPlaced(int index)
{
	return this->guardsPlaced[index];
}

// �������� ���� ���������� ����� ���������� ��������
bool Informer::isEquipmentFinished()
{
	return this->equipmentFinished;
}

// �������� ���� ���������� ����� ���������� �������� (������ � ���������)
bool Informer::isEquipmentFinishedInvCall()
{
	return this->equipmentFinishedInvCall;
}

// �������� ���� ���������� ���
bool Informer::isFightOver()
{
	return this->fightOver;
}

// �������� ���� ������� ��� ������
bool Informer::isRestartGame()
{
	return this->restartGame;
}

// �������� ������-��������
void* Informer::getPointer()
{
	return this->ptr;
}

// ������

// ���������� ���� ���������� �����
void Informer::setFormFinished()
{
	if (!formFinished)
		this->formFinished = true;
	else
		this->formFinished = false;
}

// ���������� ���� ���������� ����� ��������� ��������
void Informer::setEnterFinished()
{
	if (!enterFinished)
		this->enterFinished = true;
	else
		this->enterFinished = false;
}

// ���������� ���� ���������� ���������
void Informer::setGreetingFinished()
{
	if (!greetingFinished)
		this->greetingFinished = true;
	else
		this->greetingFinished = false;
}

// ���������� ���� ��������� ��������
void Informer::setGuardsPlaced(int index)
{
	if (!guardsPlaced[index])
		this->guardsPlaced[index] = true;
	else
		this->guardsPlaced[index] = false;
}

// ���������� ���� ���������� ����� ���������� ��������
void Informer::setEquipmentFinished()
{
	if (!equipmentFinished)
		this->equipmentFinished = true;
	else
		this->equipmentFinished = false;
}

// ���������� ���� ���������� ����� ���������� ��������
void Informer::setEquipmentFinishedInvCall()
{
	if (!equipmentFinishedInvCall)
		this->equipmentFinishedInvCall = true;
	else
		this->equipmentFinishedInvCall = false;
}

// ���������� ���� ���������� ���
void Informer::setFightOver()
{
	if (!fightOver)
		this->fightOver = true;
	else
		this->fightOver = false;
}

// ���������� ���� ������� ��� ������
void Informer::setRestartGame()
{
	if (!restartGame)
		this->restartGame = true;
	else
		this->restartGame = false;
}

// ���������� ������-��������
void Informer::setPointer(void* ptr)
{
	this->ptr = ptr;
}
