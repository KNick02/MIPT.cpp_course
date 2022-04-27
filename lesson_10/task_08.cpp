/*
 * task_08.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;


class Connection
{
protected:
	string source;
	unsigned short int port;
	unsigned long long timestamp;
public:
	Connection(string source, unsigned short int port, unsigned long long timestamp) {
		this->source = source;
		this->port = port;
		this->timestamp = timestamp;
	}
	~Connection() {}
	string getSource() const {
		return source;
	}
	unsigned short int getPort() const {
		return port;
	}
	unsigned long long getTimestamp() const {
		return timestamp;
	}
};

class IntrusionDetector
{
public:
	void setTimeThreshold(unsigned short int timeThreshold)
	{
		threshold = timeThreshold;
	}

	void setPortLimit(unsigned short int portLimit)
	{
		limit = portLimit;
	}

	void handleConnection(const Connection& c)
	{
		data[c.getSource()][c.getTimestamp()].insert(c.getPort());
	}

	bool isIntruder(const string& source) const
	{
		auto it = data.find(source);

		if (it == data.end())
			return false;

		auto& requests = it -> second;
		for (auto rng_begin = requests.begin(); rng_begin != requests.end(); rng_begin++)
		{
			auto rng_end = requests.lower_bound(rng_begin -> first + threshold);
			set<unsigned short> ports;

			for (auto port = rng_begin; port != rng_end; port++)
				ports.insert((port -> second).begin(), (port -> second).end());

			if (ports.size() >= limit)
				return true;

			ports.clear();
		}

		return false;
	}

private:
	unsigned short threshold;
	unsigned short limit;
	map<string, map<unsigned short, set<unsigned short>>> data;
};


int main()
{
	IntrusionDetector id;
	id.setTimeThreshold(5);
	id.setPortLimit(3);
	id.handleConnection({"evil.com", 21, 100504});
	id.handleConnection({"evil.com", 22, 100501});
	id.handleConnection({"evil.com", 23, 100502});
	id.handleConnection({"evil.com", 24, 100503});
	id.handleConnection({"evil.com", 25, 100500});
	cout << boolalpha << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") <<
			endl;
	id.handleConnection({"load.com", 80, 100504});
	id.handleConnection({"load.com", 80, 100501});
	id.handleConnection({"load.com", 80, 100502});
	id.handleConnection({"load.com", 80, 100503});
	id.handleConnection({"load.com", 80, 100500});
	cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("load.com") <<
			endl;

	return 0;
}


