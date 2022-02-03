/*
 * task_shop.cpp
 *
 *  Created on: 3 февр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

struct Box
{
	unsigned price;
	unsigned number;
};


int main()
{
	Box data[MAX_N];
	size_t n, i, total_candies = 0;
	int s, total_price = 0;

	cin >> n;

	for (size_t i = 0; i < n; i++)
		cin >> data[i].price >> data[i].number;

	cin >> s;

	// sort by price
	sort(data, data + n, [] (Box lhs, Box rhs) {return lhs.price < rhs.price;});

	for (i = 0; i < n && s >= total_price; i++)
	{
		total_price += data[i].price;
		total_candies += data[i].number;
	}

	if (s < total_price)
		total_candies -= data[i - 1].number;

	cout << ((s < total_price)? (i - 1) : n) << ' ' << total_candies;

	return 0;
}



