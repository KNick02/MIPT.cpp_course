/*
 * task_02.cpp
 *
 *  Created on: 6 апр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class Vector2D
{
public:
	// Конструкторы
	Vector2D() {}

	Vector2D(int x_val, int y_val) : x(x_val), y(y_val) {}

	~Vector2D() {}

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}

	void setX(int x_val)
	{
		x = x_val;
	}

	void setY(int y_val)
	{
		y = y_val;
	}

	bool operator == (const Vector2D& v2) const
		{
		return x == v2.getX() && y == v2.getY();
		}

	bool operator!= (const Vector2D& v2) const
		{
		return !(*this == v2);
		}

	Vector2D operator+ (const Vector2D& v2) const
	{
		return {x + v2.getX(), y + v2.getY()};
	}

	Vector2D operator- (const Vector2D& v2) const
	{
		return {x - v2.getX(), y - v2.getY()};
	}

	Vector2D operator* (const int a) const
		{
		return {x * a, y * a};
		}

private:
	int x, y;
};

Vector2D operator* (int a, const Vector2D& v)
{
	return {v.getX() * a, v.getY() * a};
}

// Вывод вектора, ожидается строго в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v)
{
	os << '(' << v.getX() << "; " << v.getY() << ')';
	return os;
}

std::istream& operator>>(std::istream &is, Vector2D &v)
{
	int x, y;
	is >> x >> y;
	v.setX(x);
	v.setY(y);
	return is;
}

/*
int main()
{
	Vector2D v1;

	cin >> v1;
	cout << v1 << endl;
	Vector2D v2;
	cin >> v2;
	cout << v2 << endl;
	cout << boolalpha << (v1 == v2) << endl;
	cout << boolalpha << (v1 != v2) << endl;
	Vector2D v3 = v1 - v2;
	cout << v3 << endl;
	cout << v3 * 42 << endl;
	cout << 42 * v3 << endl;
}
*/
