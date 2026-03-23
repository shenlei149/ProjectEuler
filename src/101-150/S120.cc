#include "S120.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S120::GetAnswer()
{
	int sum = 0;
	for (int a = 3; a <= 1000; a++)
	{
		sum += GetMaxRByA(a);
	}

	return std::to_string(sum);
}

int S120::GetMaxRByA(int a) { return (a - 1) / 2 * 2 * a; }

} // namespace ProjectEuler
