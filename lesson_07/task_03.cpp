/*
 * task_03.cpp
 *
 *  Created on: 6 апр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <vector>

using namespace std;

class VectorN
{
public:
	VectorN(unsigned int n)
{
		data.resize(n);
}

	~VectorN() {}

	unsigned getSize() const
	{
		return data.size();
	}

	int getValue(unsigned int i) const
	{
		return data[i];
	}

	void setValue(unsigned int i, int value)
	{
		data[i] = value;
	}

	bool operator == (const VectorN& v) const
			{
		for (size_t i = 0; i < getSize(); i++)
			if (data[i] != v.getValue(i))
				return false;

		return true;
			}

	bool operator != (const VectorN& v) const
			{
		return !(*this == v);
			}

	VectorN operator + (const VectorN& v) const
	{
		VectorN result(getSize());
		for (size_t i = 0; i < getSize(); i++)
			result.setValue(i, data[i] + v.getValue(i));
		return result;
	}

	VectorN operator - (const VectorN& v) const
	{
		VectorN result(getSize());
		for (size_t i = 0; i < getSize(); i++)
			result.setValue(i, data[i] - v.getValue(i));
		return result;
	}


	VectorN operator* (const int a) const
	{
		VectorN result(getSize());
		for (size_t i = 0; i < getSize(); i++)
			result.setValue(i, data[i] * a);
		return result;
	}

private:
	vector<int> data;
};

VectorN operator * (const int a, const VectorN& v)
{
	VectorN result(v.getSize());
	for (size_t i = 0; i < v.getSize(); i++)
		result.setValue(i, v.getValue(i) * a);
	return result;
}


int main()
{
	VectorN a(4);
	a.setValue(0, 0);
	a.setValue(1, 1);
	a.setValue(2, 2);
	a.setValue(3, 3);
	VectorN b(4);
	b.setValue(0, 0);
	b.setValue(1, -1);
	b.setValue(2, -2);
	b.setValue(3, -3);

	cout << (a == b) << endl;
	cout << (a != b) << endl;
	VectorN c = a + b;
	VectorN d = 5 * c;
	for(unsigned int i = 0; i < a.getSize(); ++i)
		cout << d.getValue(i) << endl;

	return 0;
}
