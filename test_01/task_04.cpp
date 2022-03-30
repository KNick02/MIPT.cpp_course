/*
 * task_04.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point2D
{
protected:
	double _x;
	double _y;
public:
	// Конструктор точки с заданными координатами
	Point2D(double x, double y): _x(x), _y(y) {
	}
	// Получить координату X точки
	double x() const {
		return _x;
	}
	// Получить координату Y точки
	double y() const {
		return _y;
	}
};

class Polygone
{
public:
	Polygone(const std::vector<Point2D>& points)
{
		elements = points;
}

	double area() const
	{
		if (size() == 3)
		{
			Point2D a = vertex(0), b = vertex(1), c = vertex(2);
			double A = sqrt((a.x() - b.x()) * (a.x() - b.x()) +
					(a.y() - b.y()) * (a.y() - b.y()));

			double B = sqrt((c.x() - b.x()) * (c.x() - b.x()) +
					(c.y() - b.y()) * (c.y() - b.y()));

			double C = sqrt((a.x() - c.x()) * (a.x() - c.x()) +
					(a.y() - c.y()) * (a.y() - c.y()));

			double p = (A + B + C) / 2;
			return sqrt(p * (p - A) * (p - B) * (p - C));
		}

		else
		{
			double summ_area = 0;
			for (unsigned i = 1; i + 1 < elements.size(); i++)
			{
				summ_area += Polygone({elements[0], elements[i], elements[i+1]}).area();
			}
			return summ_area;
		}
	}

	unsigned int size() const
	{
		return elements.size();
	}

	Point2D vertex(unsigned int N) const
	{
		return elements.at(N);
	}

private:
	vector<Point2D> elements;
};

/*

int main()
{
	std::vector<Point2D> points = {{-1.0, -1.0}, {-1.0, 1.0},
			{1.0, 1.0}, {1.0, -1.0}};
	Polygone p(points);
	cout << "Points:" << endl;
	for(unsigned int i = 0; i < p.size(); i++) {
		cout << p.vertex(i).x() << " " << p.vertex(i).y() <<
				endl;
	}
	cout << "Area: " << p.area() << endl;
	return 0;
}
*/



