/*
 * task_05.cpp
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

	vector<int> v = GetVector<int>(n);

	int k;
	cin >> k;

	auto new_end = remove_if(v.begin(), v.end(), [k](int item){return item > k;});

	v.erase(new_end, v.end());
	cout << v;

	return 0;
}


