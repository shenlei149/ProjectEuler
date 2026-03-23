#include "S329.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S329::GetAnswer()
{
	// Precompute primality up to 500
	vector<bool> is_prime(501, false);
	auto primes_vec = Utils::GenPrimes(500);
	for (long long p : primes_vec)
	{
		if (p <= 500)
		{
			is_prime[p] = true;
		}
	}

	// dp[pos] stores numerator for position `pos`.
	// Common denominator D for all positions.
	vector<long long> dp(501, 1);
	long long D = 1;

	for (int k = 0; k < 15; ++k)
	{
		char croak = croaks[k];

		// Update probabilities based on croak match
		for (int pos = 1; pos <= 500; ++pos)
		{
			bool prime = is_prime[pos];
			// P(croak|pos)
			// If prime: P('P')=2/3, P('N')=1/3
			// If composite: P('P')=1/3, P('N')=2/3

			long long num = 0;
			if (prime)
			{
				num = (croak == 'P' ? 2 : 1);
			}
			else
			{
				num = (croak == 'P' ? 1 : 2);
			}
			// Denom factor 3

			dp[pos] *= num;
		}
		D *= 3;

		if (k < 14) // Jump
		{
			vector<long long> next_dp(501, 0);
			for (int pos = 1; pos <= 500; ++pos)
			{
				// Jumps
				// At 1: jump to 2 (prob 1). Contribution dp[1] * 1.
				// At 500: jump to 499 (prob 1). Contribution dp[500] * 1.
				// At other: jump to pos-1, pos+1 (prob 1/2 each).
				// To keep integer arithmetic, we multiply everything by 2.
				// Then dp[1]*2 goes to next_dp[2].
				// dp[pos]*1 goes to next_dp[pos-1] and next_dp[pos+1].

				if (pos == 1)
				{
					next_dp[2] += dp[1] * 2;
				}
				else if (pos == 500)
				{
					next_dp[499] += dp[500] * 2;
				}
				else
				{
					next_dp[pos - 1] += dp[pos];
					next_dp[pos + 1] += dp[pos];
				}
			}
			dp = next_dp;
			D *= 2;
		}
	}

	long long sum_dp = 0;
	for (int pos = 1; pos <= 500; ++pos)
	{
		sum_dp += dp[pos];
	}

	// Total Probability = (sum_dp / D) / 500
	// = sum_dp / (D * 500)

	long long total_denom = D * 500;
	long long gcd = Utils::GetGcd(sum_dp, total_denom);

	stringstream ss;
	ss << (sum_dp / gcd) << "/" << (total_denom / gcd);
	return ss.str();
}

} // namespace ProjectEuler
