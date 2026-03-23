#include "S121.h"
#include "../Utils.h"
#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S121::GetAnswer()
{
	int turns = 15;
	// Polynomial coefficients. P[i] is coeff of x^i (i blues).
	// Initial: turn 0 (no discs taken yet): 1 way to have 0 blues.
	std::vector<long long> poly = { 1 };

	// Turns 1 to 15.
	// Turn k (1-based index):
	// P(Blue) = 1/(k+1), P(Red) = k/(k+1).
	// We multiply current poly by (x + k).
	// new_poly[i] = poly[i-1] * 1 + poly[i] * k

	for (int k = 1; k <= turns; k++)
	{
		std::vector<long long> next_poly(poly.size() + 1, 0);
		for (size_t i = 0; i < poly.size(); i++)
		{
			// Term x^i from prev poly.
			// Multiply by x -> x^{i+1}. Coeff 1.
			next_poly[i + 1] += poly[i];

			// Multiply by k -> x^i. Coeff k.
			next_poly[i] += poly[i] * k;
		}
		poly = next_poly;
	}

	long long numerator = 0;
	// Win if blues > turns / 2.
	// i.e. blues >= 8.
	for (int i = turns / 2 + 1; i <= turns; i++)
	{
		if (i < poly.size())
		{
			numerator += poly[i];
		}
	}

	// Denominator is (turns + 1)! = 16!
	// But we computed weighted sum. Total weight is sum of coeffs of poly.
	// Poly is product (x+k). Sum of coeffs is P(1) = product (1+k) = (n+1)!
	long long total = 0;
	for (long long c : poly)
	{
		total += c;
	}

	// Answer is floor(total / numerator)? No, inverse probability?
	// Problem: "find the maximum prize fund that should be allocated to a single game in which the player pays £1 to
	// enter". Expected return should be < 1. Prize * Prob < 1 => Prize < 1/Prob. Max Prize = floor(1/Prob).

	return std::to_string(total / numerator);
}

} // namespace ProjectEuler
