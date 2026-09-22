#include "S94.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S94::GetAnswer()
{
	int64_t perimeters = 0;
	for (int64_t a = 3; a <= 333333333; a += 2)
	{
		int64_t c = a + 1;
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

bool S94::Meet(int64_t a, int64_t c)
{
	int64_t half = c >> 1;
	int64_t hsquare = half * half;
	int64_t asquare = a * a;
	int64_t height = (int64_t)std::sqrt(asquare - hsquare);
	int64_t htsquare = height * height;
	return asquare == htsquare + hsquare;
}

} // namespace ProjectEuler
