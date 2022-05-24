/*
 * task_02.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class MoneyBox
{
public:
	void addCoin(unsigned int value)
	{
		number++;
		total_value += value;
	}

	unsigned int getCoinsNumber() const
	{
		return number;
	}

	unsigned int getCoinsValue() const
	{
		return total_value;
	}

private:
	unsigned int number = 0;
	unsigned int total_value = 0;
};


int main()
{
	MoneyBox m;
	// �������� ������� ������������ 10
	m.addCoin(10);
	// �������� ������� ������������ 5
	m.addCoin(5);
	// �������, ��� ������� ������ 2 �����
	cout << m.getCoinsNumber() << endl;
	// �������, ��� ����� ����������� ���� ������� 15
	cout << m.getCoinsValue() << endl;

	return 0;
}


