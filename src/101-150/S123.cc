#include "S123.h"
#include "../Utils.h"
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S123::GetAnswer()
{
	// Generate primes up to ~300000.
	// The n-th prime ~ n log n. 7037 * log 7037 ~ 63000.
	// Let's generate a safe upper bound.
	auto primes = Utils::GenPrimes(1000000); // Should be plenty.
	// Remove p=0/1 artifacts if GenPrimes returns index based array or use GenPrimes returning vector.
	// GenPrimes returns vector of primes or bool array?
	// Looking at S124 usage: Utils::GenPrimes(100001) returns long long[].
	// Looking at S10.cc or Utils.h...
	// Let's check Utils.h first.

	// In S123.cc previous code: Utils::GenPrimes(1000000).Where(...)
	// So it returns a container.

	// We need 1-based index n. p_n is primes[n-1].

	// Start search from n = 7037 (odd).
	long long n = 7037;
	// Ensure we have enough primes.
	if (primes.size() < n)
	{
		return "Error: Not enough primes generated";
	}

	for (; n <= primes.size(); n += 2)
	{
		long long p = primes[n - 1];
		long long r = (2 * n * p) % (p * p); // r = 2np mod p^2

		if (r > 10000000000LL)
		{
			return std::to_string(n);
		}
	}
	return "0";
}

} // namespace ProjectEuler
