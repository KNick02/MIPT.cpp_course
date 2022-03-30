/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
	size_t N;
	cin >> N;

	double x, y, F;
	double Fx, Fy;

	for (size_t i = 0; i < N; i++)
	{
		cin >> x >> y >> F;
		Fx += F * x / sqrt(x * x + y * y);
		Fy += F * y / sqrt(x * x + y * y);
	}

	cout << fixed << setprecision(4);
	cout << Fx << ' ' << Fy;

	return 0;
}


