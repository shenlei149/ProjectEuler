#include "S301.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S301::GetAnswer()
{
	std::vector<int> zero_count(30);
	std::vector<int> one_count(30);
	zero_count[0] = 1;
	one_count[0] = 1;
	for (int i = 1; i < 30; i++)
	{
		zero_count[i] = zero_count[i - 1] + one_count[i - 1];
		one_count[i] = zero_count[i - 1];
	}

	return std::to_string((zero_count[29] + one_count[29]));
}

} // namespace ProjectEuler
