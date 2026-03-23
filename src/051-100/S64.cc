#include "S64.h"
#include <cmath>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S64::GetAnswer()
{
	int count = 0;
	for (int N = 1; N <= 10000; N++)
	{
		int limit = sqrt(N);
		if (limit * limit == N)
		{
			continue;
		}

		int m = 0;
		int d = 1;
		int a0 = limit;
		int a = a0;

		int period = 0;
		while (a != 2 * a0)
		{
			m = d * a - m;
			d = (N - m * m) / d;
			a = (a0 + m) / d;
			period++;
		}

		if (period % 2 == 1)
		{
			count++;
		}
	}
	return std::to_string(count);
}
} // namespace ProjectEuler
