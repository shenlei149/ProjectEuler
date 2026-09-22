#include "S71.h"
#include "../Utils.h"
#include <iostream>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S71::GetAnswer()
{
	int64_t bestN = 0;
	int64_t bestD = 1;
	int64_t limit = 1000000;

	// We want n/d just less than 3/7
	// n/d < 3/7  =>  7n < 3d
	// Maximize n/d means minimizing 3/7 - n/d = (3d - 7n) / 7d
	// Smallest positive numerator is 1.
	// 3d - 7n = 1  =>  7n = 3d - 1  =>  n = (3d - 1) / 7
	// Check if integer.
	// Iterate d from 1 to 1,000,000.
	// Calculate max n such that 7n < 3d.
	// n = floor((3d - 1) / 7).
	// Compare n/d with bestN/bestD.

	for (int64_t d = 1; d <= limit; d++)
	{
		if (d == 7)
		{
			continue; // 3/7 itself not allowed? "strictly less"
		}

		int64_t n = (3 * d - 1) / 7;
		if (n * bestD > bestN * d)
		{
			bestN = n;
			bestD = d;
		}
	}

	return std::to_string(bestN);
}
} // namespace ProjectEuler
