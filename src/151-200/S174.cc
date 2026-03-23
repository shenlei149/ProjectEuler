#include "S174.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S174::GetAnswer()
{
	std::vector<int> counts(N + 1, 0);

	for (int hole = 1; hole < N / 4; hole++)
	{
		int min_length = hole + 1;

		for (int max_length = min_length;; max_length += 2)
		{
			int a_1 = min_length;
			int a_n = max_length;
			int n = (a_n - a_1) / 2 + 1;
			int total = (a_1 + a_n) * n / 2 * 4;
			if (total <= N)
			{
				counts[total]++;
			}
			else
			{
				break;
			}
		}
	}

	int sum = 0;
	for (int j = 0; j < counts.size(); j++)
	{
		if (counts[j] <= 10 && counts[j] >= 1)
		{
			sum++;
		}
	}

	return std::to_string(sum);
}

} // namespace ProjectEuler
