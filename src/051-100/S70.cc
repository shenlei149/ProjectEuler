#include "S70.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
bool IsPermutation(long long a, long long b)
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
	long long limit = 10000000;
	double minRatio = 100.0;
	long long result = 0;

	auto primes = Utils::GenPrimes(5000);
	std::vector<int> rangePrimes;
	for (long long p : primes)
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
			long long n = (long long)rangePrimes[i] * rangePrimes[j];
			if (n > limit)
			{
				break;
			}

			long long phi = (rangePrimes[i] - 1) * (rangePrimes[j] - 1);

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
