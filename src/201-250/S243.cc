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
	int64_t c = 1;
	int64_t d = 1;
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
		int64_t n = d * i;
		if ((__int128)c * n * 94744L < (__int128)d * (n - 1) * 15499L)
		{
			return std::to_string(n);
		}
	}

	return "";
}

} // namespace ProjectEuler
