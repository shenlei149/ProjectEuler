#include "S516.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
long long MOD = 4294967296LL; // 2^32

// Helper: Generate 5-smooth numbers
void GenerateSmooths(std::vector<long long> &smooths, long long limit)
{
	smooths.clear();
	for (long long i = 1;;)
	{
		for (long long j = i;;)
		{
			for (long long k = j;;)
			{
				smooths.push_back(k);
				if (limit / 5 < k)
				{
					break;
				}
				k *= 5;
			}
			if (limit / 3 < j)
			{
				break;
			}
			j *= 3;
		}
		if (limit / 2 < i)
		{
			break;
		}
		i *= 2;
	}
}

// Recursive search for subsets of special primes
void FindSubsets(int index,
				 long long currentProduct,
				 const std::vector<long long> &specialPrimes,
				 const std::vector<long long> &smooths,
				 const std::vector<long long> &smoothSums,
				 long long MAX,
				 long long &totalSum)
{
	// For currentProduct P, we want sum of (P * s) % MOD for all s in smooths with P*s <= MAX.
	// s <= MAX / P.
	// Find largest s <= MAX / P.

	auto it = std::upper_bound(smooths.begin(), smooths.end(), MAX / currentProduct);
	long long count = std::distance(smooths.begin(), it);

	// Sum of smooths[0...count-1]
	if (count > 0)
	{
		long long sSum = smoothSums[count]; // Sum is mod MOD
		long long term = ((currentProduct % MOD) * sSum) % MOD;
		totalSum = (totalSum + term) % MOD;
	}

	// Recurse
	for (size_t i = index; i < specialPrimes.size(); ++i)
	{
		long long p = specialPrimes[i];

		if (MAX / p < currentProduct)
		{
			// Primes are sorted, so we can break early
			break;
		}

		FindSubsets(i + 1, currentProduct * p, specialPrimes, smooths, smoothSums, MAX, totalSum);
	}
}

std::string S516::GetAnswer()
{
	long long MAX = 1000000000000LL; // 10^12

	std::vector<long long> smooths;
	GenerateSmooths(smooths, MAX);
	std::sort(smooths.begin(), smooths.end());

	// Special primes p > 5 such that p-1 is 5-smooth
	std::vector<long long> specialPrimes;
	for (long long s : smooths)
	{
		if (s + 1 > MAX)
		{
			continue;
		}
		long long p = s + 1;
		if (p <= 5)
		{
			continue;
		}
		if (Utils::IsPrime(p))
		{
			specialPrimes.push_back(p);
		}
	}
	std::sort(specialPrimes.begin(), specialPrimes.end());

	// Precompute prefix sums of smooths
	std::vector<long long> smoothSums(smooths.size() + 1, 0);
	for (size_t i = 0; i < smooths.size(); ++i)
	{
		smoothSums[i + 1] = (smoothSums[i] + (smooths[i] % MOD)) % MOD;
	}

	long long totalSum = 0;

	FindSubsets(0, 1, specialPrimes, smooths, smoothSums, MAX, totalSum);

	return std::to_string(totalSum);
}
} // namespace ProjectEuler
