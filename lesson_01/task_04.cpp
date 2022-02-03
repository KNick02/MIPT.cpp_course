/*
 * task_04.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 10

using namespace std;

int main()
{
	int n, m, data[MAX_N][MAX_N];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> data[i][j];

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
			cout << data[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}



