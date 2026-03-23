#include "S74.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
static const int Factorials[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int S74::Factorial(int n)
{
	if (n < 10 && n >= 0)
	{
		return Factorials[n];
	}
	return 0;
}

int S74::GetChainLength(int n)
{
	// Check cache
	if (cache.count(n))
	{
		return cache[n];
	}

	std::vector<int> chain;
	chain.push_back(n);
	int curr = n;

	while (true)
	{
		int next = 0;
		int temp = curr;
		if (temp == 0)
		{
			next = 1; // 0! = 1
		}
		else
		{
			while (temp > 0)
			{
				next += Factorial(temp % 10);
				temp /= 10;
			}
		}

		// If next is in cache
		if (cache.count(next))
		{
			int len = chain.size() + cache[next];
			for (size_t i = 0; i < chain.size(); i++)
			{
				cache[chain[i]] = len - i;
			}
			return len;
		}

		// If next is in current chain (cycle)
		for (size_t i = 0; i < chain.size(); i++)
		{
			if (chain[i] == next)
			{
				int cycle_len = chain.size() - i;
				// Cycle nodes
				for (size_t j = i; j < chain.size(); j++)
				{
					cache[chain[j]] = cycle_len;
				}
				// Pre-cycle nodes
				for (size_t j = 0; j < i; j++)
				{
					cache[chain[j]] = (i - j) + cycle_len;
				}

				return cache[n]; // n is chain[0]
			}
		}

		curr = next;
		chain.push_back(curr);

		if (chain.size() > 60)
		{
			// Loop should catch it before this unless cycle is huge
		}
	}
}

std::string S74::GetAnswer()
{
	int count = 0;
	for (int i = 1; i < 1000000; i++)
	{
		if (GetChainLength(i) == 60)
		{
			count++;
		}
	}
	return std::to_string(count);
}
} // namespace ProjectEuler
