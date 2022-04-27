/*
 * task_01.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <vector>
#include <iostream>

using namespace std;

class Task
{
protected:
	int cpuNum;
	int size;

public:
	Task(int cpuNum, int size)
{
		this->cpuNum = cpuNum;
		this->size = size;
	}

	int getCPU() const {
		return cpuNum;
	}

	int getSize() const {
		return size;
	}
};

class Analyzer
{
public:
	Analyzer(int numCores) : load(numCores, 0) {}

	void analyze(const vector<Task>& tasks)
	{
		for (const Task& task : tasks)
			load[task.getCPU()] += task.getSize();
	}

	int getLoadForCPU(int cpuNum)
	{
		return load[cpuNum];
	}

private:
	vector<int> load;
};

int main()
{
	int numberOfCores = 4;
	vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
	Analyzer a(numberOfCores);
	a.analyze(data);
	for(int i = 0; i < numberOfCores; i++)
		cout << a.getLoadForCPU(i) << endl;

	return 0;
}


