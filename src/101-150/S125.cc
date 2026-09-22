#include "S125.h"
#include "../Utils.h"
#include <cmath>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S125::GetAnswer()
{
	int64_t limit = 100000000;
	int sqrt_limit = (int)std::sqrt(limit);

	std::set<int64_t> valid_sums;

	for (int i = 1; i <= sqrt_limit; ++i)
	{
		int64_t current_sum = (int64_t)i * i;
		for (int j = i + 1; j <= sqrt_limit; ++j)
		{
			current_sum += (int64_t)j * j;
			if (current_sum >= limit)
			{
				break;
			}

			if (Utils::IsPalindrome(std::to_string(current_sum)))
			{
				valid_sums.insert(current_sum);
			}
		}
	}

	int64_t total = 0;
	for (int64_t s : valid_sums)
	{
		total += s;
	}

	return std::to_string(total);
}

} // namespace ProjectEuler
