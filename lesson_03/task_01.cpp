/*
 * task_01.cpp
 *
 *  Created on: 2 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class Train
{
public:
	Train(double m_val) : m(m_val), x(0), v(0) {}

	void move(double dt)
	{
		x += v * dt;
	}

	void accelerate(double dp)
	{
		v += dp / m;
	}

	double getX()
	{
		return x;
	}

private:
	double m, x, v;
};

/*
int main()
{
	Train t(10);
	t.accelerate(1); // Скорость стала 0.1
	t.move(1);
	cout << "Current X: " << t.getX() << endl;
	t.move(1);
	cout << "Current X: " << t.getX() << endl;
	t.accelerate(-2); // Скорость стала -0.1
	t.move(3);
	cout << "Current X: " << t.getX() << endl;
	return 0;
}
*/


/*
	Test output:

	Current X: 0.1
	Current X: 0.2
	Current X: -0.1
 */


