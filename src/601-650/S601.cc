#include "S601.h"
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
long long S601::P(int s, long long N)
{
	// P(s, N) implementation using formula
	long long M = 1;
	for (long long i = 1; i <= s; ++i)
	{
		M = std::lcm(M, i);
	}

	if (N <= 1)
	{
		return 0;
	}
	long long max_m = (N - 2) / M;

	long long g = std::gcd(M, (long long)s + 1);
	long long K = (s + 1) / g;

	long long count = max_m - (max_m / K);
	return count;
}

std::string S601::GetAnswer()
{
	long long sum = 0;
	for (int i = 1; i <= 31; ++i)
	{
		long long N = 1LL << (2 * i);
		sum += P(i, N);
	}
	return std::to_string(sum);
}
} // namespace ProjectEuler
