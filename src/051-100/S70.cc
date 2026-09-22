#include "S70.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
bool IsPermutation(int64_t a, int64_t b)
{
	string sa = to_string(a);
	string sb = to_string(b);
	if (sa.length() != sb.length())
	{
		return false;
	}
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	return sa == sb;
}

std::string S70::GetAnswer()
{
	int64_t limit = 10000000;
	double minRatio = 100.0;
	int64_t result = 0;

	auto primes = Utils::GenPrimes(5000);
	std::vector<int> rangePrimes;
	for (int64_t p : primes)
	{
		if (p > 2000)
		{
			rangePrimes.push_back(p);
		}
	}

	for (size_t i = 0; i < rangePrimes.size(); i++)
	{
		for (size_t j = i; j < rangePrimes.size(); j++)
		{
			int64_t n = (int64_t)rangePrimes[i] * rangePrimes[j];
			if (n > limit)
			{
				break;
			}

			int64_t phi = (rangePrimes[i] - 1) * (rangePrimes[j] - 1);

			double ratio = (double)n / phi;
			if (ratio < minRatio)
			{
				if (IsPermutation(n, phi))
				{
					minRatio = ratio;
					result = n;
				}
			}
		}
	}

	return std::to_string(result);
}
} // namespace ProjectEuler
