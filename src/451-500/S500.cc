#include "S500.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S500::GetAnswer()
{
	// Target: 500500 factors. 2^500500.
	int target = 500500;
	int64_t MOD = 500500507;

	// We need ~500500 cheapest factors.
	// Costs are p, p^2, p^4, p^8...
	// 500500th prime is around 7.4M.
	int limit = 8000000;
	auto primes = Utils::GenPrimes(limit);

	std::vector<int64_t> costs;
	costs.reserve(primes.size() + 1000);

	for (int64_t p : primes)
	{
		int64_t cost = p;
		costs.push_back(cost);

		// Only need to add higher powers if they are small enough
		// to compete with the largest prime we'll pick (approx 7.4M).
		// 3000^2 = 9M. So if cost < 3000, cost^2 < 9M.
		while (cost <= 3000)
		{
			cost = cost * cost;
			costs.push_back(cost);
		}
	}

	if (costs.size() < target)
	{
		return "Error";
	}

	// Find smallest target elements
	std::nth_element(costs.begin(), costs.begin() + target, costs.end());

	int64_t ans = 1;
	for (int i = 0; i < target; ++i)
	{
		ans = (ans * (costs[i] % MOD)) % MOD;
	}

	return std::to_string(ans);
}
} // namespace ProjectEuler
