#include "Equipment.h"

// ����������� �� ����������� (�� ����� �������� �����)
Equipment::Equipment(): Items()
{
	this->name = "None";
	this->bonusHP = 0;
	this->bonusAP = 0;
	this->bonusDamage = 0;
}

// ����������� � ����������� (�� ����� �������� �����)
Equipment::Equipment(std::string name, int price, short bonusHP, short bonusAP, short bonusDamage) : Items(name, price)
{
	this->bonusHP = bonusHP;
	this->bonusAP = bonusAP;
	this->bonusDamage = bonusDamage;
}

// ����������
Equipment::~Equipment() {}

// ������

// �������� ������� ������ ������'�
short Equipment::getBonusHP()
{
	return this->bonusHP;
}

// �������� ������� ������ ����
short Equipment::getBonusAP()
{
	return this->bonusAP;
}

// �������� ������� ������ �����
short Equipment::getBonusDamage()
{
	return this->bonusDamage;
}

// ������

// ���������� ������� ������ ������'�
void Equipment::setBonusHP(short bonusHP)
{
	this->bonusHP = bonusHP;
}

// ���������� ������� ������ ����
void Equipment::setBonusAP(short bonusAP)
{
	this->bonusAP = bonusAP;
}

// ���������� ������� ������ �����
void Equipment::setBonusDamage(short bonusDamage)
{
	this->bonusDamage = bonusDamage;
}

