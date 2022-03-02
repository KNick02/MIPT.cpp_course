/*
 * task_02.cpp
 *
 *  Created on: 2 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class GasHolder
{
public:
	GasHolder(float v) : nu(0), T(273), V(v) {}

	~GasHolder() {}

	void inject(float m, float M)
	{
		nu += m / M;
	}

	void heat(float dT)
	{
		T += dT;
	}

	void cool(float dT)
	{
		T -= dT;
		if (T < 0)
			T = 0;
	}

	float getPressure()
	{
		return nu * 8.31 * T / V;
	}

private:
	float nu, T, V;
};


/*
int main()
{
	GasHolder h(1.0);
	h.inject(29, 29);
	cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
	h.inject(29, 29);
	cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
	h.heat(273);
	cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
	h.cool(373);
	cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
	h.cool(373);
	cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;

	return 0;
}
*/


/*
	Test output:

	Pressure after operation: 2268.63 Pa
	Pressure after operation: 4537.26 Pa
	Pressure after operation: 9074.52 Pa
	Pressure after operation: 2875.26 Pa
*/
