#include "S76.h"
#include "../Utils.h"
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S76::GetAnswer()
{
	std::vector<int> q;
	int iq = 0;
	// Generates generalized pentagonal numbers?
	// Logic from C# seems to fill q with something.
	// But loop condition iq < 10?
	// Let's preserve the logic but fix syntax.
	for (; iq < 100; iq++) // C# code likely had bigger limit?
	{
		// 1, 2, 5, 7, 12, 15...
		// Pentagonal numbers: n(3n-1)/2. Generalized: n=0, 1, -1, 2, -2...
		// My loop: iq=0 -> 0, 0.
		// iq=1 -> 1, 2.
		// iq=2 -> 5, 7.
		if (iq > 0)
		{
			q.push_back(iq * (iq * 3 - 1) / 2);
			q.push_back(iq * (iq * 3 + 1) / 2);
		}
	}
	// Initial p
	std::vector<int> p = { 1, 1, 2 };
	// Target 100
	for (int ip = 3; ip <= 100; ip++)
	{
		int sum = 0;
		int k = 0;
		while (true)
		{
			if (k >= q.size())
			{
				break; // Safety
			}
			int Pent = q[k];
			if (Pent > ip)
			{
				break;
			}

			// Partition function p(n) = sum (-1)^(k-1) p(n - pent_k)
			// Signs: +, +, -, -, +, +, ...
			// k=0 (pent=1): +
			// k=1 (pent=2): +
			// k=2 (pent=5): -
			// k=3 (pent=7): -

			int sign = (k / 2) % 2 == 0 ? 1 : -1;
			sum += sign * p[ip - Pent];
			k++;
		}
		p.push_back(sum);
	}

	return std::to_string(p[100] - 1); // -1 because at least two integers?
}
} // namespace ProjectEuler
