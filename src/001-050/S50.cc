#include "S50.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S50::GetAnswer()
{
	int maxCount = 0;
	long long maxPrime = 0;
	auto primes = Utils::GenPrimeSieve(MAX);

	for (int i = 0; i < primes.size(); i++)
	{
		if (primes[i] == 0)
		{
			continue;
		}

		long long sum = 0;
		int count = 0;
		for (int j = i; j < primes.size(); j++)
		{
			if (primes[j] == 0)
			{
				continue;
			}

			sum += primes[j];
			count++;
			if (sum >= MAX)
			{
				break;
			}

			if (primes[sum] != 0)
			{
				if (count > maxCount)
				{
					maxCount = count;
					maxPrime = primes[sum];
				}
			}
		}
	}

	return std::to_string(maxPrime);
}

} // namespace ProjectEuler
