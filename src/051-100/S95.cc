#include "S95.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S95::GetAnswer()
{
	const int MAX = 1000000;
	std::vector<int> sum_divisors(MAX + 1, 1);

	// Sieve to find sum of proper divisors
	for (int i = 2; i <= MAX / 2; i++)
	{
		for (int j = 2 * i; j <= MAX; j += i)
		{
			sum_divisors[j] += i;
		}
	}

	int max_chain_len = 0;
	int min_member = 0;

	for (int i = 2; i <= MAX; i++)
	{
		int curr = i;
		std::vector<int> chain;
		bool bad = false;

		while (true)
		{
			chain.push_back(curr);
			int next = 0;
			if (curr <= MAX)
			{
				next = sum_divisors[curr];
			}
			else
			{
				bad = true;
				break;
			}

			if (next > MAX)
			{
				bad = true;
				break;
			}

			if (next == i)
			{
				// Loop closed correctly to start
				if ((int)chain.size() > max_chain_len)
				{
					max_chain_len = chain.size();
					min_member = i;
				}
				break;
			}

			// Check for loop not to start or infinite
			auto it = std::find(chain.begin(), chain.end(), next);
			if (it != chain.end())
			{
				bad = true;
				break;
			}

			curr = next;
		}
	}

	return std::to_string(min_member);
}
} // namespace ProjectEuler
