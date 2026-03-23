#include "S820.h"
#include <iostream>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S820::GetAnswer()
{
	long long sum = 0;
	// nth decimal digit of 1/k. n=MAX=10^7.
	// digit = floor( (10^n / k) % 10 ).
	// = floor( 10^n / k ) % 10.
	// = ( (10^n - (10^n % k)) / k ) % 10.
	// It's equivalent to (10^n mod (10k)) / k.
	// Or simply: (10^n mod k) * 10 / k.
	// Let r = 10^n mod k.
	// next digit is floor(r * 10 / k).
	// Correct.
	// D(k) = floor( (10^n mod k) * 10 / k ).
	// Exponent n is MAX.
	// Wait, Code said `PowerMod(10, MAX - 1, k)`.
	// If n=MAX. `10^MAX mod k`.
	// `D(k)` in code: `PowerMod(10, MAX-1, k) * 10 / k`.
	// This is `(10^(MAX-1) mod k) * 10 / k`.
	// This computes the MAX-th digit?
	// 1/k = 0.d1 d2 ...
	// d1 = floor(10/k). rem = 10%k.
	// d2 = floor(rem*10/k).
	// rem_m = 10^m mod k.
	// d_m = floor( (10^(m-1) mod k) * 10 / k ).
	// We want d_MAX.
	// So m=MAX.
	// d_MAX = floor( (10^(MAX-1) mod k) * 10 / k ).
	// Correct.

	for (int k = 1; k <= MAX; k++)
	{
		sum += D(k);
	}

	return std::to_string(sum);
}

int S820::D(int k)
{
	long long pm = PowerMod(10, MAX - 1, k);
	return (int)(pm * 10 / k);
}

int S820::PowerMod(int baseValue, int exponent, int modulus)
{
	long long result = 1;
	long long baseMod = baseValue % modulus;

	while (exponent > 0)
	{
		if ((exponent & 1) == 1)
		{
			result = (result * baseMod) % modulus;
		}

		baseMod = (baseMod * baseMod) % modulus;
		exponent >>= 1;
	}

	return (int)result;
}
} // namespace ProjectEuler
