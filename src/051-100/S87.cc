#include "S87.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S87::GetAnswer()
{
	const int MAX = 50000000;
	std::set<int> numbers;				 // Use set to keep unique
	auto sieve = Utils::GenPrimes(7500); // Prime limit ~sqrt(50M) = 7071
	std::vector<int> primes;
	for (auto p : sieve)
	{
		if (p != 0)
		{
			primes.push_back((int)p);
		}
	}

	// Primes are sorted.
	// i^2 + j^3 + k^4 < 50,000,000
	// k^4 < 50,000,000 => k < 84
	// j^3 < 50,000,000 => j < 368
	// i^2 < 50,000,000 => i < 7071

	for (int i = 0; i < primes.size(); i++)
	{
		long long p1 = primes[i];
		long long sq = p1 * p1;
		if (sq >= MAX)
		{
			break;
		}

		for (int j = 0; j < primes.size(); j++)
		{
			long long p2 = primes[j];
			long long cb = p2 * p2 * p2;
			if (sq + cb >= MAX)
			{
				break;
			}

			for (int k = 0; k < primes.size(); k++)
			{
				long long p3 = primes[k];
				long long qd = p3 * p3 * p3 * p3;
				if (sq + cb + qd >= MAX)
				{
					break;
				}

				numbers.insert((int)(sq + cb + qd));
			}
		}
	}

	return std::to_string(numbers.size());
}
} // namespace ProjectEuler
