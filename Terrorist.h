#pragma once
#include "GameActor.h"

// ����-������� ����� �������� ������ - ��������
class Terrorist : public GameActor
{
	bool boss;	// ������ ����
public:
	// ����������� �� ����������� (�� ����� �������� �����)
	Terrorist();
	// ����������� � ����������� (�� ����� �������� �����)
	Terrorist(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, bool boss);
	// ����������
	~Terrorist();

	// ������

	// �� � �����
	bool isBoss();

	// ������

	// ���������� �����
	void setBoss();
	
	// ����ֲ�

	// ������� ������ �� ���
	// ����� ���: ��'��� ��� - enemy, ����-������? - isHead, - ����-��������? - isDefended
	// ������ ���: �� ������� ��������� ������ - critHit
	// return: ������ ����� ������
	virtual int fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked);
};

