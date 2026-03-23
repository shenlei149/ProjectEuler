#include "S12.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S12::GetAnswer()
{
	int triangle = 0;
	int i = 1;
	while (true)
	{
		triangle += i;
		if (GetDivisorsCount(triangle) > 500)
		{
			break;
		}

		i++;
	}

	return std::to_string(triangle);
}

int S12::GetDivisorsCount(int number)
{
	int count = 0;
	int sqrt = (int)std::sqrt(number);
	for (int i = 1; i <= sqrt; i++)
	{
		if (number % i == 0)
		{
			count++;
		}
	}

	if (sqrt * sqrt == number)
	{
		// perfect square
		return count * 2 - 1;
	}
	else
	{
		return count * 2;
	}
}

} // namespace ProjectEuler
