#include "S491.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
long long Factorial(int n)
{
	long long res = 1;
	for (int i = 2; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

long long CalculatePermutations(const std::vector<int> &digits)
{
	std::map<int, int> counts;
	for (int x : digits)
	{
		counts[x]++;
	}

	long long n = Factorial(digits.size());
	for (const auto &[key, val] : counts)
	{
		if (val > 1)
		{
			n /= Factorial(val);
		}
	}
	return n;
}

// Forward declaration
void Solve(int depth, int startDigit, int currentSum, std::vector<int> &available, long long &count);

std::string S491::GetAnswer()
{
	long long count = 0;
	std::vector<int> available(10, 2);

	Solve(0, 0, 0, available, count);

	return std::to_string(count);
}

// Implementation
void Solve(int depth, int startDigit, int currentSum, std::vector<int> &available, long long &count)
{
	if (depth == 10)
	{
		// Check if currentSum is valid
		bool valid = false;
		if (currentSum == 23 || currentSum == 34 || currentSum == 45 || currentSum == 56 || currentSum == 67)
		{
			valid = true;
		}
		if (!valid)
		{
			return;
		}

		// Reconstruct sets
		std::vector<int> oddSet;
		std::vector<int> evenSet;

		for (int i = 0; i <= 9; ++i)
		{
			int used = 2 - available[i];
			for (int k = 0; k < used; ++k)
			{
				oddSet.push_back(i);
			}
			for (int k = 0; k < available[i]; ++k)
			{
				evenSet.push_back(i);
			}
		}

		long long oddPerms = 0;
		// Odd positions (1,3..19) -> 10 positions.
		// Any permutation of oddSet is valid for the odd positions.
		{
			long long n = 3628800; // 10!
			std::map<int, int> counts;
			for (int x : oddSet)
			{
				counts[x]++;
			}
			for (const auto &[key, val] : counts)
			{
				if (val > 1)
				{
					n /= Factorial(val);
				}
			}
			oddPerms = n;
		}

		long long evenPerms = 0;
		// Even positions (2,4..20). Leading digit is at 20.
		// Leading digit cannot be 0.
		{
			long long n = 3628800; // 10!
			std::map<int, int> counts;
			for (int x : evenSet)
			{
				counts[x]++;
			}
			for (const auto &[key, val] : counts)
			{
				if (val > 1)
				{
					n /= Factorial(val);
				}
			}

			long long totalEven = n;

			// If 0 is in evenSet
			int zeroCount = 0;
			for (int x : evenSet)
			{
				if (x == 0)
				{
					zeroCount++;
				}
			}

			if (zeroCount > 0)
			{
				// Perms starting with 0 = Total * (count(0) / 10)
				long long invalid = totalEven * zeroCount / 10;
				evenPerms = totalEven - invalid;
			}
			else
			{
				evenPerms = totalEven;
			}

			// If leading digit is 0, number is not 20 digits?
			// Wait. Even positions include leading digit (pos 20).
			// Yes, so leading digit must not be 0.
			// We subtracted those cases.

			count += oddPerms * evenPerms;
			return;
		}
	}

	// Loop over choices for current depth
	for (int d = startDigit; d <= 9; ++d)
	{
		if (available[d] > 0)
		{
			// Pruning
			int remaining = 10 - depth - 1;
			int minSum = currentSum + d; // + 0..
			// Smallest possible sum for remaining digits?
			// Actually remaining digits are >= d since we pick in order.
			// Wait, we pick combinations.
			// The remaining digits can be anything >= d.

			int maxSum = currentSum + d + 9 * remaining;
			if (maxSum < 23)
			{
				// If even picking max digits won't reach 23, prune.
				// But we iterate d upwards. So next d will be larger, sum larger.
				// So we can't break. We continue?
				// No, if maxSum < 23, increasing d might help.
			}

			if (minSum > 67)
			{
				break; // If min sum exceeds 67, no point continuing.
			}

			available[d]--;
			Solve(depth + 1, d, currentSum + d, available, count);
			available[d]++;
		}
	}
}
} // namespace ProjectEuler
