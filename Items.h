#pragma once
#include <iostream>

// ������� ���� - ��������
class Items
{
protected:
	std::string name;	// ����������� ��������
	int price;			// ���� �������� (� �������)

public:
	// ����������� �� �����������
	Items();
	// ����������� � ����������� (�����������)
	Items(std::string name, int price);
	// ����������
	~Items();

	// ������

	// �������� ����������� ��������
	std::string getName();
	// �������� ����
	int getPrice();

	// ������
	
	// ���������� ����������� ��������
	void setName(std::string name);
	// ���������� ����
	void setPrice();
};