#pragma once
#include "Items.h"

// ����-������� ����� �������� - �����������
class Equipment : public Items
{
private:
	short bonusHP;		// ����� ������'�
	short bonusAP;		// ����� ����
	short bonusDamage;	// ����� �����

public:
	// ����������� �� ����������� (�� ����� �������� �����)
	Equipment();
	// ����������� � ����������� (�� ����� �������� �����)
	Equipment(std::string name, int price, short bonusHP, short bonusAP, short bonusDamage);
	// ����������
	~Equipment();

	// ������

	// �������� ������� ������ ������'�
	short getBonusHP();
	// �������� ������� ������ ����
	short getBonusAP();
	// �������� ������� ������ �����
	short getBonusDamage();

	// ������

	// ���������� ������� ������ ������'�
	void setBonusHP(short bonusHP);
	// ���������� ������� ������ ����
	void setBonusAP(short bonusAP);
	// ���������� ������� ������ �����
	void setBonusDamage(short bonusDamage);
};

