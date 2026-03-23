#include "S52.h"
#include "../Utils.h"
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S52::GetAnswer()
{
	for (int i = 3; i < 10; i++)
	{
		for (int j = (int)std::pow(10, i) + 2; j < (int)std::pow(10, i + 1) / 6; j += 3)
		{
			if (HasTwoOrThree(j) && HasZeroOrFive(j) && HasMoreThanSix(j) && HasFourOrFiveOrSix(j))
			{
				if (Utils::IsPermutation(j, j * 6) && Utils::IsPermutation(j, j * 5) &&
					Utils::IsPermutation(j, j * 4) && Utils::IsPermutation(j, j * 3) && Utils::IsPermutation(j, j * 2))
				{
					return std::to_string(j);
				}
			}
		}
	}

	return "";
}

bool S52::HasSpecifiedDigit(int number, int spec)
{
	while (number != 0)
	{
		if (number % 10 == spec)
		{
			return true;
		}

		number /= 10;
	}

	return false;
}

bool S52::HasZeroOrFive(int number) { return HasSpecifiedDigit(number, 0) || HasSpecifiedDigit(number, 5); }

bool S52::HasTwoOrThree(int number) { return HasSpecifiedDigit(number, 2) || HasSpecifiedDigit(number, 3); }

bool S52::HasFourOrFiveOrSix(int number)
{
	return HasSpecifiedDigit(number, 4) || HasSpecifiedDigit(number, 5) || HasSpecifiedDigit(number, 6);
}

bool S52::HasMoreThanSix(int number)
{
	return HasSpecifiedDigit(number, 7) || HasSpecifiedDigit(number, 8) || HasSpecifiedDigit(number, 9);
}

} // namespace ProjectEuler
