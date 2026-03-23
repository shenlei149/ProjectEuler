#include "S745.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S745::GetAnswer()
{
	long long N = 100000000000000LL; // 10^14
	long long NSqrt = 10000000LL;	 // 10^7
	long long Mod = 1000000007;

	std::vector<long long> counts(NSqrt + 1);

	// Count numbers up to N whose largest square divisor is i^2.
	// Total multiples of i^2 is N/(i^2).
	// But some are multiples of (k*i)^2.
	// Use inclusion-exclusion from top down.

	for (long long i = NSqrt; i >= 2; i--)
	{
		long long count = N / (i * i);
		for (long long j = i * 2; j <= NSqrt; j += i)
		{
			count -= counts[j];
		}

		counts[i] = count;
	}

	// Sum of g(n).
	// g(n) is largest square divisor.
	// If largest square divisor is i^2, we add i^2.
	// We have counts[i] numbers where g(n)=i^2.
	// What about numbers where g(n)=1?
	// sum = Total - Sum(counts[i]).

	long long sum_g1 = N;
	for (int i = 2; i <= NSqrt; i++)
	{
		sum_g1 -= counts[i];
	}
	sum_g1 %= Mod; // g(n)=1 adds 1.

	long long total_sum = sum_g1; // contribution from 1s

	for (long long i = 2; i <= NSqrt; i++)
	{
		long long term = counts[i] % Mod;
		long long sq = (i * i) % Mod;
		total_sum = (total_sum + term * sq) % Mod;
	}

	return std::to_string(total_sum);
}
} // namespace ProjectEuler
