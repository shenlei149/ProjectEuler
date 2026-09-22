#include "S684.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
int64_t S684::GetRemainder(int64_t l)
{
	// Compute 10^l % Mod
	int64_t res = 1;
	int64_t base = 10;
	int64_t exp = l;
	int64_t mod = 1000000007;

	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			res = (__int128)res * base % mod;
		}
		base = (__int128)base * base % mod;
		exp /= 2;
	}
	return res;
}

int64_t S684::S(int64_t f)
{
	int64_t Mod = 1000000007;
	int64_t L = f / 9;
	int64_t r = f % 9;

	int64_t remainder = GetRemainder(L);

	// s(n) = r * 10^L + (10^L - 1)
	// Sum S(n) involves geometric series.
	// The formula in original code seems to be for Sum_{i=1}^f s(i).
	// Let's trust the formula.
	// first = (r*r + 3*r)/2 * 10^L - r.
	// second = 6 * 10^L - 6 - 9*L.
	// Result = first + second.

	int64_t term1 = (r * r + 3 * r) / 2;
	int64_t first = (__int128)term1 * remainder % Mod;
	first = (first - r + Mod) % Mod;

	int64_t second = (6 * remainder) % Mod;
	second = (second - 6 + Mod) % Mod;
	second = (second - (9 * (L % Mod)) % Mod + Mod) % Mod;

	return (first + second) % Mod;
}

std::string S684::GetAnswer()
{
	std::vector<int64_t> fibonacci;
	int64_t f0 = 0;
	int64_t f1 = 1;
	// f(2)=1, f(3)=2, ... f(90).
	// Problem asks for Sum S(f_i) for 2 <= i <= 90.
	// i=2: f=1.

	for (int i = 2; i <= 90; i++)
	{
		int64_t f2 = f0 + f1;
		fibonacci.push_back(f2);
		f0 = f1;
		f1 = f2;
	}

	int64_t result = 0;
	int64_t Mod = 1000000007;

	for (auto f : fibonacci)
	{
		result = (result + S(f)) % Mod;
	}

	return std::to_string(result);
}
} // namespace ProjectEuler
