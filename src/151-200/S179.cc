#include "S179.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S179::GetAnswer()
{
	std::vector<int> numberOfDivisors(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			numberOfDivisors[j]++;
		}
	}

	int count = 0;
	for (int i = 2; i < N; i++)
	{
		if (numberOfDivisors[i] == numberOfDivisors[i + 1])
		{
			count++;
		}
	}

	return std::to_string(count);
}

} // namespace ProjectEuler
