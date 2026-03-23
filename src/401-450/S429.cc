#include "S429.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
// Member function to match header?
long long S429::PowMod(long long p, int e, long long m) { return Utils::Pow(p, (long long)e, m); }

std::string S429::GetAnswer()
{
	long long N = 100000000;
	long long MOD = 1000000009;

	auto primes = Utils::GenPrimes(N);

	long long ans = 1;

	for (long long p : primes)
	{
		long long exponent = 0;
		long long temp = p;

		while (true)
		{
			exponent = (exponent + N / temp) % (MOD - 1);
			if (N / p < temp)
			{
				break;
			}
			temp *= p;
		}

		// p^(2*exponent) % MOD
		// 2*exponent can be large, but we use PowMod with MOD-1?
		// No, Fermat's Little Theorem applies if MOD is prime.
		// MOD = 1000000009 is prime.
		// So exponent reduces modulo MOD-1.

		long long expReduced = (2 * exponent) % (MOD - 1);
		long long term = Utils::Pow(p, expReduced, MOD);
		term = (term + 1) % MOD;

		ans = (ans * term) % MOD;
	}

	return std::to_string(ans);
}
} // namespace ProjectEuler
