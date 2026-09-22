#include "S788.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S788::GetAnswer()
{
	Power9.assign(MaxD + 1, 0);
	Power9[0] = 1;
	for (int i = 1; i <= MaxD; i++)
	{
		Power9[i] = (Power9[i - 1] * 9) % Mod;
	}

	cache.assign(MaxD + 1, std::vector<int64_t>(MaxD + 1, 0));

	// Cache initialization?
	// Logic from code:
	// for (int i = 0; i <= MaxD; i++) { cache[i][0] = 1; cache[i][1] = i > 1 ? i : 1; }
	// Wait, cache[i][1] is Combinations(i, 1) = i.
	// If i=0, Comb(0,1)=0. Code says 1?
	// Logic: "i > 1 ? i : 1".
	// Comb(1,1)=1.
	// Comb(0,1)=0.
	// If i=1, 1. If i=0, 1?
	// The recursive function handles base cases.
	// I'll trust the recursive function.
	// But the cache initialization might be an optimization or base cases.
	// I'll implement recursive function with memoization, and let it fill.

	int64_t sum = 0;
	for (int i = 1; i <= MaxD; i++)
	{
		sum = (sum + Count(i)) % Mod;
	}

	return std::to_string(sum);
}

int64_t S788::Count(int D)
{
	int64_t count = 0;
	int start = (D % 2 == 0) ? (D / 2 + 1) : ((D + 1) / 2);

	for (int i = start; i <= D; i++)
	{
		// Case 1: Dominating digit is 0
		// We select 'i' positions for 0.
		// Remaining D-i positions can be anything 1-9.
		// But leading zero?
		// If D digits, leading cannot be 0.
		// So if 0 is dominating, we have i zeros.
		// One zero cannot be at position 0.
		// So we choose i positions out of D-1 (excluding first)?
		// Or total ways - ways with leading zero.
		// Original code:
		// Comb(D-1, i) * 9^(D-i).
		// Comb(D-1, i) chooses i positions from remaining D-1 (since first digit cannot be 0, wait).
		// If first digit is not 0, then 0 is at some i positions in the remaining D-1.
		// Wait, if 0 is dominating, count >= D/2 + 1 zeros.
		// Can 0 be dominating? Yes, e.g. 100.
		// Leading digit is non-zero (1-9).
		// Remaining D-1 digits have 'i' zeros.
		// So we need to choose 'i' zeros from D-1 positions.
		// Comb(D-1, i).
		// The remaining (D-1) - i positions are non-zero (1-9).
		// 9^(D-1-i).
		// Code: Comb(D-1, i) * Power9[D-i]?
		// D-i is exponent.
		// Wait, Power9[D-i] means 9^(D-i).
		// This implies remaining D-i positions (including first?)
		// If 0 is dominating, we have i zeros.
		// Total digits D.
		// First digit cannot be 0.
		// So first digit is one of 1-9 (9 choices).
		// Remaining D-1 positions need i zeros.
		// So we choose i positions from D-1.
		// Comb(D-1, i).
		// Remaining (D-1) - i positions are non-zero (1-9).
		// Total ways: 9 * Comb(D-1, i) * 9^(D-1-i) = Comb(D-1, i) * 9^(D-i).
		// This matches the code logic exactly!

		int64_t ways0 = GetCombinationsCountWithCache(D - 1, i);
		int remain = D - i;
		ways0 = (ways0 * Power9[remain]) % Mod;
		count = (count + ways0) % Mod;

		// Case 2: Dominating digit is non-zero (d in 1..9)
		// Subcase 2a: First digit is d.
		// We need i occurrences of d.
		// First is d. Remaining D-1 positions need i-1 occurrences of d.
		// Comb(D-1, i-1).
		// Remaining (D-1)-(i-1) = D-i positions are any other digit (0-9 except d).
		// 9 choices each.
		// 9^(D-i).
		// Multiply by 9 (for d=1..9).

		int64_t ways_d_first = GetCombinationsCountWithCache(D - 1, i - 1);
		ways_d_first = (ways_d_first * Power9[D - i]) % Mod;
		ways_d_first = (ways_d_first * 9) % Mod;
		count = (count + ways_d_first) % Mod;

		// Subcase 2b: First digit is NOT d.
		// First digit is one of 1-9 except d (8 choices).
		// We need i occurrences of d in remaining D-1 positions.
		// Comb(D-1, i).
		// Remaining (D-1)-i positions are anything except d (9 choices).
		// 9^(D-1-i).
		// Multiply by 8 (first digit choices).
		// Multiply by 9 (d choices).

		int remain2 = D - i - 1;
		if (remain2 >= 0)
		{
			int64_t ways_d_not_first = GetCombinationsCountWithCache(D - 1, i);
			ways_d_not_first = (ways_d_not_first * Power9[remain2]) % Mod;
			ways_d_not_first = (ways_d_not_first * 8) % Mod;
			ways_d_not_first = (ways_d_not_first * 9) % Mod;
			count = (count + ways_d_not_first) % Mod;
		}
	}
	return count;
}

int64_t S788::GetCombinationsCountWithCache(int64_t n, int64_t k)
{
	if (k < 0 || k > n)
	{
		return 0;
	}
	if (k == 0 || k == n)
	{
		return 1;
	}
	if (k > n / 2)
	{
		k = n - k;
	}

	if (cache[n][k] != 0)
	{
		return cache[n][k];
	}

	int64_t res = (GetCombinationsCountWithCache(n - 1, k) + GetCombinationsCountWithCache(n - 1, k - 1)) % Mod;
	cache[n][k] = res;
	return res;
}
} // namespace ProjectEuler
