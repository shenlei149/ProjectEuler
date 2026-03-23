#include "S346.h"
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S346::GetAnswer()
{
	// Find all numbers < 10^12 that are repunits in at least two bases.
	// Every number n is a repunit in base n-1 (11 in base n-1 is (n-1)+1 = n).
	// So we just need to find numbers that are repunits in some base b with length >= 3.

	long long MAX = 1000000000000LL;
	std::set<long long> strongRepunits;
	strongRepunits.insert(1); // 1 is repunit in all bases... technically definition says b > 1.

	// 1 + b + b^2 + ... = (b^n - 1) / (b - 1)
	// Smallest is 1 + b + b^2.
	// 1 + b + b^2 < 10^12 => b^2 < 10^12 => b < 10^6.

	long long limit = 1000000LL;

	for (long long b = 2; b < limit; b++)
	{
		long long val = 1 + b + b * b;
		long long term = b * b;

		while (val < MAX)
		{
			strongRepunits.insert(val);

			// Check overflow for next term
			if (MAX / b < term)
			{
				break;
			}
			term *= b;

			if (MAX - term < val)
			{
				break;
			}
			val += term;
		}
	}

	long long sum = 0;
	for (auto x : strongRepunits)
	{
		sum += x;
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
