#include "S516.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
int64_t MOD = 4294967296LL; // 2^32

// Helper: Generate 5-smooth numbers
void GenerateSmooths(std::vector<int64_t> &smooths, int64_t limit)
{
	smooths.clear();
	for (int64_t i = 1;;)
	{
		for (int64_t j = i;;)
		{
			for (int64_t k = j;;)
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
				 int64_t currentProduct,
				 const std::vector<int64_t> &specialPrimes,
				 const std::vector<int64_t> &smooths,
				 const std::vector<int64_t> &smoothSums,
				 int64_t MAX,
				 int64_t &totalSum)
{
	// For currentProduct P, we want sum of (P * s) % MOD for all s in smooths with P*s <= MAX.
	// s <= MAX / P.
	// Find largest s <= MAX / P.

	auto it = std::upper_bound(smooths.begin(), smooths.end(), MAX / currentProduct);
	int64_t count = std::distance(smooths.begin(), it);

	// Sum of smooths[0...count-1]
	if (count > 0)
	{
		int64_t sSum = smoothSums[count]; // Sum is mod MOD
		int64_t term = ((currentProduct % MOD) * sSum) % MOD;
		totalSum = (totalSum + term) % MOD;
	}

	// Recurse
	for (size_t i = index; i < specialPrimes.size(); ++i)
	{
		int64_t p = specialPrimes[i];

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
	int64_t MAX = 1000000000000LL; // 10^12

	std::vector<int64_t> smooths;
	GenerateSmooths(smooths, MAX);
	std::sort(smooths.begin(), smooths.end());

	// Special primes p > 5 such that p-1 is 5-smooth
	std::vector<int64_t> specialPrimes;
	for (int64_t s : smooths)
	{
		if (s + 1 > MAX)
		{
			continue;
		}
		int64_t p = s + 1;
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
	std::vector<int64_t> smoothSums(smooths.size() + 1, 0);
	for (size_t i = 0; i < smooths.size(); ++i)
	{
		smoothSums[i + 1] = (smoothSums[i] + (smooths[i] % MOD)) % MOD;
	}

	int64_t totalSum = 0;

	FindSubsets(0, 1, specialPrimes, smooths, smoothSums, MAX, totalSum);

	return std::to_string(totalSum);
}
} // namespace ProjectEuler
