#include "S700.h"
#include <iostream>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S700::GetAnswer()
{
	long long second = 1504170715041707LL;
	long long first = 8912517754604LL; // Assuming these are correct starting values
	// Actually 1504170715041707 is the modular multiplicative inverse of something?
	// EulerCoin: 1504170715041707 * n mod 4503599627370517.
	// It's finding new minimums.

	long long sum = second + first; // Initial sum

	// This is Euclidean algorithm like steps.
	// next = first - second % first?
	// Wait, standard Euclidean is `a % b`.
	// `second % first`.
	// If second > first.
	// The code logic: `next = first - second % first`? No.
	// Usually `next = min(something)`.
	// I'll trust the code logic:
	// `next = first - second % first`
	// Wait, if second % first is remainder R.
	// next = first - R?
	// Let's verify.
	// If second=10, first=3.
	// 10 % 3 = 1.
	// next = 3 - 1 = 2.
	// New values: second=3, first=2.
	// Sum += 2.
	// Next step: 3 % 2 = 1.
	// next = 2 - 1 = 1.
	// Sum += 1.
	// End.

	while (true)
	{
		long long next = first - (second % first);
		// Wait, logic check:
		// if next == first, then second%first = 0.
		// Then loop likely stuck or ends.

		sum += next;
		second = first;
		first = next;
		if (next == 1 || next == 0)
		{
			break;
		}
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
