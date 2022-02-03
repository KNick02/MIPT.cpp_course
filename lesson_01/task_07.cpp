/*
 * task_07.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

struct Element
{
	int order;
	int value;
};

int main()
{
	int n, m;
	Element data[MAX_N];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i].value;
		data[i].order = i;
	}
	cin >> m;

	// sort by value
	sort(data, data + n, [](Element lhs, Element rhs) {return lhs.value > rhs.value;});

	// sort by order of input
	sort(data, data + m, [](Element lhs, Element rhs) {return lhs.order < rhs.order;});

	for (int i = 0; i < m; i++)
		cout << data[i].value << ' ';

	return 0;
}




