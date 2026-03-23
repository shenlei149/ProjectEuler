#include "S80.h"
#include "../Utils.h"
#include <cmath>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S80::GetAnswer()
{
	long long totalSum = 0;
	// 10^200 - ensures 100 digits of precision (actually yields ~100 digits integer)
	// Sqrt(n * 10^200) approx Sqrt(n) * 10^100.
	// We want 100 decimal digits.
	// If n=2, sqrt=1.414... * 10^100 = 1414... (101 digits).
	// We sum first 100.

	std::string zeros(200, '0');
	BigInt scale("1" + zeros);

	for (int i = 1; i <= 100; i++)
	{
		long long root = std::llround(std::sqrt(i));
		if (root * root == i)
		{
			continue;
		}

		BigInt n(i);
		n = n * scale;
		BigInt r = BigInt::Sqrt(n);
		std::string s = r.toString();

		// Sum first 100 digits
		int limit = 100;
		if (s.length() < 100)
		{
			limit = s.length();
		}

		for (int j = 0; j < limit; j++)
		{
			totalSum += s[j] - '0';
		}
	}

	return std::to_string(totalSum);
}
} // namespace ProjectEuler
