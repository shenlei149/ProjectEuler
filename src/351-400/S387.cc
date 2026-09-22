#include "S387.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
// Helper function to check if n is prime
static bool IsPrime(int64_t n);

static void GenerateRTHN(int64_t current, int digitSum, int64_t LIMIT_P, int64_t &totalSum);

// Implementation
static bool IsPrime(int64_t n)
{
	if (n <= 1)
	{
		return false;
	}
	if (n <= 3)
	{
		return true;
	}
	if (n % 2 == 0 || n % 3 == 0)
	{
		return false;
	}
	for (int64_t i = 5; i * i <= n; i = i + 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}

static void GenerateRTHN(int64_t current, int digitSum, int64_t LIMIT_P, int64_t &totalSum)
{
	// current is RTHN by construction.

	// Check if current is Strong
	if (IsPrime(current / digitSum))
	{
		// Try to form P = current * 10 + d
		for (int d : { 1, 3, 7, 9 })
		{
			int64_t p = current * 10 + d;
			if (p >= LIMIT_P)
			{
				continue;
			}
			if (IsPrime(p))
			{
				totalSum += p;
			}
		}
	}

	// Recurse: append digit k
	// Next RTHN check
	if (current >= LIMIT_P / 10)
	{
		return; // Optimization: next = current * 10 + k >= LIMIT_P
	}

	for (int k = 0; k <= 9; ++k)
	{
		int64_t next = current * 10 + k;
		int nextSum = digitSum + k;
		if (next % nextSum == 0)
		{
			GenerateRTHN(next, nextSum, LIMIT_P, totalSum);
		}
	}
}

std::string S387::GetAnswer()
{
	int64_t LIMIT = 100000000000000LL;
	int64_t sum = 0;

	for (int i = 1; i <= 9; ++i)
	{
		GenerateRTHN(i, i, LIMIT, sum);
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
