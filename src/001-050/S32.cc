#include "S32.h"
#include "../Utils.h"
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{

std::string S32::GetAnswer()
{
	long long sum = 0;
	// digits 1-9
	const std::string all_digits = "123456789";

	// Use a set to avoid summing duplicates? Project Euler 32 says "sum of all products".
	// "HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum."
	std::set<int> valid_products;

	for (int i = 1000; i < 10000; i++)
	{
		std::string s_i = std::to_string(i);
		if (Utils::IsPandigital(s_i, false))
		{
			// Check if s_i has '0'. IsPandigital(..., false) checks for 0 if implemented correctly.
			// Utils::IsPandigital implementation:
			// if (!canContainsZero && s.find('0') != npos) return false;
			// distinct.size() == s.length();
			// So yes, it checks 0 and uniqueness.

			// Find remaining digits
			std::string factorDigits = "";
			for (char c : all_digits)
			{
				if (s_i.find(c) == std::string::npos)
				{
					factorDigits += c;
				}
			}

			// factorDigits should have length 5 (9 - 4)
			if (factorDigits.length() == 5)
			{
				std::vector<char> fd(factorDigits.begin(), factorDigits.end());
				if (IsPandigitalProduct(i, fd))
				{
					valid_products.insert(i);
				}
			}
		}
	}

	for (int p : valid_products)
	{
		sum += p;
	}

	return std::to_string(sum);
}

int S32::CharsToInt(const std::vector<char> &chars)
{
	int val = 0;
	for (char c : chars)
	{
		val = val * 10 + (c - '0');
	}
	return val;
}

bool S32::IsPandigitalProduct(int i, std::vector<char> factorDigits)
{
	// factorDigits is sorted? Not necessarily. But for cache key it should be unique.
	// In GetAnswer loop, factorDigits is constructed in order '1'..'9', so it is sorted.
	std::string key(factorDigits.begin(), factorDigits.end());

	if (cache.find(key) == cache.end())
	{
		cache[key] = std::set<int>();
		// Generate permutations
		std::sort(factorDigits.begin(), factorDigits.end());
		do
		{
			// Split 1+4 or 2+3
			// 1 digit * 4 digits = 5 digits (too large? max prod is 9999). 9*9999=89991 (5 digits).
			// Wait, i is 4 digits.
			// 1 * 4 digits: 9 * 8765 = 78885 (5 digits). 2 * 3456 = 6912 (4 digits).
			// So 1 * 4 is possible.
			// 2 * 3 digits: 99 * 999 = 98901 (5 digits). 12 * 345 = 4140 (4 digits).
			// So 2 * 3 is possible.
			// 3 * 2 digits: same as 2 * 3.
			// 4 * 1 digits: same as 1 * 4.

			// So check split at k=1, k=2. (and k=3, k=4 covering the reverse).
			// Actually just generating all products a*b is enough.

			for (int k = 1; k < 5; k++)
			{
				std::vector<char> v1(factorDigits.begin(), factorDigits.begin() + k);
				std::vector<char> v2(factorDigits.begin() + k, factorDigits.end());

				int n1 = CharsToInt(v1);
				int n2 = CharsToInt(v2);
				cache[key].insert(n1 * n2);
			}
		}
		while (std::next_permutation(factorDigits.begin(), factorDigits.end()));
	}

	return cache[key].count(i) > 0;
}

} // namespace ProjectEuler
