/*
 * task_06.cpp
 *
 *      Author: Nikolay Kozlovsky
 */
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

bool Comparator(pair<unsigned, string> lhs, pair<unsigned, string> rhs)
{
	if (lhs.first == rhs.first)
		return lhs.second < rhs.second;

	return lhs.first > rhs.first;
}

class ResultsHolder
{
public:
	void update(const std::string& full_name, unsigned mark)
	{
		marks[full_name] = mark;
	}

	void print_students() const
	{
		for (const auto& item : marks)
			cout << item.first << ' ' << item.second << '\n';
	}

	void print_standings() const
	{
		vector<pair<unsigned, string>> sorted;
		for (auto student : marks)
				sorted.push_back(make_pair(student.second, student.first));

		sort(sorted.begin(), sorted.end(), Comparator);
		for (const auto& item : sorted)
			cout << item.second << ' ' << item.first << '\n';
	}

	std::set<std::string> process_military_request(const std::set<std::string>& names)
	{
		set<string> out;
		for (const string& name : names)
		{
			auto it = marks.find(name);
			if (it -> second < 3)
			{
				out.insert(name);
				marks.erase(name);
			}
		}
		return out;
	}

private:
	map<string, unsigned> marks;
};

int main()
{
	// ������� �������
	ResultsHolder rh;
	// ��������� ����������
	rh.update("Alex", 6);
	rh.update("Anny", 5);
	rh.update("Ivan", 10);
	rh.update("Anastasia", 9);
	rh.update("Johnny", 1);
	rh.update("Alex", 7); // ��������� � Alex, ������ �����������
	rh.update("Nikita", 8);
	// ������ � ������� �������� ����������
	std::cout << "Exam results:" << std::endl;
	rh.print_standings();
	// ����������, ��� ��� � �����
	auto to_military_service = rh.process_military_request({"Johnny", "Ivan"});
	// ������ �� �� �����
	std::cout << "Are in army now:" << std::endl;
	for(const auto& s : to_military_service) {
		std::cout << s << std::endl;
	}
	// ������ �� �������� (�� ��� ��� Johnny, �� Ivan ������� � ����)
	std::cout << "Exam results:" << std::endl;
	rh.print_students();

	return 0;
}
