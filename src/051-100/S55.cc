#include "S55.h"
#include "../Utils.h"
#include <algorithm>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S55::GetAnswer()
{
	int count = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (IsLychrel(i))
		{
			count++;
		}
	}

	return std::to_string(count);
}

bool S55::IsLychrel(BigInt number)
{
	for (int i = 0; i < 50; i++)
	{
		std::string s = number.toString();
		std::reverse(s.begin(), s.end());
		BigInt reversed(s);
		number = number + reversed;

		if (Utils::IsPalindrome(number.toString()))
		{
			return false;
		}
	}

	return true;
}

} // namespace ProjectEuler
