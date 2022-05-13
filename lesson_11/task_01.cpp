/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <vector>
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
void PrintVector(const vector<T>& v)
{
	for (const auto& item : v)
		cout << item << ' ';
}


int main()
{
	size_t n;
	cin >> n;

	vector<int> v = GetVector<int>(n);

	reverse(v.begin(), v.end());
	PrintVector(v);

	return 0;
}


