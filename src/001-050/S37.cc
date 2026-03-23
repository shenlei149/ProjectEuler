#include "S37.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S37::GetAnswer()
{
	int count = 0;
	std::vector<int> truncatablePrimes;

	for (int i = 11;; i += 2)
	{
		if (IsTruncatablePrimes(i))
		{
			truncatablePrimes.push_back(i);
			count++;
		}

		if (count == 11)
		{
			break;
		}
	}

	long long sum = 0;
	for (auto p : truncatablePrimes)
	{
		sum += p;
	}
	return std::to_string(sum);
}

bool S37::IsTruncatablePrimes(int number)
{
	if (!Utils::IsPrime(number))
	{
		return false;
	}
	else
	{
		int left = number / 10;
		while (left != 0)
		{
			if (!Utils::IsPrime(left))
			{
				return false;
			}

			left /= 10;
		}

		std::string right = std::to_string(number);
		while (true)
		{
			right = right.substr(1);
			if (right.size() == 0)
			{
				break;
			}
			if (!Utils::IsPrime(std::stoll(right)))
			{
				return false;
			}
		}

		return true;
	}
}

} // namespace ProjectEuler
