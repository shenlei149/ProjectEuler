#include "S26.h"
#include "../Utils.h"
#include <algorithm>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S26::GetAnswer()
{
	int max = 0;
	int value = 1;
	for (int i = 2; i < 1000; i++)
	{
		int tmp = GetRecurringCycle(1, i);
		if (tmp > max)
		{
			max = tmp;
			value = i;
		}
	}

	return std::to_string(value);
}

int S26::GetRecurringCycle(int n, int m)
{
	std::vector<int> dividends;

	while (true)
	{
		while (n < m)
		{
			n *= 10;
		}

		auto it = std::find(dividends.begin(), dividends.end(), n);
		if (it != dividends.end())
		{
			return std::distance(it, dividends.end());
		}

		dividends.push_back(n);
		n %= m;

		if (n == 0)
		{
			return 0;
		}
	}
}

} // namespace ProjectEuler
