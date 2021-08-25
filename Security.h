#pragma once
#include "Weapon.h"
#include "Equipment.h"
#include "GameActor.h"

class Terrorist;

// ����-������� ����� �������� ������ - ���������
class Security : public GameActor
{
private:
	Weapon weapon;		// ������� �����
	Equipment stuff;	// �����������

	std::string rank;	// ������ ��������
	float precision;	// ������� ����� (���� ���������)
	short wins;			// �������� � ��������
	bool onPosition;	// �� ������ ������� ���������	

public:
	// ����������� �� ����������� (�� ����� �������� �����)
	Security();
	// ����������� � ����������� (�� ����� �������� �����)
	Security(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, float precision, std::string rank, short wins);
	// ����������
	~Security();

	// ������

	// �������� ������� �����
	Weapon getWeapon();
	// �������� �����������
	Equipment getStuff();
	// �������� ������ ��������
	std::string getRank();
	// �������� �������
	float getPrecision();
	// �������� �������� � ��������
	short getWins();
	// �������� �������
	bool isOnPosition();

	// ������

	// ���������� ������� �����
	void setWeapon(Weapon primaryW);
	// ���������� �����������
	void setStuff(Equipment stuff);
	// ���������� ������ ��������
	void setRank(std::string rank);
	// ���������� �������
	void setPrecision(float precision);
	// ���������� �������� � ��������
	void setWins(short wins);
	// ���������� �������
	void setOnPosition();

	// ����ֲ�

	// ������� ������ �� ���
	// ����� ���: ��'��� ��� - enemy, ����-������? - isHead, - ����-��������? - isDefended
	// ������ ���: �� ������� ��������� ������ - critHit
	// return: ������ ����� ������
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool& blocked);
	// ��������� �������� (��������)
	void rankUp();
	// ��������� ���������
	bool equalsTo(const Security& right);
};