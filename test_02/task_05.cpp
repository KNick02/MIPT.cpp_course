/*
 * task_05.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool Comparator(pair<unsigned, string> lhs, pair<unsigned, string> rhs)
{
	if (lhs.first == rhs.first)
		return lhs.second < rhs.second;

	return lhs.first > rhs.first;
}

int main()
{
	size_t n;
	cin >> n;

	map<string, set<string>> strings;
	string input, lower;

	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		lower = "";
		for (char c : input)
			lower += tolower(c);

		strings[lower].insert(input);
	}

	vector<pair<unsigned, string>> sorted;
	for (auto couple : strings)
		sorted.push_back(make_pair(couple.second.size(), couple.first));

	sort(sorted.begin(), sorted.end(), Comparator);

	for (const auto& item : sorted)
		if (item.first > 2)
			cout << item.second << '\n';

	return 0;
}


