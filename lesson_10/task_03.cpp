/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Person
{
public:
	Person() {}

	Person(string surname, string name, string middleName)
{
		this -> surname = surname;
		this -> name = name;
		this -> middleName = middleName;
}

	void set_surname(const string& surname)
	{
		this -> surname = surname;
	}

	void set_name(const string& name)
	{
		this -> name = name;
	}

	void set_middleName(const string& middleName)
	{
		this -> middleName = middleName;
	}

	string get_surname() const
	{
		return surname;
	}

	string get_name() const
	{
		return name;
	}

	string get_middleName() const
	{
		return middleName;
	}

	bool operator < (const Person& p)
	{
		if (surname == p.get_surname())
		{
			if (name == p.get_name())
				return middleName < p.get_middleName();

			return name < p.get_name();
		}

		return surname < p.get_surname();
	}

private:
	string surname;
	string name;
	string middleName;
};

istream& operator >> (istream& is, Person& p)
{
	string surname, name, middleName;
	is >> surname >> name >> middleName;
	p.set_surname(surname);
	p.set_name(name);
	p.set_middleName(middleName);

	return is;
}

ostream& operator << (ostream& os, const Person& p)
{
	os << p.get_surname() << ' ' << p.get_name() << ' ' << p.get_middleName();
	return os;
}

int main()
{
	cout << "Testing I/O" << endl;
	Person p;
	cin >> p;
	cout << p << endl;
	cout << "Testing sorting" << endl;
	vector<Person> people;
	people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
	people.push_back(Person("Petrov", "Petr", "Petrovich"));
	people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
	people.push_back(Person("Ivanov", "Petr", "Ivanovich"));
	sort(people.begin(), people.end());
	for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}


