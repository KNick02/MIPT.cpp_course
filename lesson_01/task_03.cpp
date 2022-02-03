/*
 * task_03.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 10

using namespace std;

int main()
{
	int n, data[MAX_N][MAX_N];

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> data[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << data[j][i] << ' ';
		cout << '\n';
	}

	return 0;
}



