/*
 * task_sort.cpp
 *
 *  Created on: 2 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>

#define MAX_N 1000

using namespace std;

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int* FindMinElement(int* array, size_t n)
{
	size_t min_ind = 0;
	for (size_t i = 0; i < n; i++)
		if (array[i] < array[min_ind])
			min_ind = i;

	return array + min_ind;
}

int main()
{
	int n, data[MAX_N];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> data[i];

	// Insertion sort
	for (int i = 0; i < n; i++)
		Swap(data + i, FindMinElement(data + i, n - i));

	// Get pointer to to first non-negative number
	int* first_non_negative = data;
	for (; *first_non_negative < 0; first_non_negative++);

	// Print non-negatives
	for (int* ptr = first_non_negative; ptr < data + n; ptr++)
		cout << *ptr << ' ';

	// Print negatives in descending order
	for (int* ptr = first_non_negative - 1; ptr >= data; ptr--)
		cout << *ptr << ' ';

	return 0;
}



