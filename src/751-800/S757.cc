#include "S757.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S757::GetAnswer()
{
	// Limit delta to N^(1/3)
	// logic based on ported code
	long long limit = (long long)std::pow(MAX, 1.0 / 3.0) + 2;

	for (long long delta = 1; delta < limit; delta++)
	{
		TryDelta(delta);
	}

	std::sort(StealthyNumbers.begin(), StealthyNumbers.end());
	auto last = std::unique(StealthyNumbers.begin(), StealthyNumbers.end());
	StealthyNumbers.erase(last, StealthyNumbers.end());

	return std::to_string(StealthyNumbers.size());
}

void S757::TryDelta(long long delta)
{
	long long n = GetMaxN(delta);
	// Check overflow
	// n*(n+1)*delta*(delta+1) > MAX
	// We want a*b <= MAX.
	// a = n*delta, b = (n+1)*(delta+1).

	// n might be slightly overestimated
	while (true)
	{
		unsigned __int128 val = (unsigned __int128)n * (n + 1) * delta * (delta + 1);
		if (val > MAX)
		{
			n--;
		}
		else
		{
			break;
		}
	}

	if (n < delta) // ensure c <= d? logic from original
	{
		return;
	}

	for (long long m = delta; m <= n; m++)
	{
		long long a = m * delta;
		long long b = (m + 1) * (delta + 1);
		StealthyNumbers.push_back(a * b);
	}
}

long long S757::GetMaxN(long long delta) { return (long long)std::sqrt(MAX / (delta * (delta + 1))); }

} // namespace ProjectEuler
