#include "S88.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S88::GetAnswer()
{
	const int Max = 12000;
	std::vector<int> ks(Max + 1, INT_MAX);
	ks[0] = 0;
	ks[1] = 0;

	// Using simple recursion instead of iterative digits which is error prone
	// Function to find product sum numbers
	// product, sum, count, start_factor
	auto search = [&](auto &&self, int product, int sum, int count, int start) -> void
	{
		int k = product - sum + count;
		if (k <= Max)
		{
			if (product < ks[k])
			{
				ks[k] = product;
			}
		}

		// Try adding another factor
		// product * factor <= Max * 2 (heuristic limit, since k = p - s + c, p ~ k + s - c > k)
		// Actually, upper bound for product is somewhat loose, but 2*Max is safe enough for small factors
		// For k=12000, 2*12000 = 24000.
		// Wait, if k is large, product can be large?
		// k = product - sum + count
		// For minimal product-sum, product is usually close to k.
		// For k=12000, 12000 = 12000 * 1^(11999). Sum = 12000 + 11999 = 23999.
		// p - s + c = 12000 - 23999 + 12000 = 1. No.
		// p = 12000. factors {12000, 1...}. sum = 12000 + (k-1). p - s + c = 12000 - (12000+k-1) + k = 1.
		// That's always k for any p?
		// No, k is fixed. We want min p for given k.

		// Recursive search:
		// iterate factor starting from 'start'
		// New product = product * factor
		// New sum = sum + factor
		// New count = count + 1

		// Bound:
		// k = p - s + c. We want to fill ks[k].
		// If p > 2 * Max, then k = p - s + c > p - p + 2 = 2? No.
		// The bound is tricky. But since we want minimal p for k <= 12000,
		// and p >= k always (except for 2*2=4, 2+2=4, k=2, p=4>k).
		// For large k, p is slightly larger than k.
		// Max p we care about is around 24000?

		for (int i = start;; ++i)
		{
			long long next_p = (long long)product * i;
			if (next_p > 2 * Max)
			{
				break; // Heuristic limit
			}

			self(self, (int)next_p, sum + i, count + 1, i);
		}
	};

	// Start with factors >= 2
	search(search, 1, 1, 1, 2);

	// Collect unique values
	std::set<int> unique_sums;
	for (int i = 2; i <= Max; ++i)
	{
		if (ks[i] != INT_MAX)
		{
			unique_sums.insert(ks[i]);
		}
	}

	long long total_sum = 0;
	for (int s : unique_sums)
	{
		total_sum += s;
	}

	return std::to_string(total_sum);
}

} // namespace ProjectEuler
