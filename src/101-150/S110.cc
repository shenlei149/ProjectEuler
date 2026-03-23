#include "S110.h"
#include "../BigInt.h"
#include "../Utils.h"
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S110::GetAnswer()
{
	// Initialize min with a large upper bound:
	// Product of primes up to solution.
	// Let's just run once with MaxPower to set a valid min.
	min = 0; // Invalid
	bool first = true;

	// Check with initial powers = 0
	std::vector<int> powers(Primes.size(), 0);
	Check(powers, 0);

	return min.toString();
}

void S110::Check(std::vector<int> power, int index)
{
	if (index == Primes.size())
	{
		long long count = 1;
		for (int item : power)
		{
			count *= (1 + item * 2);
		}

		long long solutions = (count + 1) / 2;

		if (solutions > MAX)
		{
			BigInt n = 1;
			for (size_t i = 0; i < power.size(); ++i)
			{
				if (power[i] > 0)
				{
					n = n * Utils::Pow(Primes[i], power[i]);
				}
			}

			if (min == 0 || n < min)
			{
				min = n;
			}
		}
	}
	else
	{
		for (int i = 0; i <= MaxPower[index]; i++)
		{
			// Pruning: powers should be non-increasing for optimal n
			if (index > 0 && i > power[index - 1])
			{
				break;
			}

			std::vector<int> copy = power;
			copy[index] = i;
			Check(copy, index + 1);
		}
	}
}

} // namespace ProjectEuler
