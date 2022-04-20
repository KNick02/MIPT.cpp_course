/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

size_t A(const string& s, size_t i)
{
	string left, right;
	size_t k = 0;
	for (; k < s.size() && (i + 2 - k) > 0; k++)
	{
		left = s.substr(0, k);
		right = s.substr(i + 1 - k, k);
		reverse(right.begin(), right.end());
		if (left != right)
			return --k;
	}

	return (k == s.size()) ? k : (k - 1);
}

int main()
{
	string s;
	cin >> s;

	for (size_t i = 0; i < s.size(); i++)
		cout << A(s, i) << ' ';

	return 0;
}


