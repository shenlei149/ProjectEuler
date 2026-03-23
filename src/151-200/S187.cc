#include "S187.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S187::GetAnswer()
{
	auto primes = Utils::GenPrimes(MAX / 2);

	// remove 0 if any
	primes.erase(std::remove(primes.begin(), primes.end(), 0), primes.end());

	long long count = 0;
	for (size_t i = 0; i < primes.size(); ++i)
	{
		long long p = primes[i];
		long long m = (MAX - 1) / p;
		if (m < p)
		{
			break;
		}

		// Find number of primes q such that p <= q <= m.
		// We need index of first element > m.
		auto it = std::upper_bound(primes.begin(), primes.end(), m);

		long long dist = std::distance(primes.begin(), it);
		if (dist > (long long)i)
		{
			count += (dist - i);
		}
	}

	return std::to_string(count);
}

} // namespace ProjectEuler
