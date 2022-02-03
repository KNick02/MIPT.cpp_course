/*
 * task_09.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

using namespace std;

struct Vector
{
	int x, y, z;
};

Vector sum(Vector a, Vector b)
{
	return {a.x + b.x,
			a.y + b.y,
			a.z + b.z};
}

/*
const int N = 10;

int main()
{
	Vector res = {0, 0, 0};
	for (int i=0; i<N; i++)
	{
		Vector tmp;
		cin >>tmp.x >>tmp.y >>tmp.z;
		res = sum(res, tmp);
	}
	cout <<res.x <<" " <<res.y <<" " <<res.z <<endl;
	return 0;
}
*/



