/*
 * task_04.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	vector<int> numbers(n);
	for (size_t i = 0; i < n; i++)
		cin >> numbers[i];

	set<int> num_set;

	for (int n : numbers)
	{
		if (num_set.count(n))
			num_set.erase(n);
		else
			num_set.insert(n);
	}

	auto it = num_set.end();
	advance(it, -1);

	cout << *it;

	return 0;
}


