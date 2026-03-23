#include "S38.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S38::GetAnswer()
{
	int maxPandigitalNumber = 0;
	for (int i = 2; i < 10000; i++)
	{
		std::string sb = "";

		int n = 1;
		while (sb.size() < 9)
		{
			sb += std::to_string(i * n);
			n++;
		}

		if (sb.size() == 9 && Utils::IsPandigital(sb, false))
		{
			int tmp = std::stoi(sb);

			if (tmp > maxPandigitalNumber)
			{
				maxPandigitalNumber = tmp;
			}
		}
	}
	return std::to_string(maxPandigitalNumber);
}

} // namespace ProjectEuler
