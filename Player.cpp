#include "Player.h"

const int MAX_GUARDS = 10;

// ����������� �� �����������
Player::Player()
{
	this->money = 0;
	this->currentRound = 0;
	this->score = 0;
}

// ����������� � �����������
Player::Player(int money, short currentRound, int score)
{
	this->money = money;
	this->currentRound = currentRound;
	this->score = score;
}

// ����������
Player::~Player() {}

// ������

// �������� ��������
::Security Player::getGuard(int index)
{
	return this->guards[index];
}

// �������� �������� (��������)
::Security* Player::getGuardPTR(int index)
{
	return &this->guards[index];
}

// �������� �������� �� ��������� ���������
GuardsContainer* Player::getGuardsContainerPTR()
{
	return &(this->guardsContainer);
}

// �������� ������� ��������� ������� � ������
short Player::getGuardsAmount()
{
	return this->guardsAmount;
}

// �������� ������� ������
int Player::getMoney()
{
	return this->money;
}

// �������� �������� �����
short Player::getCurrentRound()
{
	return this->currentRound;
}

// �������� ������� ����
int Player::getScore()
{
	return this->score;
}

// ������

// ���������� ��������
void Player::setGuard(int index, ::Security guard)
{
	this->guards[index] = guard;
}

// ���������� ������� ��������� ������� � ������
void Player::setGuardsAmount(short amount)
{
	this->guardsAmount = amount;
}


// ���������� ������� ������
void Player::setMoney(int money)
{
	this->money = money;
}

// ���������� �������� �����
void Player::setCurrentRound(short currentRound)
{
	this->currentRound = currentRound;
}

// ���������� ������� ����
void Player::setScore(int score)
{
	this->score = score;
}

// ����ֲ�

// ������� ��������� ������ ���� �� ��������� �������
//		�� ��������� ��� ���������� ��������� ������� �������� ��������� ������
void Player::pushGuards()
{
	for (int i = 0; i < MAX_GUARDS - 1; i++)
	{
		if (guards[i].getHealthPoints() <= 0) // ���� ������ ��������� � ��������
		{
			for (int j = i; j < MAX_GUARDS - 1; j++) // ���� �� �����
			{
				// ����������� �������� � container
				for (int k = 0; k < 6; k++)
				{
					if (guardsContainer.count(k) == 1)
						if (guards[j+1].equalsTo(*(guardsContainer.find(k)->second))) // ���� �� ����� ����� container
						{
							// ���� ��������� ���������� ����� � ����������
							guardsContainer.find(k)->second = &guards[j];
							break;
						}
				}
				this->guards[j] = this->guards[j + 1];
			}
			// ������� � ���� - ������
			Security empty;
			this->guards[MAX_GUARDS - 1] = empty;
		}
	}
}
