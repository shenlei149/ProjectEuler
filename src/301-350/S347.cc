#include "S347.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
int64_t S347::GetM(int64_t p, int64_t q, int64_t MAX)
{
	int64_t best = 0;

	int64_t p_pow = p;
	while (p_pow * q <= MAX)
	{
		int64_t temp = p_pow * q;
		while (temp * q <= MAX)
		{
			temp *= q;
		}
		if (temp > best)
		{
			best = temp;
		}

		if (MAX / p < p_pow)
		{
			break;
		}
		p_pow *= p;
	}
	return best;
}

std::string S347::GetAnswer()
{
	int64_t MAX = 10000000;
	auto primes = Utils::GenPrimes(MAX / 2);

	int64_t sum = 0;
	// Optimization: if p*q > MAX, break inner.
	// If p*2 > MAX, break outer.

	// However, problem says sum of distinct M(p,q,N).
	// Since M(p,q,N) is divisible by p and q only, and <= N.
	// It is unique for the pair {p,q}.
	// And distinct pairs produce distinct numbers (fundamental theorem of arithmetic).
	// So we can sum them directly.

	for (size_t i = 0; i < primes.size(); ++i)
	{
		int64_t p = primes[i];
		if (p * p > MAX)
		{
			break; // Optimization: q > p, so p*q > p*p. If p*p > MAX, then p*q > MAX.
		}

		for (size_t j = i + 1; j < primes.size(); ++j)
		{
			int64_t q = primes[j];
			if (p * q > MAX)
			{
				break;
			}

			sum += GetM(p, q, MAX);
		}
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
