/*
 * task_05.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <set>

using namespace std;


class SessionManager
{
public:
	void login(const string& username)
	{
		active.insert(username);
	}

	void logout(const string& username)
	{
		active.erase(username);
	}

	int getNumberOfActiveUsers() const
	{
		return active.size();
	}

private:
	set<string> active;
};

int main()
{
	SessionManager m;
	m.login("alice");
	cout << m.getNumberOfActiveUsers() << endl;
	m.login("bob");
	cout << m.getNumberOfActiveUsers() << endl;
	m.login("alice");
	cout << m.getNumberOfActiveUsers() << endl;
	m.logout("whoever");
	cout << m.getNumberOfActiveUsers() << endl;
	m.logout("alice");
	cout << m.getNumberOfActiveUsers() << endl;
	m.logout("bob");
	cout << m.getNumberOfActiveUsers() << endl;
	return 0;
}

