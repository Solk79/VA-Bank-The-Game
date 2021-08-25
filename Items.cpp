#include "Items.h"

// ����������� �� �����������
Items::Items()
{
	this->name = "";
	this->price = 0;
}

// ����������� � ����������� (�����������)
Items::Items(std::string name, int price)
{
	this->name = name;
	this->price = price;
}

// ����������
Items::~Items() {}

// ������

// �������� ����������� ��������
std::string Items::getName()
{
	return this->name;
}

// �������� ����
int Items::getPrice()
{
	return this->price;
}

// ������

// ���������� ����������� ��������
void Items::setName(std::string name)
{
	this->name = name;
}

// ���������� ����
void Items::setPrice()
{
	this->price = price;
}
