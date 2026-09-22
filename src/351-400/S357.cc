#include "S357.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S357::GetAnswer()
{
	// 100,000,000
	int64_t MAX = 100000000;

	// We need to sum n <= 10^8 such that for every divisor d of n, d + n/d is prime.
	// Necessary condition: 1 + n is prime (d=1).
	// So n = p - 1.

	// Generate primes up to MAX + 1.
	auto primes = Utils::GenPrimes(MAX + 1);

	// Fast prime check
	std::vector<bool> isPrime(MAX + 2, false);
	for (int64_t p : primes)
	{
		isPrime[p] = true;
	}

	int64_t sum = 0;

	for (int64_t p : primes)
	{
		int64_t n = p - 1;
		if (n > MAX)
		{
			break;
		}

		bool ok = true;
		// Iterate divisors of n
		for (int64_t d = 1; d * d <= n; ++d)
		{
			if (n % d == 0)
			{
				if (!isPrime[d + n / d])
				{
					ok = false;
					break;
				}
			}
		}

		if (ok)
		{
			sum += n;
		}
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
