/*
 * task_01.cpp
 *
 *  Created on: 9 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	size_t n;
	cin >> n;

	vector<int> temperatures(n);
	vector<size_t> fitting_ind;

	for (auto& item : temperatures)
	{
		cin >> item;
		sum += item;
	}

	int average = sum / n;
	for (size_t i = 0; i < n; i++)
		if (temperatures[i] > average)
			fitting_ind.push_back(i);

	cout << fitting_ind.size() << endl;
	for (const auto& ind : fitting_ind)
		cout << ind << ' ';

	return 0;
}


