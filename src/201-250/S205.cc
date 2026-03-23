#include "S205.h"
#include "../Utils.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S205::GetAnswer()
{
	PeterResults.clear();
	ColinResults.clear();

	std::vector<int> Peter(37, 0); // Max sum 4*9 = 36.
	std::vector<int> Colin(37, 0); // Max sum 6*6 = 36.

	GenPeterResults("", 0);
	for (const auto &s : PeterResults)
	{
		long long sum = 0;
		for (char c : s)
		{
			sum += (c - '0');
		}
		if (sum < Peter.size())
		{
			Peter[sum]++;
		}
	}

	GenColinResults("", 0);
	for (const auto &s : ColinResults)
	{
		long long sum = 0;
		for (char c : s)
		{
			sum += (c - '0');
		}
		if (sum < Colin.size())
		{
			Colin[sum]++;
		}
	}

	long long numerator = 0;
	for (size_t p = 1; p < Peter.size(); p++)
	{
		for (size_t c = 1; c < Colin.size(); c++)
		{
			if (p > c)
			{
				numerator += (long long)Peter[p] * Colin[c];
			}
		}
	}

	double result = (double)numerator / 262144.0 / 46656.0;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(7) << result;
	return ss.str();
}

void S205::GenPeterResults(std::string num, int nth)
{
	if (nth == 9)
	{
		PeterResults.push_back(num);
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		GenPeterResults(num + std::to_string(i), nth + 1);
	}
}

void S205::GenColinResults(std::string num, int nth)
{
	if (nth == 6)
	{
		ColinResults.push_back(num);
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		GenColinResults(num + std::to_string(i), nth + 1);
	}
}

} // namespace ProjectEuler
