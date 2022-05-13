/*
 * task_06.cpp
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
	vector<bool> pos(n);
	for (size_t i = 0; i < n; i++)
		pos[i] = !(v[i] % 2);

	auto even_end = partition(v.begin(), v.end(), [](int item) {return item % 2 == 0;});
	vector<int> even(v.begin(), even_end);
	vector<int> odd(even_end, v.end());

	sort(even.rbegin(), even.rend());
	sort(odd.begin(), odd.end());

	for (size_t i = 0, j = 0, k = 0; i < n; i++)
		v[i] = (pos[i])? (even[j++]) : (odd[k++]);

	cout << v;

	return 0;
}


