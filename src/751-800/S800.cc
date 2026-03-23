#include "S800.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S800::GetAnswer()
{
	// 800800^800800
	int M_int = 800800;
	// Limit: C = M log M.
	// log(p^q * q^p) = q log p + p log q <= C.
	// We find pairs (p, q) with p < q such that q log p + p log q <= C.

	// Max prime q?
	// If p=2, q log 2 + 2 log q <= C.
	// q log 2 <= C.
	// q <= C / log 2.
	// C = 800800 * log(800800).
	// log(800800) ~ 13.59.
	// C ~ 1.08e7.
	// q <= 1.08e7 / 0.693 ~ 1.57e7.
	// So we sieve primes up to 1.6e7.

	int sieve_limit = 16000000;
	auto primes_long = Utils::GenPrimes(sieve_limit);
	std::vector<int> primes;
	for (auto p : primes_long)
	{
		primes.push_back((int)p);
	}

	double C = M_int * std::log(M_int);

	// Precompute logs
	std::vector<double> logs(primes.size());
	for (size_t i = 0; i < primes.size(); ++i)
	{
		logs[i] = std::log(primes[i]);
	}

	long long count = 0;

	// Two pointers
	// Left p_idx, Right q_idx.
	// For fixed p, find max q.

	int left = 0;
	int right = primes.size() - 1;

	while (left < right)
	{
		long long p = primes[left];
		double log_p = logs[left];

		while (left < right)
		{
			long long q = primes[right];
			double log_q = logs[right];

			if (q * log_p + p * log_q <= C)
			{
				// q works. All primes between left and right also work?
				// Yes, because function is monotonic in q.
				// If q works, smaller primes work.
				// Range [left+1, right].
				count += (right - left);
				break;
			}
			else
			{
				right--;
			}
		}
		left++;
	}

	return std::to_string(count);
}
} // namespace ProjectEuler
