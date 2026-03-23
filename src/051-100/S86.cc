#include "S86.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S86::GetAnswer()
{
	int count = 0;
	int a = 2;
	while (count < 1000000)
	{
		a++;
		count += GetCountByA(a);
	}

	return std::to_string(a);
}

int S86::GetCountByA(int a)
{
	int count = 0;
	for (int bc = 2; bc <= 2 * a; bc++)
	{
		int slope = (int)std::sqrt(a * a + bc * bc);
		if (a * a + bc * bc == slope * slope)
		{
			int bStart = bc % 2 == 0 ? bc / 2 : bc / 2 + 1;
			int bEnd = std::min(a, bc - 1);
			count += bEnd - bStart + 1;
		}
	}

	return count;
}

} // namespace ProjectEuler
