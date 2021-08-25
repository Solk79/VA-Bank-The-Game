#include "Weapon.h"

// ����������� �� ����������� (�� ����� �������� �����)
Weapon::Weapon() : Items()
{
	this->name = "Baton";
	this->damage = 10;
}

// ����������� � ����������� (�� ����� �������� �����)
Weapon::Weapon(std::string name, int price, short damage): Items(name, price)
{
	this->damage = damage;
}

// ����������
Weapon::~Weapon() {}

// ������

// �������� �������� ����� �����
short Weapon::getDamage()
{
	return this->damage;
}

// ������

// ���������� �������� ����� �����
void Weapon::setDamage(short damage)
{
	this->damage = damage;
}
