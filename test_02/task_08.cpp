/*
 * task_08.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Event
{
	string action;
	string value;
};

int main()
{
	size_t n, m;
	cin >> n;

	map<unsigned, map<string, Event>> events;
	map<string, string> properties;

	unsigned time;
	string action, property, value;

	for (size_t i = 0; i < n; i++)
	{
		cin >> time >> action >> property;
		if (action == "SET")
			cin >> value;

		events[time][property] = {action, value};
	}

	cin >> m;
	unsigned timestamp;
	for (size_t i = 0; i < m; i++)
	{
		cin >> timestamp;
		properties = {};
		auto events_end = events.lower_bound(timestamp);

		for (auto it = events.begin(); it != events_end; it++)
		{
			for (const auto& item : it -> second)
			{
				if (item.second.action == "SET")
					properties[item.first] = item.second.value;
				else
					properties.erase(item.first);
			}
		}

		for (const auto& item : properties)
			cout << item.first << " : " << item.second << ", ";
		cout << '\n';
	}

	return 0;
}


