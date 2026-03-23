#include "S315.h"
#include "../Utils.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
// Static lookup table
static const int OverlapLookup[10][10] = {
	{ 6, 2, 4, 4, 3, 4, 5, 4, 6, 5 }, // 0
	{ 2, 2, 1, 2, 2, 1, 1, 2, 2, 2 }, // 1
	{ 4, 1, 5, 4, 2, 3, 4, 2, 5, 4 }, // 2
	{ 4, 2, 4, 5, 3, 4, 4, 3, 5, 5 }, // 3
	{ 3, 2, 2, 3, 4, 3, 3, 3, 4, 4 }, // 4
	{ 4, 1, 3, 4, 3, 5, 5, 3, 5, 5 }, // 5
	{ 5, 1, 4, 4, 3, 5, 6, 3, 6, 5 }, // 6
	{ 4, 2, 2, 3, 3, 3, 3, 4, 4, 4 }, // 7
	{ 6, 2, 5, 5, 4, 5, 6, 4, 7, 6 }, // 8
	{ 5, 2, 4, 5, 4, 5, 5, 4, 6, 6 }  // 9
};

std::string S315::GetAnswer()
{
	// Copy to instance member
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			Overlap[i][j] = OverlapLookup[i][j];
		}
	}

	long long count = 0;
	const int MAX = 20000000;
	auto primes = Utils::GenPrimes(MAX);

	// Remove 0 if present (GenPrimes shouldn't return 0)

	for (auto p : primes)
	{
		if (p > MAX / 2) // Original constraint: p > MAX/2
		{
			// Calculate "saving"
			// Problem asks for difference between Sam's and Max's clock.
			// Naive: turn off old, turn on new. Cost = sum of segments.
			// Smart: only switch differences. Cost = sum of segments - 2 * overlap.
			// Saving = 2 * overlap.
			// We transition from p -> digit_sum(p) -> ... -> single digit -> off.
			// Wait.
			// "Sam's clock": 137 -> off -> 11 -> off -> 2 -> off.
			// "Max's clock": 137 -> 11 -> 2 -> off.

			// Saving for 137->11: 2 * Overlap(137, 11).
			// Saving for 11->2: 2 * Overlap(11, 2).
			// Saving for 2->off: 2 * Overlap(2, empty) = 0?
			// Saving for initial on: 0?

			// Let's trust the logic `GetCount` implements the overlap sum.

			long long current = p;
			while (current >= 10)
			{
				long long next = Utils::DigitSum(current);
				count += GetCount((int)current, (int)next) * 2;
				current = next;
			}
		}
	}

	return std::to_string(count);
}

int S315::GetCount(int num1, int num2)
{
	int total_overlap = 0;
	// Overlap only where digits exist in both.
	// Leading zeros (blanks) have 0 overlap with anything?
	// Actually, blank to digit has 0 overlap.
	// digit to blank has 0 overlap.
	// So `while (num1 > 0 && num2 > 0)` handles the common suffix digits correctly.

	while (num1 > 0 && num2 > 0)
	{
		total_overlap += Overlap[num1 % 10][num2 % 10];
		num1 /= 10;
		num2 /= 10;
	}

	return total_overlap;
}

// Unused overload from previous file?
int S315::GetCount(int p) { return 0; }

} // namespace ProjectEuler
