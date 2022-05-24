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
	// Добавили монетку достоинством 10
	m.addCoin(10);
	// Добавили монетку достоинством 5
	m.addCoin(5);
	// Ожидаем, что монеток внутри 2 штуки
	cout << m.getCoinsNumber() << endl;
	// Ожидаем, что общее достоинство всех монеток 15
	cout << m.getCoinsValue() << endl;

	return 0;
}


