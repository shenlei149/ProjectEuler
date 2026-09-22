#include "S104.h"
#include "../Utils.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S104::GetAnswer()
{
	int64_t mod = 1000000000;
	int64_t f1 = 1;
	int64_t f2 = 1;
	int64_t fn = 0;
	int k = 3;

	double logPhi = std::log10((1.0 + std::sqrt(5.0)) / 2.0);
	double logSqrt5 = std::log10(5.0) / 2.0;

	auto IsPandigital1To9 = [](int64_t n) -> bool
	{
		if (n < 100000000)
		{
			return false; // Must be at least 9 digits (actually exactly 9 for first/last 9 check)
		}
		int digits[10] = { 0 };
		int count = 0;
		while (n > 0)
		{
			int d = n % 10;
			if (d == 0)
			{
				return false;
			}
			if (digits[d] > 0)
			{
				return false;
			}
			digits[d]++;
			count++;
			n /= 10;
		}
		return count == 9;
	};

	while (true)
	{
		fn = (f1 + f2) % mod;

		// Check last 9 digits
		if (IsPandigital1To9(fn))
		{
			// Check first 9 digits
			double t = k * logPhi - logSqrt5;
			double fractional = t - std::floor(t);
			int64_t first9 = (int64_t)std::pow(10, fractional + 8);

			if (IsPandigital1To9(first9))
			{
				return std::to_string(k);
			}
		}

		f1 = f2;
		f2 = fn;
		k++;
	}
}

} // namespace ProjectEuler
