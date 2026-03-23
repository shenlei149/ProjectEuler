#include "S719.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S719::GetAnswer()
{
	long long N = 1000000000000LL;	// 10^12
	long long root_limit = 1000000; // sqrt(10^12)

	long long sum = 0;

	// Start from 4 (root=2, sq=4)
	// 1, 4, 9 cannot be split into 2+ parts to sum to root?
	// S(N) definition: "sum of numbers n <= N".
	// Example: sqrt(81)=9. 8+1=9.
	// If n < 10, split is not possible (at least 2 parts).
	// So n >= 10. root >= 4 (sq=16).
	// Actually root=3, sq=9 < 10.
	// So root starts higher.

	for (long long root = 2; root <= root_limit; ++root)
	{
		long long n = root * root;
		if (CanBeSplit(n, root))
		{
			sum += n;
		}
	}

	return std::to_string(sum);
}

bool S719::CanBeSplit(long long n, long long target)
{
	// Recursive check if decimal representation of n can sum to target.
	// n is current number to split.
	// target is remaining sum.

	if (target < 0)
	{
		return false;
	}
	if (n == target)
	{
		// Can we interpret taking the whole number as a split?
		// "split into two or more numbers".
		// So if this is the TOP level call, we cannot return true if n == target.
		// But this recursive function doesn't know depth.
		// However, we call it with n = sq, target = root.
		// Since sq = root^2 > root (for root > 1), n > target.
		// So n == target will never happen at top level.
		// So we can safely return true here (it means we found the last piece).
		return true;
	}
	if (n == 0)
	{
		return target == 0;
	}

	// Try splitting last k digits
	// n % 10, n % 100, etc.
	long long mod = 10;
	while (mod <= n)
	{
		long long part = n % mod;
		long long rest = n / mod;

		if (part <= target && CanBeSplit(rest, target - part))
		{
			return true;
		}

		if (n / mod == 0)
		{
			break; // Avoid infinite loop if n < mod? Wait, mod grows.
		}

		// Check overflow of mod * 10
		if (mod > 2000000000000LL)
		{
			break; // n is up to 10^12
		}
		mod *= 10;
	}

	// Also consider the case where we take the whole n as the last part?
	// Covered by `mod` loop eventually?
	// If n < mod, `part` = n, `rest` = 0.
	// Logic: `mod` goes up to 10^13.
	// `part = n % mod`. If `mod > n`, `part = n`, `rest = 0`.
	// `CanBeSplit(0, target - n)`.
	// `target - n` check.
	// Since `n > target` at top level, this branch will fail at top level, which is correct.
	// At deeper levels, if `n == target`, we return true at start.

	return false;
}
} // namespace ProjectEuler
