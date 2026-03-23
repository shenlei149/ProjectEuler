#include "S75.h"
#include "../Utils.h"
#include <map>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S75::GetAnswer()
{
	int limit = 1500000;
	std::vector<int> counts(limit + 1, 0);

	// L = 2km(m+n)
	// m > n > 0
	// gcd(m, n) == 1
	// m, n not both odd (one even, one odd)

	long long m_limit = sqrt(limit / 2);

	for (long long m = 2; m <= m_limit; m++)
	{
		for (long long n = 1; n < m; n++)
		{
			if ((m + n) % 2 == 1 && Utils::GetGcd(m, n) == 1)
			{
				long long L = 2 * m * (m + n);
				long long k = 1;
				while (k * L <= limit)
				{
					counts[k * L]++;
					k++;
				}
			}
		}
	}

	int result = 0;
	for (int c : counts)
	{
		if (c == 1)
		{
			result++;
		}
	}

	return std::to_string(result);
}
} // namespace ProjectEuler
