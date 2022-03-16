/*
 * task_02.cpp
 *
 *  Created on: 16 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using std::cout;
using std::endl;

class Storage
{
public:
	Storage(unsigned int n) : size(n)
{
		data = new int[n];
}

	~Storage()
	{
		delete[] data;
	}

	unsigned getSize()
	{
		return size;
	}

	int getValue(unsigned int i)
	{
		return data[i];
	}

	void setValue(unsigned int i, int value)
	{
		data[i] = value;
	}

private:
	int* data;
	unsigned int size;
};

/*

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
	// Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
	int* more_data;

public:
	TestStorage(unsigned int n) : Storage(n) {
		more_data = new int[n];
	}

	~TestStorage() {
		delete[] more_data;
	}
};


int main()
{
	Storage *ts = new TestStorage(42);
	cout << "Storage size: " << ts->getSize() << endl;
	ts -> setValue(1, -4);
	cout << "ts[1] = " << ts -> getValue(1) << endl;
	delete ts;
	return 0;
}
*/
