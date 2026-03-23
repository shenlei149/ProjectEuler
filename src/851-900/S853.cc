#include "S853.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S853::GetAnswer()
{
	long long sum = 0;

	// Initial power all 0.
	std::vector<int> power(bases.size(), 0);

	while (true)
	{
		long long n = 0;
		if (!Next(power, n))
		{
			break;
		}

		// Next returns valid n < N.
		// Check period.
		if (Period120(n))
		{
			sum += n;
		}
	}

	return std::to_string(sum);
}

long long S853::ToLong(const std::vector<int> &power)
{
	long long p = 1;
	for (size_t i = 0; i < power.size(); i++)
	{
		for (int j = 0; j < power[i]; j++)
		{
			p *= bases[i];
		}
	}
	return p;
}

bool S853::Next(std::vector<int> &power, long long &n)
{
	// Increment power like a number system
	// But limits are dynamic (product < N).
	// Actually, simple DFS or this iterative approach works if limits are handled.
	// The original code incremented p[0], then carry.
	// And reset to 0 if overflow N.

	// Code:
	/*
	for (int i = 0; i < power.size(); i++) {
		 power[i]++;
		 n = ToLong(power);
		 if (n > N) {
			 power[i] = 0; // Reset this digit
			 // Continue to increment next digit
			 if (i == power.size() - 1) return false;
		 } else {
			 return true; // Found valid next
		 }
	}
	*/

	for (size_t i = 0; i < power.size(); i++)
	{
		power[i]++;
		n = ToLong(power);
		if (n > N)
		{
			power[i] = 0;
			if (i == power.size() - 1)
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool S853::Period120(long long n)
{
	if (n <= 2)
	{
		return false; // period(1)=?, period(2)=3.
	}

	// Pisano period(n) = 120.
	// This implies F(120) = 0 mod n. (Because period(n)|120 means F(period)=0 mod n => F(120)=0 mod n).
	// But we need period(n) exactly 120.
	// It means F(120) = 0 mod n, and F(k) != 0 mod n for k < 120 (divisors of 120).
	// No, Pisano period is smallest k such that F(k)=0, F(k+1)=1.
	// Wait, normally pi(n) is period of sequence.
	// pi(n) = 120 means sequence repeats every 120.
	// This implies F(120) = 0 mod n AND F(121) = 1 mod n.
	// And for any d | 120, d < 120, NOT (F(d)=0 and F(d+1)=1).

	f[0] = 0;
	f[1] = 1;

	// Check divisors of 120: 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60.
	// We only need to check maximal proper divisors: 60, 40, 24?
	// If pi(n) = 120, then pi(n) does not divide 60, 40, 24.

	// Calculate terms up to 122?
	// Or just compute F(k) mod n.

	// First verify F(120) = 0, F(121) = 1.
	// F(120) mod n.
	// We can compute fast doubling or just loop since 120 is small.

	long long a = 0, b = 1;
	for (int i = 2; i <= 121; i++)
	{
		long long c = (a + b) % n;
		a = b;
		b = c;
		// a is F(i-1), b is F(i).
		// At i=120, b = F(120).
		// At i=121, b = F(121).
	}
	// After loop i=121:
	// b is F(121). a is F(120).

	if (a != 0 || b != 1)
	{
		return false;
	}

	// Now check proper divisors of 120.
	// 60, 40, 24.
	// If period divides 60, then F(60)=0, F(61)=1.
	// We can compute F(k) mod n for k in {60, 40, 24}.

	int checks[] = { 60, 40, 24 };
	for (int k : checks)
	{
		long long fk = 0, fk1 = 1;
		// Compute F(k), F(k+1)
		// Loop or fast doubling. Loop is fine.
		long long x = 0, y = 1;
		for (int j = 2; j <= k + 1; ++j)
		{
			long long z = (x + y) % n;
			x = y;
			y = z;
		}
		// x = F(k), y = F(k+1)
		if (x == 0 && y == 1)
		{
			return false;
		}
	}

	return true;
}
} // namespace ProjectEuler
