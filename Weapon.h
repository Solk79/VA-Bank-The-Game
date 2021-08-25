#pragma once
#include "Items.h"

// ����-������� ����� �������� - �����
class Weapon : public Items
{
private:
	short damage;	// ������� ������'�, ��� ���� �������� ����� (�����)

public:
	// ����������� �� ����������� (�� ����� �������� �����)
	Weapon();
	// ����������� � ����������� (�� ����� �������� �����)
	Weapon(std::string name, int price, short damage);
	// ����������
	~Weapon();

	// ������

	// �������� �������� ����� �����
	short getDamage();

	// ������

	// ���������� �������� ����� �����
	void setDamage(short damage);
};

