/*
 * task_02.cpp
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

	vector<int> v1 = GetVector<int>(n);
	vector<int> v2 = GetVector<int>(n);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	cout << ((v1 == v2)? "true" : "false");

	return 0;
}


