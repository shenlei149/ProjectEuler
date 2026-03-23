#include "S22.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace ProjectEuler
{

std::string S22::GetAnswer()
{
	std::vector<std::string> names;
	// Parse comma-separated names
	std::string currentName;
	for (char c : name)
	{
		if (c == ',')
		{
			if (!currentName.empty())
			{
				names.push_back(currentName);
				currentName.clear();
			}
		}
		else if (c != '"' && c != ' ' && c != '\n' && c != '\r')
		{
			currentName += c;
		}
	}
	if (!currentName.empty())
	{
		names.push_back(currentName);
	}

	std::sort(names.begin(), names.end());

	long long total = 0;
	for (size_t i = 0; i < names.size(); i++)
	{
		total += GetStringScore(names[i]) * (i + 1);
	}

	return std::to_string(total);
}

int S22::GetStringScore(std::string name)
{
	int score = 0;
	for (auto item : name)
	{
		score += item - 'A' + 1;
	}

	return score;
}

} // namespace ProjectEuler
