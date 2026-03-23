#include "S57.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S57::GetAnswer()
{
	int count = 0;
	BigInt num(3);
	BigInt den(2);

	for (int i = 1; i <= 1000; i++)
	{
		if (num.toString().length() > den.toString().length())
		{
			count++;
		}

		BigInt nextNum = num + den + den;
		BigInt nextDen = num + den;
		num = nextNum;
		den = nextDen;
	}
	return std::to_string(count);
}
} // namespace ProjectEuler
