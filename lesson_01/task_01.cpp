/*
 * task_01.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 1000

using namespace std;

int main()
{
	int n, ind, data[MAX_N];

	cin >> n;
	for (ind = 0; ind < n; ind++)
		cin >> data[ind];

	for (ind = n - 1; ind >=0; ind--)
		cout << data[ind] << ' ';

	return 0;
}


