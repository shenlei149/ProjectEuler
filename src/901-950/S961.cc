#include "S961.h"

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

namespace ProjectEuler
{

namespace
{

const int NUM_DIGITS = 18;
const int NUMBERS = 1 << NUM_DIGITS;

std::string ToBinaryWithoutLeadingZeros(int num)
{
	std::string result = std::bitset<NUM_DIGITS>(num).to_string();
	result.erase(0, result.find_first_not_of('0'));
	return result;
}

bool Win(const std::string &pattern,
		 const std::unordered_set<std::string> &winPatterns,
		 const std::unordered_set<std::string> &losePatterns)
{
	for (size_t i = 0; i < pattern.size(); ++i)
	{
		std::string newPattern = pattern;
		newPattern.erase(i, 1);
		newPattern.erase(0, newPattern.find_first_not_of('0'));

		if (newPattern.empty())
		{
			return true;
		}

		if (losePatterns.contains(newPattern))
		{
			assert(!winPatterns.contains(newPattern));
			return true;
		}
	}

	return false;
}

} // namespace

std::string ProjectEuler::S961::GetAnswer()
{
	std::vector<std::vector<std::string>> patterns(NUM_DIGITS + 1);
	for (int i = 0; i < NUMBERS; ++i)
	{
		std::string binary = ToBinaryWithoutLeadingZeros(i);
		patterns[binary.size()].push_back(std::move(binary));
	}

	std::unordered_set<std::string> winPatterns;
	std::unordered_set<std::string> losePatterns;

	for (auto &&pattern : patterns)
	{
		for (auto &&binary : pattern)
		{
			if (binary.length() == 0)
			{
				continue;
			}

			if (binary.length() == 1)
			{
				winPatterns.insert(binary);
				continue;
			}

			bool alwaysWin = Win(binary, winPatterns, losePatterns);
			if (alwaysWin)
			{
				winPatterns.insert(binary);
			}
			else
			{
				losePatterns.insert(binary);
			}
		}
	}

	long sum = 0;
	for (auto &&pattern : winPatterns)
	{
		long count = std::count(pattern.begin(), pattern.end(), '1');
		long localSum = 1;
		for (size_t i = 0; i < count; ++i)
		{
			localSum = localSum * 9;
		}

		sum += localSum;
	}

	return std::to_string(sum);
}

} // namespace ProjectEuler
