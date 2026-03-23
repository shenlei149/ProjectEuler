#include "S77.h"
#include "../Utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S77::GetAnswer()
{
	int limit = 1000;
	auto sieve = Utils::GenPrimes(limit);
	std::vector<int> primes;
	for (auto p : sieve)
	{
		if (p != 0)
		{
			primes.push_back((int)p);
		}
	}

	std::vector<int> ways(limit + 1, 0);
	ways[0] = 1;

	for (int p : primes)
	{
		for (int i = p; i <= limit; i++)
		{
			ways[i] += ways[i - p];
		}
	}

	for (int i = 0; i <= limit; i++)
	{
		if (ways[i] > 5000)
		{
			return std::to_string(i);
		}
	}

	return "0";
}
} // namespace ProjectEuler
