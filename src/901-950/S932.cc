#include "S932.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S932::GetAnswer()
{
	POW = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	// Max square is (10^8)^2 = 10^16. Fits in long long.
	// POW up to 10^16? No, 16 digits.
	POW.resize(17);
	long long p = 1;
	for (int i = 0; i < 17; ++i)
	{
		POW[i] = p;
		p *= 10;
	}

	long long sum = 0;
	for (long long i = 4; i <= RootUpper; i++) // <= or < ? Code said <
	{
		// Code said < RootUpper, but RootUpper = 10^8 - 1.
		// Problem 932 "2023 numbers".
		// "Find sum of all 2023-numbers less than 10^16".
		// So square < 10^16 => root < 10^8.
		// i < 100000000.

		long long square = i * i;
		if (Is2005Number(i, square))
		{
			sum += square;
		}
	}
	return std::to_string(sum);
}

bool S932::Is2005Number(long long root, long long square)
{
	// 2025 property: 2025 = 45^2. 20+25 = 45.
	// Split square into two parts a, b. a+b = root.
	// Split at any position?
	// "split into two parts... sum equals sqrt(n)".
	// Example 2025 -> 20, 25. 20+25=45. 45^2=2025.
	// Original code loop: `i = s.size()/2` to `s.size()/2 + length`.
	// Suggests restricted split?
	// Problem 932 doesn't specify restriction?
	// Usually it's "split into two parts".
	// But leading zeros? "a can be 0? b cannot have leading zero?"
	// Usually right part cannot have leading zero unless it's just "0".
	// But code: `if (s[i] == '0') continue`.
	// This implies split point `i` (number of digits in right part?).
	// `s.size() - i` is power index.
	// Wait, loop `i` iterates index in string?
	// `s[i]` is first digit of right part.
	// If `s[i] == '0'`, right part has leading zero.
	// Code skips it. Correct.

	std::string s = std::to_string(square);
	int len = s.length();

	for (int k = 1; k < len; ++k)
	{
		// Split into s[0..k-1] and s[k..len-1]
		// Right part starts at s[k].
		if (s[k] == '0')
		{
			continue;
		}

		// Left part a, Right part b.
		// a = square / 10^(len-k).
		// b = square % 10^(len-k).

		long long power = POW[len - k];
		long long a = square / power;
		long long b = square % power;

		if (a + b == root)
		{
			return true;
		}
	}
	return false;
}
} // namespace ProjectEuler
