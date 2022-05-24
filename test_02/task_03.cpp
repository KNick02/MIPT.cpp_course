/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <exception>

using namespace std;
class GasStation {
public:
	GasStation(unsigned int c) : capacity(c), current(0) {}

	void fill(unsigned int n)
	{
		if (current + n > capacity)
				throw exception();

		current += n;
	}

	void tank(unsigned int n)
	{
		if (current < n)
			throw exception();

		current -= n;
	}

	unsigned int get_limit() const
	{
		return current;
	}

private:
	unsigned current;
	unsigned capacity;
};

int main()
{
	GasStation s = GasStation(1000); // Колонка на 1000, пока пустая
	s.fill(300); // Это влезет в резервуар,
	cout << s.get_limit() << endl; // ... так что здесь увидим на экране 300.
	s.tank(100); // Забрали из резервуара 100,
	s.fill(300); // ... после чего долили ещё 300,
	cout << s.get_limit() << endl; // ... так что на экране ожидаем 500.
	for(unsigned int i = 0; i < 5; i++) // В цикле забрали 5 раз по 50,
		s.tank(50);
	cout << s.get_limit() << endl; // ... так что на экране ожидаем 250.
	for(unsigned int i = 0; i < 50; i++) { // Теперь пытаемся забрать 50 раз по 100,
		s.tank(100); // из-за чего на третьей попытке ждём exception.
		cout << s.get_limit() << endl;
	}
}


