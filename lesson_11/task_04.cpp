/*
 * task_04.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> GetVector(size_t size)
{
	vector<T> numbers(size);
	for (size_t i = 0; i < size; i++)
		cin >> numbers[i];

	return numbers;
}

template <typename T>
ostream& operator << (ostream& os, set<T>& v)
{
	for (const auto& item : v)
		os << item << ' ';

	return os;
}

template <typename T>
ostream& operator << (ostream& os, vector<T>& v)
{
	for (const auto& item : v)
		os << item << ' ';

	return os;
}

int main()
{
	size_t n;
	cin >> n;

	vector<int> v1 = GetVector<int>(n);
	vector<int> v2 = GetVector<int>(n);
	sort(v2.begin(), v2.end());

	vector<int> intersect;

	set_intersection(v1.begin(), v1.end(),
					v2.begin(), v2.end(),
					back_inserter(intersect));

	cout << intersect;

	return 0;
}


