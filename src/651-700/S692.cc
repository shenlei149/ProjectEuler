#include "S692.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S692::GetAnswer()
{
	std::vector<int64_t> nodes = { 1, 2, 3, 5 };
	std::vector<int64_t> diffs = { 0, 1, 1, 2 };
	std::vector<int64_t> sums = { 1, 3, 6, 12 };

	// Target: 23416728348467685
	int64_t target = 23416728348467685LL;

	for (int index = 2;; index++)
	{
		int64_t nextD = nodes[index];
		int64_t nextN = nodes.back() + nextD;

		diffs.push_back(nextD);
		nodes.push_back(nextN);

		// sums[index] is sum G(F_index)?
		// logic copied from original
		int64_t nextSum = sums[sums.size() - 1] + sums[index] - nodes[index] + nextN;
		// Wait, original: `sums[nodes.size() - 2] + ...`
		// nodes was just pushed. So nodes.size()-1 is current index.
		// nodes.size()-2 is previous index (sums.back()).
		// Correct.

		sums.push_back(nextSum);

		if (nextN == target)
		{
			return std::to_string(sums.back());
		}

		if (nextN > target)
		{
			break; // Safety
		}
	}
	return "0";
}
} // namespace ProjectEuler
