/*
 * task_04.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

size_t LevenshteinDistance(const string& source, const string& target)
{
    if (source.size() > target.size())
    {
        return LevenshteinDistance(target, source);
    }

    const size_t min_size = source.size(), max_size = target.size();
    std::vector<size_t> lev_dist(min_size + 1);

    for (size_t i = 0; i <= min_size; ++i)
    {
        lev_dist[i] = i;
    }

    for (size_t j = 1; j <= max_size; ++j)
    {
        size_t previous_diagonal = lev_dist[0], previous_diagonal_save;
        ++lev_dist[0];

        for (size_t i = 1; i <= min_size; ++i)
        {
            previous_diagonal_save = lev_dist[i];
            if (source[i - 1] == target[j - 1])
            {
                lev_dist[i] = previous_diagonal;
            }

            else
            {
                lev_dist[i] = min(min(lev_dist[i - 1], lev_dist[i]), previous_diagonal) + 1;
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_dist[min_size];
}

int main()
{
	string A, B;
	cin >> A >> B;
	cout << LevenshteinDistance(A, B);
	return 0;
}

