#include "S36.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S36::GetAnswer()
{
	int sum = 0;
	for (int i = 1; i < 1000000; i++)
	{
		std::string binary = "";
		int n = i;
		while (n > 0)
		{
			binary += (n % 2 ? '1' : '0');
			n /= 2;
		}

		if (Utils::IsPalindrome(std::to_string(i)) && Utils::IsPalindrome(binary))
		{
			sum += i;
		}
	}

	return std::to_string(sum);
}

} // namespace ProjectEuler
