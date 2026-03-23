#include "S206.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S206::GetAnswer()
{
	for (long long i = 100000003;;)
	{
		if (HasRightForm(i))
		{
			return std::to_string((i * 10));
		}

		if (i % 10 == 3)
		{
			i += 4;
		}
		else
		{
			i += 6;
		}
	}
}

bool S206::HasRightForm(long long i)
{
	std::string s = std::to_string(i * i);
	return s[2] == '2' && s[4] == '3' && s[6] == '4' && s[8] == '5' && s[10] == '6' && s[12] == '7' && s[14] == '8';
}

} // namespace ProjectEuler
