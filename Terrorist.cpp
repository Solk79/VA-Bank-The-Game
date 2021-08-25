#include "Terrorist.h"

// ����������� �� ����������� (�� ����� �������� �����)
Terrorist::Terrorist(): GameActor()
{
}

// ����������� � ����������� (�� ����� �������� �����)
Terrorist::Terrorist(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, bool boss): GameActor(name, surname, healthPoints, armorPoints, damage)
{
	this->boss = boss;
}

// ����������
Terrorist::~Terrorist() {}

// ������

// �� � �����
bool Terrorist::isBoss()
{
	return boss;
}

// ������

// ���������� �����
void Terrorist::setBoss()
{
	this->boss = true;
}

// ����ֲ�

// ������� ������ �� ���
// ����� ���: ��'��� ��� - enemy, ����-������? - isHead, - ����-��������? - isDefended
// ������ ���: �� ������� ��������� ������ - critHit
// return: ������ ����� ������
int Terrorist::fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked)
{
	int damageDone;
	if (isHead)
	{
		// 25% ���������� ��������� � ������ (�1.5 �����)
		double headCritCasino = 0 + (double)rand() / (double)RAND_MAX;
		if (headCritCasino <= 0.25) // ������� ����� - � ����� �� 0 �� 25
		{
			if (isDefended)
			{ 
				// ��������� �� �������� ������ ����� �� 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// ����� � ��������� ���������� x1.5
				damageDone = this->damage * 1.5;
				critHit = true;
			}
		}
		// ���� �� ������
		else
		{
			if (isDefended)
			{
				// ��������� �� �������� ������ ����� �� 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// �������� �����
				damageDone = this->damage;
			}
		}
	}
	// ���� �� ������
	else
	{
		if (isDefended)
		{
			// ��������� �� �������� ������ ����� �� 80%
			damageDone = this->damage - this->damage * 0.8;
			blocked = true;
		}
		else
		{
			// �������� �����
			damageDone = this->damage;
		}
	}
	proceedDamage(enemy, damageDone);

	return damageDone;

}