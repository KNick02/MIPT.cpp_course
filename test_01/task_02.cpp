/*
 * task_02.cpp
 *
 *      Author: Nikolay Kozlovsky
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	double x;
	double y;
	double z;

	double Distance(const Point& p)
	{
		return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) + (p.z - z) * (p.z - z));
	}
};

int main()
{
	size_t N;
	cin >> N;
	vector<Point> traj(N);

	double current_len = 0, norm;
	int completed = -1;

	for (Point& p : traj)
		cin >> p.x >> p.y >> p.z;

	cin >> norm;

	for (size_t i = 1; i < N; i++)
	{
		current_len += traj[i].Distance(traj[i - 1]);
		if (current_len >= norm)
		{
			completed = i;
			break;
		}
	}

	cout << completed;

	return 0;
}


