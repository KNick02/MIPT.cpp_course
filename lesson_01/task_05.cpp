/*
 * task_05.cpp
 *
 *  Created on: 2 ????. 2022 ?.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 10

using namespace std;

int main()
{
	int n, m;
	char c, data[MAX_N][MAX_N];

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			do {cin.get(c);} while (c == '\n');
			data[i][j] = c;
		}

	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
			cout << data[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}



