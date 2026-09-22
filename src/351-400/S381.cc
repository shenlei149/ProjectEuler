#include "S381.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
// Modular Inverse for Prime Modulo p
// a^(p-2) = a^-1 (Fermat's Little Theorem)
int64_t modInverse(int64_t n, int64_t mod) { return Utils::Pow(n, (int64_t)(mod - 2), mod); }

// Or Extended Euclidean
int64_t modInverseEuclid(int64_t a, int64_t m)
{
	int64_t m0 = m, t, q;
	int64_t x0 = 0, x1 = 1;
	if (m == 1)
	{
		return 0;
	}
	while (a > 1)
	{
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
	{
		x1 += m0;
	}
	return x1;
}

std::string S381::GetAnswer()
{
	int64_t MAX = 100000000; // 10^8
	auto primes = Utils::GenPrimes(MAX);

	int64_t totalSum = 0;

	for (int64_t p : primes)
	{
		if (p < 5)
		{
			continue;
		}

		// We need sum (p-k)! mod p for k=1..5
		// (p-1)! = -1
		// (p-2)! = 1
		// (p-3)! = (p-2)! / (p-2) = 1 / (-2) = -1/2 = (p-1)/2
		// (p-4)! = (p-3)! / (p-3) = ((p-1)/2) / (-3) = (p-1)/(-6) = (1-p)/6
		// (p-5)! = (p-4)! / (p-4) = ((1-p)/6) / (-4) = (p-1)/24

		// Let's compute iteratively using modular inverse.
		int64_t s1 = p - 1; // -1
		int64_t s2 = 1;
		int64_t s3 = (p - 1) / 2; // (p-1) is even for p >= 5

		// s4 = s3 * inv(-3)
		// inv(-3) = inv(p-3)
		// Using Fermat: pow(p-3, p-2, p)
		// But Euclid is faster usually.

		int64_t inv3 = modInverseEuclid(p - 3, p);
		int64_t s4 = (s3 * inv3) % p;

		int64_t inv4 = modInverseEuclid(p - 4, p);
		int64_t s5 = (s4 * inv4) % p;

		int64_t sumP = (s1 + s2 + s3 + s4 + s5) % p;
		totalSum += sumP;
	}

	return std::to_string(totalSum);
}
} // namespace ProjectEuler
