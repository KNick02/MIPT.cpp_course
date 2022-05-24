/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class Point
{
protected:
	double _x;
	double _y;
	double _z;
public:
	Point(double x, double y, double z): _x(x), _y(y), _z(z) {
	}

	double x() const {
		return _x;
	}
	double y() const {
		return _y;
	}
	double z() const {
		return _z;
	}
};

class Sphere
{
public:
	// ����������� ����� � ������� � ����� center � �������� r
	Sphere(const Point& center, double r) : c(center)
{
		this -> r = r;
}

	// ��������, �������� �� �������� ����� p � ������ �����.
	// (���������� ���������� � ��������� 1e-6.)
	bool covers(const Point& p) const
	{
		return ((p.x() - c.x()) * (p.x() - c.x()) +
				(p.y() - c.y()) * (p.y() - c.y()) +
				(p.z() - c.z()) * (p.z() - c.z())) - r * r < 1e-6;
	}

private:
	double r;
	Point c;
};

int main()
{
	// ������ �����
	Point center(10.0, 10.0, 10.0);
	Sphere s(center, 0.5);
	// ������ ���� �������� �����
	Point p1(10.1, 10.1, 10.1);
	Point p2(2, 2, 2);
	// �������, ��� ������ ����� ������ �����
	cout << boolalpha << s.covers(p1) << endl;
	// �������, ��� ������ ����� �� ������ ������ �����
	cout << boolalpha << s.covers(p2) << endl;

	return 0;
}


