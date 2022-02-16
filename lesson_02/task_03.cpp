/*
 * task_03.cpp
 *
 *  Created on: 16 февр. 2021 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Day
{
	vector<string> affairs;
	size_t num_affairs;
};


int main()
{
	size_t Q;
	cin >> Q;

	string command, affair_name;
	size_t day_num, month = 0;

	vector<size_t> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<Day> list(days_in_month[month]);

	for (size_t i = 0; i < Q; i++)
	{
		cin >> command;

		if (command == "NEXT")
		{
			month = (month + 1) % 12;
			if (list.size() > days_in_month[month])
			{
				vector<string>& reassign = list[days_in_month[month] - 1].affairs;
				for (size_t day = list.size() - 1; day > days_in_month[month] - 1; day--)
				{
					reassign.insert(reassign.end(), list[day].affairs.begin(), list[day].affairs.end());
					list[days_in_month[month] - 1].num_affairs += list[day].num_affairs;
				}
			}

			list.resize(days_in_month[month]);
		}

		else if (command == "DUMP")
		{
			cin >> day_num;

			cout << list[day_num - 1].num_affairs << " ";
			for (string affair : list[day_num - 1].affairs)
				cout << affair << " ";
			cout << endl;
		}

		else
		{
			cin >> day_num >> affair_name;
			list[day_num - 1].affairs.push_back(affair_name);
			list[day_num - 1].num_affairs++;
		}
	}

	return 0;
}

