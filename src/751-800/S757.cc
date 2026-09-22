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
	int64_t limit = (int64_t)std::pow(MAX, 1.0 / 3.0) + 2;

	for (int64_t delta = 1; delta < limit; delta++)
	{
		TryDelta(delta);
	}

	std::sort(StealthyNumbers.begin(), StealthyNumbers.end());
	auto last = std::unique(StealthyNumbers.begin(), StealthyNumbers.end());
	StealthyNumbers.erase(last, StealthyNumbers.end());

	return std::to_string(StealthyNumbers.size());
}

void S757::TryDelta(int64_t delta)
{
	int64_t n = GetMaxN(delta);
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

	for (int64_t m = delta; m <= n; m++)
	{
		int64_t a = m * delta;
		int64_t b = (m + 1) * (delta + 1);
		StealthyNumbers.push_back(a * b);
	}
}

int64_t S757::GetMaxN(int64_t delta) { return (int64_t)std::sqrt(MAX / (delta * (delta + 1))); }

} // namespace ProjectEuler
