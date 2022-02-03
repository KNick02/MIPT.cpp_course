/*
 * task_06.cpp
 *
 *  Created on: 2 ����. 2022 �.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int main()
{
	int data[MAX_N], n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> data[i];
	cin >> m;

	sort(data, data + n);

	for (int i = n - m; i < n; i++)
		cout << data[i] << ' ';

	return 0;
}




