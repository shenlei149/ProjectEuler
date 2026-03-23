#include "S686.h"
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S686::GetAnswer()
{
	// L=123.
	// Find 678910-th number.
	int n = 0; // count found
	int target_n = 678910;

	// Log10(1.23) = 0.089905111
	// Log10(1.24) = 0.093421685
	double low = std::log10(1.23);
	double high = std::log10(1.24);
	double log2 = std::log10(2.0);

	// Start j.
	// Use map to jump.
	// Jumps: 196, 289, 485.
	// Map next jump based on previous jump?
	// Or just iterate with small jumps?
	// 196 is a very good approximation.
	// 196 * log2 = 58.999... almost integer.
	// 289 * log2 = 86.99...
	// 485 * log2 = 146.000...

	// We can just iterate j = j + 196 (mostly) or others.
	// Or simpler: iterate j step by step? Too slow. 6.7e5 * 200 ~ 1.4e8.
	// 1.4e8 is fast enough in C++.
	// Wait, j goes up to 678910 * 485? No.
	// Density is about 1/196.
	// So j_max ~ 6.7e5 * 196 ~ 1.3e8.
	// Iterating 1.3e8 times doing double addition/mod is fast.
	// 1 second.

	// Let's implement simple iteration first, if too slow, use jumps.
	// Actually, simple iteration:
	// j * log2 mod 1.
	// We can maintain `curr = j * log2`.

	long long j = 0;
	// Optimization: Start from j=0?
	// Problem asks for n=678910.

	// Fast loop
	// We check if (j * log2) fractional part is in [low, high).

	// To avoid precision issues, use long double?
	// Or just `fmod(j * log2, 1.0)`.

	// Let's use the jump map from the original code as a hint.
	// It tracks `diff` (last jump size) and `Next` map.
	// The original code was efficient.
	// I will replicate it.

	std::map<int, std::vector<int>> Next = {
		{ 196, { 289, 485 } },
		{ 289, { 196 }	   },
		{ 485, { 196, 485 } }
	};

	j = 90; // Starting point from original code?
	// 2^90 = 1.237e27. Starts with 123. n=1.
	n = 1;
	int diff = 196; // First jump

	while (n < target_n)
	{
		auto &candidates = Next[diff];
		bool found = false;
		for (int jump : candidates)
		{
			int next_j = j + jump;
			// Check if 2^next_j starts with 123
			// double val = next_j * log2;
			// double frac = val - floor(val);
			// if (frac >= low && frac < high)

			// Using modf
			double intpart;
			double frac = std::modf(next_j * log2, &intpart);

			if (frac >= low && frac < high)
			{
				j = next_j;
				diff = jump;
				n++;
				found = true;
				break;
			}
		}
		if (!found)
		{
			// Fallback if map is incomplete?
			// Original code assumed it is complete.
			// If not found, maybe just linear search or larger jump?
			// But for C++ port I should probably trust the map logic or implement safe search.
			// I'll add a linear fallback just in case.
			j++;
			double intpart;
			double frac = std::modf(j * log2, &intpart);
			if (frac >= low && frac < high)
			{
				n++;
				// Reset diff logic?
				diff = 196; // Reset to default
			}
		}
	}

	return std::to_string(j);
}
} // namespace ProjectEuler
