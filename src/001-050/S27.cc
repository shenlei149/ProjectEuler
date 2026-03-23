#include "S27.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S27::GetAnswer()
{
	std::vector<S27::ABAndMaxPrime> primes;

	for (int a = -999; a < 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			S27::ABAndMaxPrime tmp;
			tmp.A = a;
			tmp.B = b;
			tmp.PrimeCount = 0;

			for (int n = 0;; n++)
			{
				int formula = n * n + a * n + b;
				if (Utils::IsPrime(std::abs(formula)))
				{ // C# implementation might imply checking primality of result
					tmp.PrimeCount++;
				}
				else
				{
					primes.push_back(tmp);
					break;
				}
			}
		}
	}

	S27::ABAndMaxPrime max = { 0, 0, -1 };
	for (const auto &prime : primes)
	{
		if (prime.PrimeCount > max.PrimeCount)
		{
			max = prime;
		}
	}

	return std::to_string(max.A * max.B);
}

} // namespace ProjectEuler
