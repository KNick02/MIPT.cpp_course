/*
 * task_01.cpp
 *
 *  Created on: 6 апр. 2022 г.
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>


using namespace std;


class Student
{
public:
	void setName(string name)
	{
		this -> name = name;
	}

	void setScore(unsigned int score)
	{
		this -> score = score;
	}

	string getName() const
	{
		return name;
	}

	unsigned int getScore() const
	{
		return score;
	}


private:
	string name;
	unsigned score;
};

istream& operator >> (istream& is, Student& s)
{
	string name;
	getline(is, name);
	s.setName(name);
	return is;
}

ostream& operator << (ostream& os, Student& s)
{
	os << "\'" << s.getName() << "\': " << s.getScore();
	return os;
}

/*

int main()
{
	Student s;
	cin >> s;
	s.setScore(10);
	cout << s << endl;

	return 0;
}
*/
