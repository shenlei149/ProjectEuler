#include "S808.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
long long Reverse(long long n)
{
	long long rev = 0;
	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}

bool IsSquare(long long n)
{
	long long root = (long long)std::sqrt(n);
	return root * root == n;
}

// Check if n is prime
bool IsPrime(long long n, const std::vector<bool> &is_prime)
{
	if (n < is_prime.size())
	{
		return is_prime[n];
	}
	// If outside sieve range, simple trial division (unlikely if sieve is large enough)
	return false;
}

std::string S808::GetAnswer()
{
	// Reversible prime squares.
	// p^2 is palindrome? No, reverse of p^2 is also a square q^2, and q is prime.
	// And p != q (not palindrome).

	// Generate primes.
	int limit = 40000000; // Guess limit
	auto primes_long = Utils::GenPrimes(limit);

	// Check squares
	// We need 50 reversible prime squares.
	int count = 0;
	long long sum = 0;

	// Use a set or hash for fast lookup of squares?
	// Or check if reverse is square.
	// If reverse(p^2) is square, let it be x^2.
	// We need to check if x is prime.

	// Sieve for primality check of x
	// x = sqrt(reverse(p^2)).
	// reverse(p^2) < 10^15?
	// p ~ 3e7 => p^2 ~ 9e14. Reverse ~ 9e14. x ~ 3e7.
	// So sieve of 4e7 is enough to check x.

	std::vector<bool> is_prime_sieve(limit + 1, false);
	for (long long p : primes_long)
	{
		if (p <= limit)
		{
			is_prime_sieve[p] = true;
		}
	}

	for (long long p : primes_long)
	{
		long long sq = p * p;
		long long rev_sq = Reverse(sq);

		if (rev_sq == sq)
		{
			continue; // Palindrome not allowed? Problem says "not a palindrome"
		}

		long long root = (long long)std::round(std::sqrt(rev_sq));
		if (root * root == rev_sq)
		{
			// Check if root is prime
			if (root <= limit && is_prime_sieve[root])
			{
				count++;
				sum += sq;
				if (count == 50)
				{
					break;
				}
			}
		}
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
