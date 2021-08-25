#pragma once
#include "Player.h"

// ���� ����������, �� ���� � ��� ��������� ����������
class Informer
{
private:
	Player player;						// �������
	bool guardsPlaced[6];				// �� ���������� �������� �� ������ �������� �� ����

	bool formFinished = 0;				// ���� ��� ���������� ���� ������ � ������
	bool enterFinished = 0;				// ���� ��� ���������� ���� ������ � ������ ��������� ��������
	bool greetingFinished = 0;			// ���� ��� ���������� ���� ������ ���������� �����
	bool equipmentFinished = 0;			// ���� ��� ���������� ���� ������ � ������ ���������� ��������
	bool equipmentFinishedInvCall = 0;	// ���� ��� ���������� ���� ������ � ������ ���������� �������� (������ � ���������)  
	bool fightOver = 0;					// ���� ��� ���������� ���� ��� (��������� �� ���������� �������)
	bool restartGame = 0;				// ���� ��� ���������� ������� ������ ������ ��� ������

	void* ptr = nullptr;				// ������-�������� ��� ����-���� �����

public:
	// ����������� �� �����������
	Informer();

	// ������

	// �������� �������� �� ������
	Player* getPlayerPTR();
	// �������� ���� ���������� �����
	bool isFormFinished();
	// �������� ���� ���������� ����� ��������� ��������
	bool isEnterFinished();
	// �������� ���� ���������� ����� ���������
	bool isGreetingFinished();
	// �������� ���� ��������� ��������
	bool areGuardsPlaced(int index);
	// �������� ���� ���������� ����� ���������� ��������
	bool isEquipmentFinished();
	// �������� ���� ���������� ����� ���������� �������� (������ � ���������)
	bool isEquipmentFinishedInvCall();
	// �������� ���� ���������� ���
	bool isFightOver();
	// �������� ���� ������� ��� ������
	bool isRestartGame();
	// �������� ������-��������
	void* getPointer();

	// ������

	// ���������� ���� ���������� �����
	void setFormFinished();
	// ���������� ���� ���������� ����� ��������� ��������
	void setEnterFinished();
	// ���������� ���� ���������� ����� ���������
	void setGreetingFinished();
	// ���������� ���� ��������� ��������
	void setGuardsPlaced(int index);
	// ���������� ���� ���������� ����� ���������� ��������
	void setEquipmentFinished();
	// ���������� ���� ���������� ����� ���������� ��������
	void setEquipmentFinishedInvCall();
	// ���������� ���� ���������� ���
	void setFightOver();
	// ���������� ���� ������� ��� ������
	void setRestartGame();
	// ���������� ������-��������
	void setPointer(void *ptr);

};