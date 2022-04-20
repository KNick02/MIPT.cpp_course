/*
 * task_02.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	int nShift = -1;
	for (size_t i = 0; i < A.size(); i++)
	{
		if (A == B)
		{
			nShift = i;
			break;
		}

		else
			rotate(A.begin(), A.begin() + 1, A.end());
	}

	cout << nShift;
	return 0;
}


