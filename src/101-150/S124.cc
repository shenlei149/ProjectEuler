#include "S124.h"
#include "../Utils.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
struct NAndRadN
{
	long long N;
	long long Rad;

	// Define < operator for sorting
	bool operator<(const NAndRadN &other) const
	{
		if (Rad != other.Rad)
		{
			return Rad < other.Rad;
		}
		return N < other.N;
	}
};

std::string S124::GetAnswer()
{
	int limit = 100000;
	std::vector<long long> rad(limit + 1, 1);

	// Sieve radicals
	for (int i = 2; i <= limit; i++)
	{
		if (rad[i] == 1) // i is prime
		{
			for (int j = i; j <= limit; j += i)
			{
				rad[j] *= i;
			}
		}
	}

	std::vector<NAndRadN> results;
	results.reserve(limit);

	for (int i = 1; i <= limit; i++)
	{
		results.push_back({ (long long)i, rad[i] });
	}

	// 0-based index. We want E(10000). Index 9999.
	// Wait. Problem says E(n) is the n-th element in sorted list.
	// Yes, index 9999.

	std::sort(results.begin(), results.end());

	return std::to_string(results[9999].N);
}
} // namespace ProjectEuler
