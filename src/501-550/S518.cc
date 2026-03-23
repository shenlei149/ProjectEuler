#include "S518.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
string S518::GetAnswer()
{
	int LIMIT = 100000000;

	// Fast prime check using sieve
	vector<bool> isPrime(LIMIT, false);
	// Utils::GenPrimes returns vector<long long> or int. Assuming long long based on previous context.
	auto primes = Utils::GenPrimes(LIMIT);
	for (auto p : primes)
	{
		isPrime[p] = true;
	}

	long long sum = 0;

	// We look for geometric progression a+1, b+1, c+1 where a,b,c are primes < LIMIT.
	// Let x = a+1, y = b+1, z = c+1.
	// y^2 = x*z. x,y,z < LIMIT+1.
	// Let x = n*v^2, y = n*u*v, z = n*u^2 with gcd(u,v)=1 and u>v.

	// Iterate u, v such that z < LIMIT
	// z = n*u^2 < LIMIT => u < sqrt(LIMIT)

	for (long long u = 1; u * u < LIMIT; ++u)
	{
		for (long long v = 1; v < u; ++v)
		{
			if (std::gcd(u, v) == 1)
			{
				// z = n*u^2 < LIMIT
				// n < LIMIT / u^2
				long long n_limit = (LIMIT - 1) / (u * u);

				for (long long n = 1; n <= n_limit; ++n)
				{
					long long x = n * v * v;
					long long y = n * u * v;
					long long z = n * u * u;

					// Primes are >= 2, so x,y,z >= 3.
					// However, geometric progression usually implies distinct terms, so u > v implies x < y < z.
					// And if a,b,c are primes, x,y,z must be >= 3.

					if (x - 1 < 2)
					{
						continue; // a = x-1 must be prime >= 2.
					}

					if (isPrime[x - 1] && isPrime[y - 1] && isPrime[z - 1])
					{
						sum += (x - 1) + (y - 1) + (z - 1);
					}
				}
			}
		}
	}

	return to_string(sum);
}
} // namespace ProjectEuler
