/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Brain {
protected:
	vector<double> data;
	string phrase;
public:
	Brain() {
		data.resize(1000000);
		phrase = "Booyahg Booyahg Booyahg";
	}
	string speak() {
		return phrase;
	}
};

class Goblin
{
public:
	Goblin(Brain* brain, vector<Goblin>& assignment) : army(assignment)
{
		this -> brain = brain;
}

	string speak()
	{
		return brain -> speak();
	}

	~Goblin()
	{
		if (army.size() == 1)
			delete brain;
	}

private:
	Brain* brain;
	vector<Goblin>& army;
};

vector<Goblin> create_goblin_army(unsigned int size)
{
	Brain* b = new Brain();
	vector<Goblin> army(size, {b, army});
	return army;
}

int main()
{
	unsigned int size1 = 1;
	unsigned int size2 = 10;
	vector<Goblin> army1 = create_goblin_army(size1);
	vector<Goblin> army2 = create_goblin_army(size2);
	for(unsigned int i = 0; i < size1; i++) {
		cout << army1[i].speak() << endl;
	}
	for(unsigned int i = 0; i < size2; i++) {
		cout << army2[i].speak() << endl;
	}
	return 0;
}
