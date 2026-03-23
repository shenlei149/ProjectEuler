#include "S39.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S39::GetAnswer()
{
	int maxValue = 0;
	int maxCount = 0;
	for (int i = 3; i <= 1000; i++)
	{
		int count = GetSolutionCount(i);
		if (count > maxCount)
		{
			maxCount = count;
			maxValue = i;
		}
	}

	return std::to_string(maxValue);
}

int S39::GetSolutionCount(int p)
{
	int count = 0;
	for (int a = 1; a <= p / 3; a++)
	{
		for (int b = a; b <= p / 2; b++)
		{
			int c = p - a - b;
			if (c >= b && a + b > c && a * a + b * b == c * c)
			{
				count++;
			}
		}
	}

	return count;
}

} // namespace ProjectEuler
