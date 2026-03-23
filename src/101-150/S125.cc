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
	long long limit = 100000000;
	int sqrt_limit = (int)std::sqrt(limit);

	std::set<long long> valid_sums;

	for (int i = 1; i <= sqrt_limit; ++i)
	{
		long long current_sum = (long long)i * i;
		for (int j = i + 1; j <= sqrt_limit; ++j)
		{
			current_sum += (long long)j * j;
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

	long long total = 0;
	for (long long s : valid_sums)
	{
		total += s;
	}

	return std::to_string(total);
}

} // namespace ProjectEuler
