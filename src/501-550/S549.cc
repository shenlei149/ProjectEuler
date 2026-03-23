#include "S549.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
static int s_calc(int p, int k)
{
	int m = 0;
	int count = 0;
	while (count < k)
	{
		m += p;
		int temp = m;
		while (temp % p == 0)
		{
			count++;
			temp /= p;
		}
	}
	return m;
}

std::string S549::GetAnswer()
{
	int N = 100000000;
	std::vector<int> S(N + 1, 0);

	for (int i = 2; i <= N; ++i)
	{
		if (S[i] == 0)
		{
			// i is prime
			long long p = i;
			long long pk = p;
			int k = 1;

			while (pk <= N)
			{
				int val;
				if (k == 1)
				{
					val = p;
				}
				else
				{
					val = s_calc((int)p, k);
				}

				for (int j = (int)pk; j <= N; j += (int)pk)
				{
					if (S[j] < val)
					{
						S[j] = val;
					}
				}

				if (N / p < pk)
				{
					break;
				}
				pk *= p;
				k++;
			}
		}
	}

	long long sum = 0;
	for (int i = 2; i <= N; ++i)
	{
		sum += S[i];
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
