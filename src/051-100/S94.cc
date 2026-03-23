#include "S94.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S94::GetAnswer()
{
	long long perimeters = 0;
	for (long long a = 3; a <= 333333333; a += 2)
	{
		long long c = a + 1;
		if (Meet(a, c))
		{
			perimeters += 2 * a + c;
			continue;
		}

		c = a - 1;
		if (Meet(a, c))
		{
			perimeters += 2 * a + c;
		}
	}

	return std::to_string(perimeters);
}

bool S94::Meet(long long a, long long c)
{
	long long half = c >> 1;
	long long hsquare = half * half;
	long long asquare = a * a;
	long long height = (long long)std::sqrt(asquare - hsquare);
	long long htsquare = height * height;
	return asquare == htsquare + hsquare;
}

} // namespace ProjectEuler
