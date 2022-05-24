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
	// Конструктор сферы с центром в точке center и радиусом r
	Sphere(const Point& center, double r) : c(center)
{
		this -> r = r;
}

	// Проверка, попадает ли заданная точка p в данную сферу.
	// (Расстояния сравнивать с точностью 1e-6.)
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
	// Создаём сферу
	Point center(10.0, 10.0, 10.0);
	Sphere s(center, 0.5);
	// Создаём пару тестовых точек
	Point p1(10.1, 10.1, 10.1);
	Point p2(2, 2, 2);
	// Ожидаем, что первая точка внутри сферы
	cout << boolalpha << s.covers(p1) << endl;
	// Ожидаем, что вторая точка не попала внутрь сферы
	cout << boolalpha << s.covers(p2) << endl;

	return 0;
}


