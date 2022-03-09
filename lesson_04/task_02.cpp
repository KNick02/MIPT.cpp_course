/*
 * task_02.cpp
 *
 *  Created on: 9 ���. 2022 �.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

using namespace std;

class Player
{
protected:
	// ���� � ������� �����
	int strength;
	int level;
public:
	// ������� �����, ��� ����������� ����� ������� �����
	Player() { }
	// ������� �����, ������ ������ ��� ��������� ���� ��� �� �������
	virtual ~Player() { }
	// ������� ������, ���� ��� ����� �������.
	// �� ������ ����� ����� �������, ��� ��� ���� ������ ��� ����� ���� ���������,
	// ��� ��� ����� ����� � ������� ������.
	// ������ ����
	void setStrength(int strength) {
		this->strength = strength;
	}
	// ������ �������
	void setLevel(int level) {

		this->level = level;
	}
	// �������� ����
	int getStrength() {
		return this->strength;
	}
	// �������� �������
	int getLevel() {
		return this->level;
	}
	// ��������, ����� �� ����� ������������ �������
	virtual bool canUse(Item* item) = 0;
};


class Knight : public Player
{
public:
	bool canUse(Item* item) override
	{
		return 	(item -> isMagical()) &&
				(getStrength() >= item->getWeight()) &&
				(getLevel() >= item->getLevel());
	}
};


class Wizard : public Player
{
public:
	bool canUse(Item* item) override
	{
		return 	(getStrength() >= item->getWeight()) &&
				(getLevel() >= item->getLevel());
	}
};

