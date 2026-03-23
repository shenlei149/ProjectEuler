#include "S61.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S61::GetAnswer()
{
	GenerateNumbers();

	// Start with any number from type 8 (largest set usually smallest count?)
	// Actually, just pick type 8 as the start of the chain since it's a cycle.
	// We can fix the order of types, but the cycle order is unknown.
	// But we can fix the start type to be 8 to avoid permutations of the same cycle.

	// Wait, we need one from EACH type.
	// So we can pick type 8 as the first node in our search.

	for (int n : numbers[8])
	{
		int result = 0;
		if (FindCycle(n, 1, 1 << 8, n, n, result))
		{
			return std::to_string(result);
		}
	}

	return "0";
}

void S61::GenerateNumbers()
{
	numbers.resize(9);

	// P3
	for (int n = 1;; n++)
	{
		int v = n * (n + 1) / 2;
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[3].push_back(v);
		}
	}
	// P4
	for (int n = 1;; n++)
	{
		int v = n * n;
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[4].push_back(v);
		}
	}
	// P5
	for (int n = 1;; n++)
	{
		int v = n * (3 * n - 1) / 2;
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[5].push_back(v);
		}
	}
	// P6
	for (int n = 1;; n++)
	{
		int v = n * (2 * n - 1);
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[6].push_back(v);
		}
	}
	// P7
	for (int n = 1;; n++)
	{
		int v = n * (5 * n - 3) / 2;
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[7].push_back(v);
		}
	}
	// P8
	for (int n = 1;; n++)
	{
		int v = n * (3 * n - 2);
		if (v >= 10000)
		{
			break;
		}
		if (v >= 1000)
		{
			numbers[8].push_back(v);
		}
	}
}

bool S61::FindCycle(int lastValue, int count, int typeMask, int firstValue, int sum, int &result)
{
	if (count == 6)
	{
		// Check if closes cycle
		if (lastValue % 100 == firstValue / 100)
		{
			result = sum;
			return true;
		}
		return false;
	}

	int suffix = lastValue % 100;
	// Need to find next number starting with suffix
	// Iterate through unused types
	for (int t = 3; t <= 7; t++) // type 8 is used first
	{
		if (!((typeMask >> t) & 1))
		{
			for (int nextVal : numbers[t])
			{
				if (nextVal / 100 == suffix)
				{
					if (FindCycle(nextVal, count + 1, typeMask | (1 << t), firstValue, sum + nextVal, result))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}
} // namespace ProjectEuler
