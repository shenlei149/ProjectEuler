#include "S85.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S85::GetAnswer()
{
	int gridCount = 0;
	int length = 0;
	int width = 0;

	for (int i = 1; i < 1500; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int newGridCount = i * (i + 1) * j * (j + 1) / 4;
			if (std::abs(newGridCount - N) < std::abs(gridCount - N))
			{
				gridCount = newGridCount;
				length = i;
				width = j;
			}
		}
	}

	return std::to_string((length * width));
}

} // namespace ProjectEuler
