/*
 * task_08.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 100

using namespace std;

int main()
{
	int n, m, data[MAX_N][MAX_N];
	int sums[MAX_N] = {0};

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> data[i][j];
			sums[j] += data[i][j];
		}

	int max_sum_ind = 0;
	for (int j = 0; j < m; j++)
		if (sums[j] > sums[max_sum_ind])
			max_sum_ind = j;

	cout << max_sum_ind;

	return 0;
}




