#include "S60.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{

bool S60::IsPrime(long long n) { return Utils::IsPrime(n); }

bool S60::Check(long long a, long long b)
{
	string sa = to_string(a);
	string sb = to_string(b);
	if (!IsPrime(stoll(sa + sb)))
	{
		return false;
	}
	if (!IsPrime(stoll(sb + sa)))
	{
		return false;
	}
	return true;
}

void S60::FindClique(std::vector<int> &clique, int startIdx, const std::vector<int> &primes, int &minSum)
{
	if (clique.size() == 5)
	{
		int sum = 0;
		for (int p : clique)
		{
			sum += p;
		}
		if (sum < minSum)
		{
			minSum = sum;
		}
		return;
	}

	for (size_t i = startIdx; i < primes.size(); i++)
	{
		int p = primes[i];
		// Pruning: if p * (5 - current_size) + current_sum >= minSum, stop
		// (Assuming primes are sorted, next ones will be larger)
		int currentSum = 0;
		for (int c : clique)
		{
			currentSum += c;
		}
		if (currentSum + p * (5 - (int)clique.size()) >= minSum)
		{
			return;
		}

		bool ok = true;
		for (int c : clique)
		{
			if (!Check(c, p))
			{
				ok = false;
				break;
			}
		}

		if (ok)
		{
			clique.push_back(p);
			FindClique(clique, i + 1, primes, minSum);
			clique.pop_back();
		}
	}
}

std::string S60::GetAnswer()
{
	// Generate primes up to some limit.
	// Problem 60 solution usually involves primes < 10000.
	auto primes = Utils::GenPrimes(10000);
	// Remove 2 and 5 (concatenation logic often fails or makes non-primes ending in 2/5)
	// Actually 2 is bad (23 ok, 32 div by 2). 5 bad.
	// 3 is fine (37, 73).
	// Filter out 2 and 5.
	std::vector<int> candidates;
	for (int p : primes)
	{
		if (p != 2 && p != 5)
		{
			candidates.push_back(p);
		}
	}

	int minSum = 2000000000;
	std::vector<int> clique;
	FindClique(clique, 0, candidates, minSum);

	return std::to_string(minSum);
}

} // namespace ProjectEuler
