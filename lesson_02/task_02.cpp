/*
 * task_02.cpp
 *
 *  Created on: 16 февр. 2021 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct command
{
	string name;
	int value;
};

size_t worry_count(const vector<bool>& queue)
{
	size_t worried = 0;

	for (bool isWorried : queue)
		worried += isWorried;

	return worried;
}


void worry(vector<bool>& queue, size_t i)
{
	queue[i] = true;
}

void quiet(vector<bool>& queue, size_t i)
{
	queue[i] = false;
}


void come(vector<bool>& queue, int k)
{
	queue.resize(queue.size() + k);
}


int main()
{
	size_t N;
	cin >> N;

	vector<command> commands(N);
	vector<bool> queue = {};

	for (auto& command : commands)
	{
		cin >> command.name;
		if (command.name != "WORRY_COUNT")
			cin >> command.value;
	}

	for (auto command : commands)
	{
		if (command.name == "COME")
			come(queue, command.value);

		else if (command.name == "WORRY")
			worry(queue, command.value);

		else if (command.name == "QUIET")
			quiet(queue, command.value);

		else
		{
			size_t result = worry_count(queue);
			cout << result<< endl;
		}
	}

	return 0;
}
