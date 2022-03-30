/*
 * task_05.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const unsigned short int RUB = 0;
const unsigned short int USD = 1;
const unsigned short int NCC = 2;


class ATM
{
public:
	ATM() : cash(3) {}

	void deposit(const std::vector<unsigned int>& notes,
			unsigned short int currency)
	{
		cash[currency].insert(cash[currency].end(), notes.begin(), notes.end());
	}

	vector<unsigned int> withdraw_large(unsigned int
			amount, unsigned short int currency)
	{
		vector<unsigned> result;
		vector<unsigned>& notes = cash[currency];
		sort(notes.rbegin(), notes.rend());

		unsigned current_sum = 0;

		size_t i = 0;
		while (current_sum < amount && i < notes.size())
		{
			if (current_sum + notes[i] <= amount)
			{
				current_sum += notes[i];
				result.push_back(notes[i]);
				notes.erase(notes.begin() + i);
			}

			i++;
		}

		if (current_sum == amount)
			return result;
		else
			return {};
	}

	std::vector<unsigned int> withdraw_small(unsigned int
			amount, unsigned short int currency)
	{
		vector<unsigned> result;
		vector<unsigned> notes = cash[currency];
		sort(notes.begin(), notes.end());

		unsigned current_sum = 0;

		size_t i = 0;
		while (current_sum < amount && i < notes.size())
		{
			current_sum += notes[i];
			result.push_back(notes[i]);
			notes.erase(notes.begin() + i);
		}

		if (current_sum == amount)
		{
			cash[currency] = notes;
			return result;
		}

		else
			return {};
	}

	unsigned int check_reserve(unsigned short int currency)
	{
		unsigned sum = 0;
		vector<unsigned>& available_cash = cash[currency];

		for (const auto& note : available_cash)
			sum += note;

		return sum;
	}

private:
	vector<vector<unsigned>> cash;
};

int main()
{
	vector<unsigned int> rubles = {50, 100, 100, 500, 50,
			1000, 100, 100, 1000, 5000};
	vector<unsigned int> dollars = {100, 100, 100};
	vector<unsigned int> nuka_cola_caps = {1, 1, 1, 1, 1};
	ATM atm;
	atm.deposit(rubles, RUB);
	atm.deposit(dollars, USD);
	atm.deposit(nuka_cola_caps, NCC);
	cout << "Reserves: " << endl;
	for(unsigned short int code = 0; code <= 2; code++) {
		cout << "Currency " << code << ": " <<
				atm.check_reserve(code) << endl;
	}
	vector<unsigned int> result;
	result = atm.withdraw_large(1000, RUB);
	cout << "Asked withdraw_large for 1000 RUB, got " <<
			result.size() << " banknotes" << endl;
	result = atm.withdraw_small(1000, RUB);
	cout << "Asked withdraw_small for 1000 RUB, got " <<
			result.size() << " banknotes" << endl;
	result = atm.withdraw_small(1000, USD);
	cout << "Asked withdraw_small for 1000 USD, got " <<
			result.size() << " banknotes" << endl;
	result = atm.withdraw_large(3, NCC);
	cout << "Asked withdraw_large for 3 NCC, got " <<
			result.size() << " banknotes" << endl;
	cout << "Reserves: " << endl;
	for(unsigned short int code = 0; code <= 2; code++) {
		cout << "Currency " << code << ": " <<
				atm.check_reserve(code) << endl;}
	return 0;
}

