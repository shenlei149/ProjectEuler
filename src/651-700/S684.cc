#include "S684.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
long long S684::GetRemainder(long long l)
{
	// Compute 10^l % Mod
	long long res = 1;
	long long base = 10;
	long long exp = l;
	long long mod = 1000000007;

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

long long S684::S(long long f)
{
	long long Mod = 1000000007;
	long long L = f / 9;
	long long r = f % 9;

	long long remainder = GetRemainder(L);

	// s(n) = r * 10^L + (10^L - 1)
	// Sum S(n) involves geometric series.
	// The formula in original code seems to be for Sum_{i=1}^f s(i).
	// Let's trust the formula.
	// first = (r*r + 3*r)/2 * 10^L - r.
	// second = 6 * 10^L - 6 - 9*L.
	// Result = first + second.

	long long term1 = (r * r + 3 * r) / 2;
	long long first = (__int128)term1 * remainder % Mod;
	first = (first - r + Mod) % Mod;

	long long second = (6 * remainder) % Mod;
	second = (second - 6 + Mod) % Mod;
	second = (second - (9 * (L % Mod)) % Mod + Mod) % Mod;

	return (first + second) % Mod;
}

std::string S684::GetAnswer()
{
	std::vector<long long> fibonacci;
	long long f0 = 0;
	long long f1 = 1;
	// f(2)=1, f(3)=2, ... f(90).
	// Problem asks for Sum S(f_i) for 2 <= i <= 90.
	// i=2: f=1.

	for (int i = 2; i <= 90; i++)
	{
		long long f2 = f0 + f1;
		fibonacci.push_back(f2);
		f0 = f1;
		f1 = f2;
	}

	long long result = 0;
	long long Mod = 1000000007;

	for (auto f : fibonacci)
	{
		result = (result + S(f)) % Mod;
	}

	return std::to_string(result);
}
} // namespace ProjectEuler
