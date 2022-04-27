/*
 * task_04.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Animal
{
public:
	virtual string getType() const = 0;
	virtual ~Animal() {}
};

class Monkey : public Animal
{
	string getType() const override
	{
		return "monkey";
	}
};

class Lion : public Animal
{
	string getType() const override
	{
		return "lion";
	}
};

class Cat : public Animal
{
	string getType() const override
	{
		return "cat";
	}
};

class ZooKeeper
{
public:
	ZooKeeper() {}

	void handleAnimal(const Animal& a)
	{
		animals[a.getType()]++;
	}

	int getAnimalCount(const string& type) const
	{
		auto it = animals.find(type);
		return (it == animals.end())? 0 : (it -> second);
	}

private:
	map<string, int> animals;
};

int main()
{
	ZooKeeper z;
	Animal *a = new Monkey();
	z.handleAnimal(*a);
	delete a;
	a = new Monkey();
	z.handleAnimal(*a);
	delete a;
	a = new Lion();
	z.handleAnimal(*a);
	delete a;
	cout << z.getAnimalCount("monkey") << endl;
	cout << z.getAnimalCount("lion") << endl;
	cout << z.getAnimalCount("cat") << endl;

	return 0;
}


