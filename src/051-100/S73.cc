#include "S73.h"
#include "../Utils.h"
#include <map>

using namespace std;

namespace ProjectEuler
{
std::string S73::GetAnswer()
{
	int count = 0;
	auto primes = Utils::GenPrimeSieve(12001);
	for (int i = 5; i <= 12000; i++)
	{
		// Reduced proper fraction n/d for d=i
		// gcd(n, i) == 1
		// 1/3 < n/i < 1/2  =>  i < 3n  AND  2n < i
		// => n > i/3  AND  n < i/2

		int start = i / 3 + 1;
		int end = (i - 1) / 2;

		auto factors = Utils::Factorize(i, primes);

		for (int n = start; n <= end; n++)
		{
			bool coprime = true;
			for (const auto &[p, exp] : factors)
			{
				if (n % p == 0)
				{
					coprime = false;
					break;
				}
			}

			if (coprime)
			{
				count++;
			}
		}
	}

	return std::to_string(count);
}
} // namespace ProjectEuler
