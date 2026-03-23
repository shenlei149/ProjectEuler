#include "S90.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S90::GetAnswer()
{
	std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto combs = Utils::Combination(digits, 6);

	int count = 0;

	// Check all pairs (i, j)
	for (size_t i = 0; i < combs.size(); ++i)
	{
		for (size_t j = i + 1; j < combs.size(); ++j)
		{ // distinct pairs
			if (Check(combs[i], combs[j]))
			{
				count++;
			}
		}
		// Also check (i, i)? No, distinct dice.
		// Problem says "two cubes". If cubes are identical, it's one arrangement?
		// "How many distinct arrangements of the two cubes allow for all of the square numbers to be displayed?"
		// If dice are identical (e.g. {1,2,3,4,5,6} and {1,2,3,4,5,6}), does it count?
		// Problem says "distinct arrangements of the two cubes".
		// Usually order of dice doesn't matter. (d1, d2) is same as (d2, d1).
		// My loop j = i + 1 handles unique pairs of distinct sets.
		// What if d1 == d2? Can d1 == d2?
		// Yes. Loop j = i handles that.
		// "two cubes".
		// Example: {1, 2, 3, 4, 5, 6} and {1, 2, 3, 4, 5, 6}.
		// If I swap them, it's the same arrangement.
		// So checking j >= i covers all pairs.
		// Wait, j = i is valid? Yes.
	}

	// Actually, let's include j=i.
	// Re-reading problem 90: "How many distinct arrangements of the two cubes..."
	// If I paint {1..6} on cube 1 and {1..6} on cube 2.
	// That is one arrangement.
	// If I paint {1..6} on cube 1 and {0..5} on cube 2.
	// That is another.
	// Is ({1..6}, {0..5}) different from ({0..5}, {1..6})?
	// Usually "two cubes" implies indistinguishable cubes unless specified.
	// "distinct arrangements".
	// If I swap the cubes, the set of faces available is the same.
	// So order doesn't matter.
	// So loop j >= i is correct.

	count = 0;
	for (size_t i = 0; i < combs.size(); ++i)
	{
		for (size_t j = i; j < combs.size(); ++j)
		{
			if (Check(combs[i], combs[j]))
			{
				count++;
			}
		}
	}

	return std::to_string(count);
}

bool S90::Check(const std::vector<int> &d1, const std::vector<int> &d2)
{
	// Squares: 01, 04, 09, 16, 25, 36, 49, 64, 81
	const int squares[][2] = {
		{ 0, 1 },
		  { 0, 4 },
		{ 0, 9 },
		  { 1, 6 },
		{ 2, 5 },
		  { 3, 6 },
		{ 4, 9 },
		  { 6, 4 },
		{ 8, 1 }
	};

	auto hasDigit = [](const std::vector<int> &d, int digit)
	{
		for (int x : d)
		{
			if (x == digit)
			{
				return true;
			}
			if (digit == 6 && x == 9)
			{
				return true;
			}
			if (digit == 9 && x == 6)
			{
				return true;
			}
		}
		return false;
	};

	for (const auto &sq : squares)
	{
		int a = sq[0];
		int b = sq[1];

		bool canForm = (hasDigit(d1, a) && hasDigit(d2, b)) || (hasDigit(d1, b) && hasDigit(d2, a));

		if (!canForm)
		{
			return false;
		}
	}

	return true;
}

} // namespace ProjectEuler
