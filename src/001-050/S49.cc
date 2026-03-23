#include "S49.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S49::GetAnswer()
{
	auto primes_raw = Utils::GenPrimes(10000);
	std::vector<int> primes;
	for (auto p : primes_raw)
	{
		if (p != 0 && p > 1487)
		{
			primes.push_back((int)p);
		}
	}
	int length = primes.size();

	for (int i = 0; i < length - 2; i++)
	{
		for (int j = i + 1; j < length - 1; j++)
		{
			if (Utils::IsPermutation(primes[i], primes[j]))
			{
				for (int k = j + 1; k < length; k++)
				{
					if (primes[j] * 2 == primes[i] + primes[k] && Utils::IsPermutation(primes[i], primes[k]))
					{
						return std::to_string(primes[i]) + std::to_string(primes[j]) + std::to_string(primes[k]);
					}
				}
			}
		}
	}

	return "";
}

} // namespace ProjectEuler
