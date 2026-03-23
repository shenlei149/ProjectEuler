#include "S14.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
int S14::GetChainLength(long long number)
{
	int length = 1;
	while (number != 1)
	{
		if (number % 2 == 0)
		{
			number /= 2;
		}
		else
		{
			number = 3 * number + 1;
		}

		if (number < 1000000 && termsLength[number] != 0)
		{
			return length + termsLength[number];
		}

		length++;
	}

	return length;
}

std::string S14::GetAnswer()
{
	termsLength = std::vector<int>(1000000);

	int maxLength = 0;
	int maxNumber = 0;
	for (int i = 1; i < 1000000; i++)
	{
		int tempLength = GetChainLength(i);
		termsLength[i] = tempLength;
		if (tempLength > maxLength)
		{
			maxLength = tempLength;
			maxNumber = i;
		}
	}

	return std::to_string(maxNumber);
}

} // namespace ProjectEuler
