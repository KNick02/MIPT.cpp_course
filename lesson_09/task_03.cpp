/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;


template <typename T>
class Vector2D
{
public:
	// Конструкторы
	Vector2D() {}

	Vector2D(T x_val, T y_val) : x(x_val), y(y_val) {}

	~Vector2D() {}

	T getX() const
	{
		return x;
	}

	T getY() const
	{
		return y;
	}

	void setX(T x_val)
	{
		x = x_val;
	}

	void setY(T y_val)
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

	Vector2D operator* (int a) const
	{
		return {x * a, y * a};
	}

private:
	T x, y;
};

template <typename T, typename M>
Vector2D<T> operator* (M a, const Vector2D<T>& v)
{
	return {v.getX() * a, v.getY() * a};
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v)
{
	os << '(' << v.getX() << "; " << v.getY() << ')';
	return os;
}

template <typename T>
std::istream& operator>>(std::istream &is, Vector2D<T> &v)
{
	T x, y;
	is >> x >> y;
	v.setX(x);
	v.setY(y);
	return is;
}


/*
int main()
{
	Vector2D<int> v1;
	cin >> v1;
	cout << "Read vector: " << v1 << endl;
	cout << "Vector multiplied by 42: " << v1 * 42 << endl;
	Vector2D<double> v2;
	cin >> v2;
	cout << "Read vector: " << v2 << endl;
	cout << "Vector multiplied by 42: " << 42 * v2 << endl;

	return 0;
}
*/

