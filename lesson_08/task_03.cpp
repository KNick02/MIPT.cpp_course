/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	size_t next_occ = B.find(A, 0);
	if (next_occ == -1)
	{
		cout << -1;
		return 0;
	}

	do
	{
		cout << next_occ++ << ' ';
		next_occ = B.find(A, next_occ);
	} while (next_occ != -1);

	return 0;
}


