#include "S97.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S97::GetAnswer()
{
	long long massivePrime = 1;
	for (int i = 0; i < 7830457; i++)
	{
		massivePrime *= 2;
		massivePrime %= 10'000'000'000;
	}

	massivePrime *= 28433;
	massivePrime += 1;

	return std::to_string((massivePrime % 10'000'000'000));
}

} // namespace ProjectEuler
