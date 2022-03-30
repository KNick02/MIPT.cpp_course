/*
 * task_03.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Coon
{
	unsigned int id;
	char name[100];
	double weight;
	double food;
};

Coon* find_the_most_fed_cat(Coon* atc, unsigned int n_cats)
{
	return max_element(atc, atc + n_cats, [] (Coon a, Coon b)
			{return (a.food / a.weight) < (b.food / b.weight);});
}

int main()
{
	Coon all_the_coons[1000];
	all_the_coons[0] = {0, "first", 3, 4};
	all_the_coons[1] = {1, "second", 5, 4};
	all_the_coons[2] = {2, "third", 4, 4};

	cout << find_the_most_fed_cat(all_the_coons, 3)->name;

	return 0;
}
