/*
 * task_02.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 1000

using namespace std;

int main()
{
	int n, ind, sum = 0, data[MAX_N];

	cin >> n;
	for (ind = 0; ind < n; ind++)
	{
		cin >> data[ind];
		sum += data[ind];
	}

	double average = (1.0 * sum) / n;

	for (ind = 0; ind < n; ind++)
		if (data[ind] > average)
			cout << data[ind] << ' ';

	return 0;
}


