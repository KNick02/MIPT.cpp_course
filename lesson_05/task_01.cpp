/*
 * task_01.cpp
 *
 *  Created on: 16 ���. 2022 �.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>

using std::cout;
using std::endl;


namespace namespaceA
{
class Engine {
public:
	void run() {
		cout << "EngineA run" << endl;
	}
};
}

namespace namespaceB
{
class Engine {
public:

	void run() {
		cout << "EngineB run" << endl;
	}
};
}

namespace namespaceC
{
class Engine {
public:
	void run() {
		cout << "EngineC run" << endl;
	}
};
}



class MyEngine
{
public:
	void run(unsigned int number)
	{
		switch(number)
		{
		case 1:
			engA.run();
			break;
		case 2:
			engB.run();
			break;
		case 3:
			engC.run();
			break;
		}
	}

private:
	namespaceA::Engine engA;
	namespaceB::Engine engB;
	namespaceC::Engine engC;

};


/*
int main()
{
	MyEngine e;
	e.run(1); // ����� run �� Engine-� �� ���������� A
	e.run(2); // ����� run �� Engine-� �� ���������� B
	e.run(3); // ����� run �� Engine-� �� ���������� C
	e.run(10); // ������ �� ����������

	return 0;
}
*/
