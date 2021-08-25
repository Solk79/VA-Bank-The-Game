#include "GameActor.h"

// �������� ������� �� ������� �����, �� ����������
void GameActor::proceedDamage(GameActor* enemy, int damageDone)
{
	// ������ ���� �� ����
	if (enemy->getArmorPoints() > 0)
	{
		enemy->setArmorPoints(enemy->getArmorPoints() - damageDone);
		// ���� ����� ������� �� ������� ����
		if (enemy->getArmorPoints() < 0)
		{
			// ���� �� ������'�
			enemy->setHealthPoints(enemy->getHealthPoints() - enemy->getArmorPoints() * (-1));
			enemy->setArmorPoints(0);
		}
	}
	// ���� ���� ����, �� �� ������'�
	else
		enemy->setHealthPoints(enemy->getHealthPoints() - damageDone);
}

// ����������� �� �����������
GameActor::GameActor()
{
	this->name = "";
	this->surname = "";

	this->healthPoints = 1;
	this->armorPoints = 0;
	this->damage = 0;
}

// ����������� � �����������
GameActor::GameActor(std::string name, std::string surname, short healthPoints, short armorPoints, short damage)
{
	this->name = name;
	this->surname = surname;
	this->healthPoints = healthPoints;
	this->armorPoints = armorPoints;
	this->damage = damage;
}

// ����������
GameActor::~GameActor() {}

// ������

// �������� ��'�
std::string GameActor::getName()
{
	return this->name;
}

// �������� �������
std::string GameActor::getSurname()
{
	return this->surname;
}

// �������� ������� ������'�
short GameActor::getHealthPoints()
{
	return this->healthPoints;
}

// �������� ������� ����
short GameActor::getArmorPoints()
{
	return this->armorPoints;
}

// �������� �������� �����
short GameActor::getDamage()
{
	return this->damage;
}

// ������

// ���������� ��'�
void GameActor::setName(std::string name)
{
	this->name = name;
}

// ���������� �������
void GameActor::setSurname(std::string surname)
{
	this->surname = surname;
}

// ���������� ������� ������'�
void GameActor::setHealthPoints(short healthPoints)
{
	this->healthPoints = healthPoints;
}

// ���������� ������� ����
void GameActor::setArmorPoints(short armorPoints)
{
	this->armorPoints = armorPoints;
}

// ���������� �������� �����
void GameActor::setDamage(short damage)
{
	this->damage = damage;
}
