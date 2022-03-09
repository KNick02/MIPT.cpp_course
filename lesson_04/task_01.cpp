/*
 * task_01.cpp
 *
 *  Created on: 9 мар. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Animal
{
public:
	virtual string getType() = 0;
	virtual bool isDangerous() = 0;

	// virtual ~Animal() {}
};


/*
class Monkey : public Animal
{
public:
	string getType() override
	{
		return "Monkey";
	}

	bool isDangerous() override
	{
		return false;
	}
};

class Lion : public Animal
{
public:
	string getType() override
	{
		return "Lion";
	}

	bool isDangerous() override
	{
		return true;
	}
};
*/


class ZooKeeper
{
public:
	ZooKeeper() {}

	void handleAnimal(Animal* a)
	{
		if (a -> isDangerous())
			dangerous.insert(a -> getType());
	}

	int getDangerousCount()
	{
		return dangerous.size();
	}

private:
	set<string> dangerous;
};


/*
int main()
{
	ZooKeeper z;
	Monkey *m = new Monkey();
	z.handleAnimal(m);
	delete m;
	m = new Monkey();
	z.handleAnimal(m);
	delete m;
	Lion *l = new Lion();
	z.handleAnimal(l);
	delete l;
	cout << z.getDangerousCount() << endl;

	return 0;
}
*/
