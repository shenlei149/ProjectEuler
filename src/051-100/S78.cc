#include "S78.h"
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S78::GetAnswer()
{
	const int MOD = 1000000;
	std::vector<int> p;
	p.push_back(1); // p[0] = 1

	std::vector<int> pentagonal;
	// Precompute enough generalized pentagonal numbers
	// k(3k-1)/2 for k = 1, -1, 2, -2, ...
	for (int k = 1; k < 250; ++k)
	{
		pentagonal.push_back(k * (3 * k - 1) / 2);
		pentagonal.push_back(k * (3 * k + 1) / 2); // This corresponds to -k
	}

	int n = 1;
	while (true)
	{
		int pn = 0;
		int k = 0;

		while (k < pentagonal.size())
		{
			int gk = pentagonal[k];
			if (gk > n)
			{
				break;
			}

			// Sign pattern: +, +, -, -, +, +, ...
			// indices 0, 1 -> +
			// indices 2, 3 -> -
			// indices 4, 5 -> +
			if ((k / 2) % 2 == 0)
			{
				pn = (pn + p[n - gk]) % MOD;
			}
			else
			{
				pn = (pn - p[n - gk] + MOD) % MOD;
			}
			k++;
		}

		if (pn == 0)
		{
			return std::to_string(n);
		}
		p.push_back(pn);
		n++;
	}
	return "0";
}
} // namespace ProjectEuler
