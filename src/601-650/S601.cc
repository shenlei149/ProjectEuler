#include "S601.h"
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
int64_t S601::P(int s, int64_t N)
{
	// P(s, N) implementation using formula
	int64_t M = 1;
	for (int64_t i = 1; i <= s; ++i)
	{
		M = std::lcm(M, i);
	}

	if (N <= 1)
	{
		return 0;
	}
	int64_t max_m = (N - 2) / M;

	int64_t g = std::gcd(M, (int64_t)s + 1);
	int64_t K = (s + 1) / g;

	int64_t count = max_m - (max_m / K);
	return count;
}

std::string S601::GetAnswer()
{
	int64_t sum = 0;
	for (int i = 1; i <= 31; ++i)
	{
		int64_t N = 1LL << (2 * i);
		sum += P(i, N);
	}
	return std::to_string(sum);
}
} // namespace ProjectEuler
