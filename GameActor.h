#pragma once
#include <iostream>

// ������� ���� - ������� �����
class GameActor
{
protected:
	std::string name;		// ��'� ������
	std::string surname;	// ������� ������

	short healthPoints;		// ������'� ������
	short armorPoints;		// ����� ������
	short damage;			// ������� ������'�, ��� ���� ������ ����� � ��� ��� ����� (�����)

	// �������� ������� �� ������� �����, �� ����������
	// ��������������� ���� � ���� � ���������� �����
	void proceedDamage(GameActor* enemy, int damageDone);

public:
	// ����������� �� �����������
	GameActor();
	// ����������� � ����������� (�����������)
	GameActor(std::string name, std::string surname, short healthPoints, short armorPoints, short damage);
	// ����������
	~GameActor();

	// ������

	// �������� ��'�
	std::string getName();
	// �������� �������
	std::string getSurname();
	// �������� ������� ������'�
	short getHealthPoints();
	// �������� ������� ����
	short getArmorPoints();
	// �������� �������� �����
	short getDamage();

	// ������

	// ���������� ��'�
	void setName(std::string name);
	// ���������� �������
	void setSurname(std::string surname);
	// ���������� ������� ������'�
	void setHealthPoints(short healthPoints);
	// ���������� ������� ����
	void setArmorPoints(short armorPoints);
	// ���������� �������� �����
	void setDamage(short damage);

	// ������� ������ �� ���
	// ����� ���: ��'��� ��� - enemy, ����-������? - isHead, - ����-��������? - isDefended
	// ������ ���: �� ������� ��������� ������ - critHit
	// return: ������ ����� ������
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked) = 0;
};

