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
int64_t S429::PowMod(int64_t p, int e, int64_t m) { return Utils::Pow(p, (int64_t)e, m); }

std::string S429::GetAnswer()
{
	int64_t N = 100000000;
	int64_t MOD = 1000000009;

	auto primes = Utils::GenPrimes(N);

	int64_t ans = 1;

	for (int64_t p : primes)
	{
		int64_t exponent = 0;
		int64_t temp = p;

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

		int64_t expReduced = (2 * exponent) % (MOD - 1);
		int64_t term = Utils::Pow(p, expReduced, MOD);
		term = (term + 1) % MOD;

		ans = (ans * term) % MOD;
	}

	return std::to_string(ans);
}
} // namespace ProjectEuler
