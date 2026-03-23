#include "S119.h"
#include "../Utils.h"

#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S119::GetAnswer()
{
	std::vector<long long> candidates;
	long long maxVal = LLONG_MAX;
	for (int i = 2; i < 9 * std::to_string(maxVal).size(); i++)
	{
		int power = 2;
		while (true)
		{
			BigInt ret = Utils::Pow(i, power);
			if (ret > BigInt(maxVal))
			{
				break;
			}

			long long number = std::stoll(ret.toString());
			long long sum = Utils::DigitSum(number);
			if (sum == i)
			{
				candidates.push_back(number);
			}

			power++;
		}
	}

	std::sort(candidates.begin(), candidates.end());

	if (candidates.size() <= 29)
	{
		return "0";
	}

	return std::to_string(candidates[29]);
}
} // namespace ProjectEuler
