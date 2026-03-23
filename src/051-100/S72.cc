#include "S72.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S72::GetAnswer()
{
	long long count = 0;

	for (int d = 2; d <= 1000000; d++)
	{
		count += Utils::GetCoprimeCount(d);
	}

	return std::to_string(count);
}

} // namespace ProjectEuler
