#include "S872.h"
#include <iostream>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S872::GetAnswer()
{
	long long root = 100000000000000000LL; // 10^17
	long long find = 16677181699666569LL;  // 9^17
	long long sum = root;
	long long diff = root - find;

	// Tree structure:
	// Root n. Children n - 2^k where 2^k < n?
	// Recursive definition of T_n.
	// Path from root to find.
	// If we are at node `current`, and want to reach `target`.
	// `diff = current - target`.
	// We subtract powers of 2.

	// Code logic:
	long long node = root;
	long long diff_level = 1;
	while (diff != 0)
	{
		// Try to subtract diff_level?
		// Condition `diff % 2 == 1`.
		// Looking at bits of diff?
		// If bit is set, we take the branch?

		if (diff % 2 != 0)
		{
			node -= diff_level;
			sum += node;
			// diff -= diff_level?
			// Logic in code: diff /= 2. diff_level *= 2.
			// Wait, if diff is odd, we subtract 1 unit of...
			// diff is scaled down?
			// This logic extracts bits of `root - find`.
			// If k-th bit is set, we add node `root - 2^k - ...`?
			// `node` accumulates subtractions.
			// `sum` adds the nodes on path.

			// Original code:
			// if (diff % 2 == 1) { node -= diff_level; sum += node; break; }
			// Wait, `break` breaks inner while(true)?
			// Inner while(true) loops diff /= 2; diff_level *= 2.
			// So it scans for the next set bit.

			// Let's replicate exact logic.
			// `diff` is reduced.
			// `diff_level` scales up.
			// `node` decreases.
		}

		diff /= 2;
		diff_level *= 2;
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
