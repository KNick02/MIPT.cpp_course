/*
 * task_07.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


class TelemetryController
{
public:
	void handleEvent(const string& device, long value)
	{
		max_values[device] = max(max_values[device], value);
		min_values[device] = min(min_values[device], value);
		counter[device]++;
	}

	unsigned int getEventsCount(const string& device) const
	{
		auto it = counter.find(device);
		return (it == counter.end())? 0 : (it -> second);
	}

	long getMinValue(const string& device) const
	{
		return min_values.at(device);
	}

	long getMaxValue(const string& device) const
	{
		return max_values.at(device);
	}

private:
	map<string, long> max_values;
	map<string, long> min_values;
	map<string, unsigned int> counter;

};

int main()
{
	TelemetryController tc;
	tc.handleEvent("d1", 42);
	tc.handleEvent("d1", -42);
	tc.handleEvent("d2", 100);
	cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
	cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
	cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;

	return 0;
}


