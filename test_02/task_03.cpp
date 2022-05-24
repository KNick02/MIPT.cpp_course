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
	GasStation s = GasStation(1000); // ������� �� 1000, ���� ������
	s.fill(300); // ��� ������ � ���������,
	cout << s.get_limit() << endl; // ... ��� ��� ����� ������ �� ������ 300.
	s.tank(100); // ������� �� ���������� 100,
	s.fill(300); // ... ����� ���� ������ ��� 300,
	cout << s.get_limit() << endl; // ... ��� ��� �� ������ ������� 500.
	for(unsigned int i = 0; i < 5; i++) // � ����� ������� 5 ��� �� 50,
		s.tank(50);
	cout << s.get_limit() << endl; // ... ��� ��� �� ������ ������� 250.
	for(unsigned int i = 0; i < 50; i++) { // ������ �������� ������� 50 ��� �� 100,
		s.tank(100); // ��-�� ���� �� ������� ������� ��� exception.
		cout << s.get_limit() << endl;
	}
}


