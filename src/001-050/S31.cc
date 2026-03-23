#include "S31.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S31::GetAnswer()
{
	kindOfCoins = { 1, 2, 5, 10, 20, 50, 100, 200 };
	return std::to_string(CountCoins(200, kindOfCoins.size() - 1));
}

int S31::CountCoins(int amount, int index)
{
	if (amount == 0)
	{
		return 1;
	}

	if (amount < 0 || index < 0)
	{
		return 0;
	}

	return CountCoins(amount, index - 1) + CountCoins(amount - kindOfCoins[index], index);
}

} // namespace ProjectEuler
