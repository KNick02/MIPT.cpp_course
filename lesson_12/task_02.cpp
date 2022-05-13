/*
 * task_02.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>

using namespace std;

class Connector
{
public:
	Connector(const string& address)
	{
	}

	void sendRequest(const string& data)
	{
	}
};


int main()
{
	size_t N;
	cin >> N;

	string adress, data = "HELLO";

	for (size_t i = 0; i < N; i++)
	{
		cin >> adress;
		cout << adress << ": ";

		Connector c(adress);
		try
		{
			c.sendRequest(data);
			cout << "ok\n";
		}
		catch (exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}

	return 0;
}
