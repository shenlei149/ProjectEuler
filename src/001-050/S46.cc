#include "S46.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S46::GetAnswer()
{
	for (int i = 35;; i += 2)
	{
		if (!IsGoldbachNumber(i))
		{
			return std::to_string(i);
		}
	}
}

bool S46::IsGoldbachNumber(int number)
{
	int length = (int)std::sqrt(number / 2) + 1;
	for (int i = 0; i < length; i++)
	{
		int tmp = number - i * i * 2;
		if (Utils::IsPrime(tmp))
		{
			return true;
		}
	}

	return false;
}

} // namespace ProjectEuler
