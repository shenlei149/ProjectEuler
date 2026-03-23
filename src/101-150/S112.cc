#include "S112.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S112::GetAnswer()
{
	int bouncyCount = 0;
	for (int i = 100;; i++)
	{
		if (IsBouncy(i))
		{
			bouncyCount++;
		}

		if (bouncyCount * 100 / i == 99)
		{
			return std::to_string(i);
		}
	}
}

bool S112::IsBouncy(int number)
{
	bool increasing = false;
	bool decreasing = false;

	int second = number % 10;
	number /= 10;
	while (number != 0)
	{
		int first = number % 10;
		number /= 10;

		if (first < second)
		{
			increasing = true;
		}
		else if (first > second)
		{
			decreasing = true;
		}

		if (increasing && decreasing)
		{
			return true;
		}

		second = first;
	}

	return false;
}

} // namespace ProjectEuler
