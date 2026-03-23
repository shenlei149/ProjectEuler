#include "S348.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S348::GetAnswer()
{
	std::map<long long, int> counts;

	// Target: 4 ways to express as square + cube.
	// We need 5 such numbers. Sum them up.

	// We need to iterate squares and cubes.
	// What's the upper bound?
	// 5229225 is one example.
	// Try up to 2 * 10^9 or something.
	// 10^9 square is ~30000. cube is ~1000.

	long long MAX = 1000000000LL;

	// Iterate cubes first?
	// n = a^2 + b^3.

	for (long long b = 2; b * b * b < MAX; ++b)
	{
		long long cube = b * b * b;
		for (long long a = 2;; ++a)
		{
			long long sq = a * a;
			long long sum = sq + cube;
			if (sum >= MAX)
			{
				break;
			}

			if (Utils::IsPalindrome(std::to_string(sum)))
			{
				counts[sum]++;
			}
		}
	}

	long long totalSum = 0;
	int found = 0;

	for (const auto &[val, count] : counts)
	{
		if (count == 4)
		{
			totalSum += val;
			found++;
			if (found == 5)
			{
				break;
			}
		}
	}

	return std::to_string(totalSum);
}
} // namespace ProjectEuler
