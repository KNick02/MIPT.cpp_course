/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class IncorrectIndexException : virtual public std::exception
{
public:
	IncorrectIndexException(size_t ind, size_t size)
{
		this -> ind = ind;
		this -> size = size;
		error_message = "Index " + to_string(ind) + " is not less than size " + to_string(size);
}

	const char* what() const throw ()
	{
		return error_message.c_str();
	}

protected:
	size_t ind, size;
	string error_message;
};

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
		if (i >= size)
			throw IncorrectIndexException(i, size);

		return data[i];
	}

	void setValue(unsigned int i, int value)
	{
		if (i >= size)
			throw IncorrectIndexException(i, size);

		data[i] = value;
	}

private:
	int* data;
	unsigned int size;
};

int main() {
	unsigned int index;
	std::cin >> index;
	Storage s(42);
	s.setValue(index, 0);
	std::cout << s.getValue(index) << std::endl;
	return 0;
}
