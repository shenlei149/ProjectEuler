#include "S30.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S30::GetAnswer()
{
	int sum = 0;
	for (int i = 2; i < 999999; i++)
	{
		if (IsPowerNumber(i, 5))
		{
			sum += i;
		}
	}

	return std::to_string(sum);
}

bool S30::IsPowerNumber(int number, int power)
{
	int originalNumber = number;
	int powerSum = 0;
	while (number != 0)
	{
		powerSum += (int)std::pow(number % 10, power);
		number /= 10;
	}

	return powerSum == originalNumber;
}

} // namespace ProjectEuler
