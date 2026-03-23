#include "S28.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S28::GetAnswer()
{
	int sum = 0;
	for (int i = 1; i <= 500; i++)
	{
		sum += i * i * 16 + i * 4 + 4;
	}

	return std::to_string((sum + 1));
}

} // namespace ProjectEuler
