/*
 * task_07.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using namespace std;

class Ball
{
public:
	void destroy()
	{
		if (condition > 0 || broken)
			throw exception();

		condition = 2;
		broken = true;
	}

	void lose()
	{
		if (condition > 0 || lost)
			throw exception();

		condition = 1;
		lost = true;
	}

private:
	static bool lost;
	static bool broken;
	char condition = 0;
};
