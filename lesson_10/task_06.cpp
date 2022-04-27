/*
 * task_06.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Tracker
{
public:
	void click(const string& username, unsigned long long timestamp)
	{
		clicks[username].insert(timestamp);
	}

	unsigned long long getClickCount(const string& username) const
	{
		auto it = clicks.find(username);
		return (it == clicks.end())? 0 : (it -> second).size();
	}

	unsigned long long getFirstClick(const string& username) const
	{
		auto it = clicks.find(username);
		return (it == clicks.end())? 0 : *((it -> second).begin());
	}

	unsigned long long getLastClick(const string& username) const
	{
		auto it = clicks.find(username);
		return (it == clicks.end())? 0 : *((it -> second).rbegin());
	}

private:
	map<string, set<unsigned long long>> clicks;
};


int main()
{
	Tracker t;
	t.click("alice", 1000);
	t.click("bob", 1100);
	t.click("alice", 1001);
	t.click("alice", 1200);
	t.click("alice", 1002);
	cout << t.getClickCount("alice") << endl;
	cout << t.getClickCount("bob") << endl;
	cout << t.getFirstClick("alice") << endl;
	cout << t.getFirstClick("bob") << endl;
	cout << t.getLastClick("alice") << endl;
	cout << t.getLastClick("bob") << endl;

	return 0;
}
