#include "S34.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S34::GetAnswer()
{
	// Precompute factorials
	factorials = { (int)Utils::Factorial(0), (int)Utils::Factorial(1), (int)Utils::Factorial(2),
				   (int)Utils::Factorial(3), (int)Utils::Factorial(4), (int)Utils::Factorial(5),
				   (int)Utils::Factorial(6), (int)Utils::Factorial(7), (int)Utils::Factorial(8),
				   (int)Utils::Factorial(9) };

	int sum = 0;
	// 2540160 = 9! * 7
	for (int i = 3; i < 2540160; i++)
	{
		if (i == DigitFactorials(i))
		{
			sum += i;
		}
	}

	return std::to_string(sum);
}

int S34::DigitFactorials(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += factorials[n % 10];
		n /= 10;
	}

	return sum;
}

} // namespace ProjectEuler
