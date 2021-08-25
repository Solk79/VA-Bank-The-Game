#include "Security.h"
#include "Security.h"

// ����������� �� ����������� (�� ����� �������� �����)
Security::Security(): GameActor()
{
	this->rank = "";
	this->precision = 1;
	this->wins = 0;
}

// ����������� � ����������� (�� ����� �������� �����)
Security::Security(std::string name, std::string surname, short healthPoints, short armorPoints, short damage, float precision, std::string rank, short wins) : GameActor(name, surname, healthPoints, armorPoints, damage)
{
	this->rank = rank;
	this->precision = precision;
	this->wins = wins;
	this->onPosition = 0;
}

// ����������
Security::~Security() {}

// ������

// �������� ������� �����
Weapon Security::getWeapon()
{
	return this->weapon;
}
// �������� �����������
Equipment Security::getStuff()
{
	return this->stuff;
}

// �������� ������ ��������
std::string Security::getRank()
{
	return this->rank;
}

// �������� �������
float Security::getPrecision()
{
	return this->precision;
}

// �������� �������� � ��������
short Security::getWins()
{
	return this->wins;
}

// �������� �������
bool Security::isOnPosition()
{
	return this->onPosition;
}

// ������

// ���������� ������� �����
void Security::setWeapon(Weapon primaryW)
{
	this->weapon = primaryW;
}

// ���������� �����������
void Security::setStuff(Equipment stuff)
{
	this->stuff = stuff;
}

// ���������� ������ ��������
void Security::setRank(std::string rank)
{
	this->rank = rank;
}

// ���������� �������
void Security::setPrecision(float precision)
{
	this->precision = precision;
}

// ���������� �������� � ��������
void Security::setWins(short wins)
{
	this->wins = wins;
}

// ���������� �������
void Security::setOnPosition()
{
	if (!(this->onPosition))
		this->onPosition = true;
	else
		this->onPosition = false;
}

// ����ֲ�

// ������� ������ �� ���
// ����� ���: ��'��� ��� - enemy, ����-������? - isHead, - ����-��������? - isDefended
// ������ ���: �� ������� ��������� ������ - critHit
// return: ������ ����� ������
int Security::fire(GameActor* enemy, bool isHead, bool isDefended, bool &critHit, bool &blocked)
{
	int damageDone;		// �������� �����
	double critCasino;	// ���� �� �����
	if (isHead)
	{
		// 25% ���������� ��������� � ������ (�1.5 �����)
		critCasino = 0 + (double)rand() / (double)RAND_MAX;
		if (critCasino <= 0.25) // ������� ����� - � ����� �� 0 �� 25
		{
			if (isDefended)
			{
				// ��������� �� �������� ������ ����� �� 80%
				damageDone = this->damage - this->damage * 0.8;
				blocked = true;
			}
			else
			{
				// (10 + 5*������� �������) ������� ����� ������� ������ ���� ���������
				double chance = (10 + 5 * this->wins) / 100.0;
				critCasino = 0 + (double)rand() / (double)RAND_MAX;
				if (critCasino <= chance) // ������� ����� - � ����� �� 0 �� �����
				{
					// ����� � ��������� ���������� precision �� �� ����� (�1.5)
					damageDone = this->damage * 1.5 * precision;
				}
				// ���� �� ������
				else
				{
					// �������� ��������� �� ����� (�1.5)
					damageDone = this->damage * 1.5;
				}
				critHit = true;
			}
		}
		// ���� �� ������
		else
		{
			// (10 + 5*������� �������) ������� ����� ������� ������ ���� ���������
			double chance = (10 + 5 * this->wins) / 100.0;
			critCasino = 0 + (double)rand() / (double)RAND_MAX;;
			if (critCasino <= chance) // ������� ����� - � ����� �� 0 �� �����
			{
				// ����� � ��������� ���������� precision
				damageDone = this->damage * precision;
				critHit = true;
			}
			// ���� �� ������
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
			// (10 + 5*������� �������) ������� ����� ������� ������ ���� ���������
			double chance = (10 + 5 * this->wins) / 100.0;
			critCasino = 0 + (double)rand() / (double)RAND_MAX;
			if (critCasino <= chance) // ������� ����� - � ����� �� 0 �� �����
			{
				// ����� � ��������� ���������� precision
				damageDone = this->damage * precision;
				critHit = true;
			}
			// ���� �� ������
			else
			{
				// �������� �����
				damageDone = this->damage;
			}
		}
	}
	proceedDamage(enemy, damageDone);

	return damageDone;
}

// ��������� �������� (��������)
void Security::rankUp()
{
	switch (this->wins)
	{
	case 3:
		this->rank = "sergeant";
		break;
	case 5:
		this->rank = "lieutenant";
		break;
	case 7:
		this->rank = "captain";
		break;
	}
}

// ��������� ���������
bool Security::equalsTo(const Security& right)
{
	return ((this->name == right.name) && (this->surname == this->surname));
}
