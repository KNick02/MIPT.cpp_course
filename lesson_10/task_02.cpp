/*
 * task_02.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class ResultsTable
{
public:
	void addResult(unsigned int score)
	{
		auto it = upper_bound(scores.begin(), scores.end(), score);
		scores.insert(it, score);
	}

	unsigned int getMinScore() const
	{
		return (scores.begin() == scores.end())? 0 : *(scores.begin());
	}

	unsigned int getScoreForPosition(unsigned int positionNumber) const
	{
		return scores[scores.size() - positionNumber];
	}

private:
	vector<unsigned int> scores;
};

int main()
{
	ResultsTable t;
	t.addResult(30);
	t.addResult(85);
	t.addResult(12);
	t.addResult(31);
	cout << "1st place score: " << t.getScoreForPosition(1) << endl;
	cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
	cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
	cout << "Min score during the tournament: " << t.getMinScore() << endl;
}


