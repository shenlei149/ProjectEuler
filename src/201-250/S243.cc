#include "S243.h"
#include "../Utils.h"
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S243::GetAnswer()
{
	auto primes = Utils::GenPrimes(50);
	long long c = 1;
	long long d = 1;
	for (auto p : primes)
	{
		c *= p - 1;
		d *= p;
		if (c * 94744L < d * 15499L)
		{
			break;
		}
	}

	for (int i = 2; i <= primes.back(); i++)
	{
		long long n = d * i;
		if ((__int128)c * n * 94744L < (__int128)d * (n - 1) * 15499L)
		{
			return std::to_string(n);
		}
	}

	return "";
}

} // namespace ProjectEuler
