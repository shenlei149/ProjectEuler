#include "S58.h"
#include "../Utils.h"
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S58::GetAnswer()
{
	int total = 1;
	int primeCount = 0;
	std::vector<int> newNumbers(4);
	for (int k = 1;; k++)
	{
		newNumbers[0] = 4 * k * k - 2 * k + 1;
		newNumbers[1] = 4 * k * k + 4 * k + 1;
		newNumbers[2] = 4 * k * k + 2 * k + 1;
		newNumbers[3] = 4 * k * k + 1;

		total += 4;

		for (int n : newNumbers)
		{
			if (Utils::IsPrime(n))
			{
				primeCount++;
			}
		}

		if (primeCount * 10 < total)
		{
			return std::to_string(2 * k + 1);
		}
	}
}

} // namespace ProjectEuler
