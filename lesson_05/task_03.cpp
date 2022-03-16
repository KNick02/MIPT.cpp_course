/*
 * task_03.cpp
 *
 *  Created on: 16 ���. 2022 �.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

class Animal
{
public:
	// ��������� ������ ��������.
	// ����������� ������� �� ���������� ������� ������ ��� ������ ���������� ��������.
	virtual void pet() = 0;

	virtual ~Animal() {};
};


class NPC
{
public:
	// ���������� � NPC.
	// ��� �� ������ - ������� �� ���������� ������� ������ ��� ����������� NPC.
	virtual void talk() = 0;

	virtual ~NPC() {};
};


class SmartCat : public Animal, public NPC
{
public:
	void talk() override
	{
		std::cout << "Meow!" << std::endl;
	}

	void pet() override
	{
		talk();
	}
};

/*
int main()
{
	// �������� ��� � ����� ������� ����� ���������� ����� ������,
	// ������� ������-�� �������� �� �������������� �� �������.
	Animal *a = new SmartCat();
	a->pet();
	delete a;

	// � ��� - ����� ������, ������� �������� � NPC.

	NPC *n = new SmartCat();
	n->talk();
	delete n;
}
*/
