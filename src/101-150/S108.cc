#include "S108.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S108::GetAnswer()
{
	min_n = LLONG_MAX;
	Search(0, 1, 1, 1000, 100);
	return std::to_string(min_n);
}

void S108::Search(int index, long long current_n, long long count, int limit, int max_exponent)
{
	if (index >= (int)primes.size())
	{
		return;
	}

	long long p = primes[index];
	long long next_n = current_n;

	// a is exponent
	for (int a = 1; a <= max_exponent; a++)
	{
		if (min_n != LLONG_MAX && next_n > min_n / p)
		{
			break; // Check overflow
		}
		next_n *= p;

		long long next_count = count * (2 * a + 1);

		if (next_count > 2 * limit - 1)
		{
			if (next_n < min_n)
			{
				min_n = next_n;
			}
			// Since increasing a increases n, we can stop here for this prime
			// Also larger a means larger n, so no need to recurse for larger a
			return;
		}
		else
		{
			// Recurse with non-increasing exponent constraint
			Search(index + 1, next_n, next_count, limit, a);
		}
	}
}
} // namespace ProjectEuler
