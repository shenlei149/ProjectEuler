#include "S51.h"
#include "../Utils.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S51::GetAnswer()
{
	std::vector<std::vector<int>> groups(patterns.size());

	auto all_primes = Utils::GenPrimes(1000000);
	std::vector<int> primes;
	for (long long p : all_primes)
	{
		if (p > 100000)
		{
			primes.push_back((int)p);
		}
	}

	for (int p : primes)
	{
		std::string pStr = std::to_string(p);
		for (size_t i = 0; i < patterns.size(); i++)
		{
			std::string pattern = patterns[i];
			std::vector<char> extracted;
			for (size_t j = 0; j < pattern.size(); j++)
			{
				if (pattern[j] == '0')
				{
					extracted.push_back(pStr[j]);
				}
			}

			// We expect 3 replaced digits for 6-digit number?
			// Problem says "part of the number". Patterns in S51.h seem to have three 0s.
			// e.g. "110001".
			// Check if all extracted digits are same
			if (extracted.size() == 3 && extracted[0] == extracted[1] && extracted[1] == extracted[2])
			{
				groups[i].push_back(p);
			}
		}
	}

	for (size_t i = 0; i < patterns.size(); i++)
	{
		auto group = groups[i];
		auto eight = HandleGroup(group, patterns[i]);
		if (eight.size() > 0)
		{
			// Return smallest element of the first family found
			// Primes are sorted by generation order (increasing).
			return std::to_string(eight[0][0]);
		}
	}

	return "";
}

std::vector<std::vector<int>> S51::HandleGroup(std::vector<int> primes, std::string pattern)
{
	std::map<int, std::vector<int>> subGroups;
	for (int p : primes)
	{
		// Construct key from '1' positions
		// We need to match digits at '1' positions.
		// Can construct an integer key or string key.
		// Original logic: iterate backwards, build int.
		// "110001" -> key is digits at 0,1,5.

		std::string s = std::to_string(p);
		int key = 0;
		for (size_t j = 0; j < pattern.size(); j++)
		{
			if (pattern[j] == '1')
			{
				key = key * 10 + (s[j] - '0');
			}
		}

		subGroups[key].push_back(p);
	}

	std::vector<std::vector<int>> result;
	for (const auto &[key, family] : subGroups)
	{
		if (family.size() == 8)
		{
			result.push_back(family);
		}
	}
	return result;
}

} // namespace ProjectEuler
