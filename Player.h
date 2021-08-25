#pragma once
#include <iostream>
#include "Security.h"
#include <map>

typedef std::map<int, ::Security(*)> GuardsContainer;
// ���� �����������-������
class Player
{
private:
	::Security guards[10];				// �� �������� ������
	GuardsContainer guardsContainer;	// ��������� ��������� (map) �� ���

	short guardsAmount = 0; // ������� ��������� ������
	int money;				// ��������� ������, ��� �� �������
	short currentRound;		// �������� �����
	int score;				// ������� ����

public:
	// ����������� �� �����������
	Player();
	// ����������� � �����������
	Player(int money, short currentRound, int score);
	// ����������
	~Player();

	// ������

	// �������� ��������
	::Security getGuard(int index);
	// �������� �������� (��������)
	::Security* getGuardPTR(int index);
	// �������� �������� �� ��������� ���������
	GuardsContainer* getGuardsContainerPTR();
	// �������� ������� ��������� ������� � ������
	short getGuardsAmount();
	// �������� ������� ������
	int getMoney();
	// �������� �������� �����
	short getCurrentRound();
	// �������� ������� ����
	int getScore();

	// ������

	// ���������� ��������
	void setGuard(int index, ::Security guard);
	// ���������� ������� ��������� ������� � ������
	void setGuardsAmount(short amount);
	// ���������� ������� ������
	void setMoney(int money);
	// ���������� �������� �����
	void setCurrentRound(short currentRound);
	// ���������� ������� ����
	void setScore(int score);

	// ����ֲ�
	// ������� ��������� ������ ���� �� ��������� �������
	//		�� ��������� ��� ���������� ��������� ������� �������� ��������� ������
	void pushGuards();
};

