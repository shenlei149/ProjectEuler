#include "S100.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S100::GetAnswer()
{
	double sqrt2 = std::sqrt(2);

	for (int i = 1;; i++)
	{
		int64_t x = (int64_t)((std::pow(1 + sqrt2, 2 * i - 1) + std::pow(1 - sqrt2, 2 * i - 1)) / 2) + 1;
		int64_t y = (int64_t)((std::pow(1 + sqrt2, 2 * i - 1) - std::pow(1 - sqrt2, 2 * i - 1)) / 2 / sqrt2) + 1;

		if (x > 2000000000000)
		{
			return std::to_string(((y + 1) / 2));
		}
	}
}

} // namespace ProjectEuler
