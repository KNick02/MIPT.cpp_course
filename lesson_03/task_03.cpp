/*
 * task_03.cpp
 *
 *  Created on: 2 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <vector>

using namespace std;

class SpacePort
{
public:
	SpacePort(unsigned int size)
{
		docks.assign(size, 0);
}

	bool requestLanding(unsigned int dockNumber)
	{
		if (dockNumber >= docks.size() || docks[dockNumber])
			return false;

		return (docks[dockNumber] = true);
	}

	bool requestTakeoff(unsigned int dockNumber)
	{
		if (dockNumber >= docks.size() || !docks[dockNumber])
			return false;

		return !(docks[dockNumber] = false);
	}

private:
	vector<bool> docks;

};

/*int main()
{
	SpacePort s(5);
	cout << boolalpha << s.requestLanding(0) << endl;
	cout << boolalpha << s.requestLanding(4) << endl;
	cout << boolalpha << s.requestLanding(5) << endl;
	cout << boolalpha << s.requestTakeoff(0) << endl;
	cout << boolalpha << s.requestTakeoff(4) << endl;
	cout << boolalpha << s.requestTakeoff(5) << endl;

	return 0;
}*/

/*
	Test output:

	true
	true
	false
	true
	true
	false
 */
