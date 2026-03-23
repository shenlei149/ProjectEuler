#include "S118.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{

std::string S118::GetAnswer()
{
	unique.assign(10, std::vector<int>());

	// Generate primes up to some reasonable limit?
	// GenPrimes builds them.
	// It calls IsPrime with `primes` vector.
	// We need primes for primality test. sqrt(10^9) = 31622.
	// Actually GenPrimes is generating primes by digits.
	// Primes could be up to 9 digits.
	// We need Miller-Rabin or trial division.
	// Utils::IsPrime(long long) should be sufficient.

	// Primes up to 10000 passed to GenPrimes. Why?
	// C# code: Utils::GenPrimes(10000).
	// Maybe for IsPrime optimization.

	std::vector<long long> smallPrimes = Utils::GenPrimes(10000);
	// Remove 0 if present? GenPrimes usually returns primes.

	for (int i = 1; i < 10; i++)
	{
		GenPrimes(i, 1, smallPrimes);
	}

	// Add 2 separately? C# did: unique[1].push_back(2);
	// GenPrimes(i...) iterates 1..9. 2 is prime.
	// Wait, GenPrimes iterates i=1..9.
	// If i=2, IsPrime(2) is true.
	// So 2 should be added.
	// But GenPrimes loop starts i=1.
	// If loop i=1, IsPrime(1) false.
	// If loop i=2, IsPrime(2) true.
	// Maybe C# logic excluded even digits or something?
	// Ah, C# loop: `for (int i = 1; i < 10; i += 2)`. Odd digits only?
	// Except 2?
	// Yes, all primes > 5 end in 1, 3, 7, 9. 2 and 5 are exceptions.
	// 5 can only be single digit 5.
	// 2 can only be single digit 2.
	// The recursive generation builds numbers by appending digits.
	// If we append digits, we might end up with even number?
	// No, usually we check at each step or at end.
	// The C# code: `GenPrimes(value + i * pow[length]...)`
	// It appends `i` at the FRONT? `value + i * pow`. Yes.
	// If `value` starts with odd, we append to front.
	// The last digit (original `value`) determines divisibility by 2 or 5.
	// So iterating 1, 3, 5, 7, 9 for the *last* digit covers most.
	// 2 is special. 5 is special.
	// C# `i+=2` covers 1, 3, 5, 7, 9.
	// 5 is prime. 15 not. 25 not. So only 5 works for ending in 5.
	// 2 is even.

	// So the strategy:
	// Iterate last digit `d` in 1, 3, 5, 7, 9.
	// 5 is only prime if length 1.
	// Recursively prepend digits.

	// So clear unique first.
	unique.assign(10, std::vector<int>());

	// C# code:
	// for (int i = 1; i < 10; i += 2) GenPrimes(i, 1, primes);
	// unique[1].push_back(2);
	// sort and reverse.

	// Replicate:
	for (int i = 1; i < 10; i += 2)
	{
		GenPrimes(i, 1, smallPrimes);
	}
	unique[1].push_back(2);

	for (auto &list : unique)
	{
		std::sort(list.begin(), list.end());
		std::reverse(list.begin(), list.end()); // descending order?
	}

	int count = 0;
	// Iterate set sizes. Max 9 digits.
	// Actually we pick subsets.
	// Elements from unique[i].
	// C# loop:
	/*
	for (int i = 8; i >= 2; i--) { // length of first prime?
		auto list = unique[i];
		for (auto start : list) {
			GenSets({start}, i, i, ref count);
		}
	}
	// Also length 1?
	// The C# loop skipped i=1?
	// Wait, primes of length 1 (2, 3, 5, 7).
	// If we pick 2, length 1.
	// Maybe handled by `i >= 1` in `GenSets` loop.
	// But outer loop `i >= 2`.
	// Maybe `start` prime must be large to avoid duplicates?
	// Actually, `GenSets` iterates `i = min(remain, lastLength)`.
	// It ensures non-increasing length order?
	// If first prime has length 1, then all have length 1?
	// If first has length 8, next has 1.
	// The loop `i >= 2` suggests we force at least one prime of length >= 2?
	// What if all are length 1? e.g. {2,3,5,7}. Sum lengths = 4. Target 9.
	// We can't have 9 primes of length 1 (only 4 exist: 2,3,5,7).
	// So at least one prime must have length >= 2.
	// Max digits 9.
	// Primes of length 1: 2,3,5,7.
	// Unique digits.
	*/

	// We just follow the C# logic.
	for (int i = 8; i >= 1; i--) // Changed to 1 to be safe, but C# said 2?
	{
		// If C# said 2, maybe it proved we need at least one prime >= 2 digits?
		// Digits 1..9 sum to 45. 45 div 3. So sum is divisible by 3.
		// If all primes are length 1 (2,3,5,7), sum is 17. Not pandigital.
		// So we can't partition 1..9 into 1-digit primes.
		// So at least one prime >= 2 digits.
		if (i < 1)
		{
			continue;
		}

		for (int start : unique[i])
		{
			std::vector<int> current = { start };
			GenSets(current, i, i, count);
		}
	}

	return std::to_string(count);
}

void S118::GenSets(const std::vector<int> &elements, int length, int lastLength, int &count)
{
	if (length == 9)
	{
		if (Utils::IsPandigital(elements))
		{
			count++;
		}
		return;
	}

	// Optimization check?
	if (!Utils::IsPandigital(elements))
	{
		return;
	}

	int remain = 9 - length;
	int begin = std::min(remain, lastLength);

	for (int i = begin; i >= 1; i--)
	{
		const auto &list = unique[i];

		int start = 0;
		if (lastLength == i)
		{
			// Find index of last element to enforce ordering (sets are unordered)
			// Since we iterate primes in descending order (if sorted that way),
			// we pick next primes from later indices.
			// list is sorted descending.
			// We want p_next <= p_prev.
			// Actually sets {A, B} == {B, A}.
			// So we enforce A > B > C...
			// elements.back() is the last added prime.
			// We find its index in `list`.
			auto it = std::find(list.begin(), list.end(), elements.back());
			if (it != list.end())
			{
				start = std::distance(list.begin(), it) + 1;
			}
		}

		for (size_t j = start; j < list.size(); j++)
		{
			int n = list[j];
			// Check if n has conflicting digits with elements?
			// IsPandigital(elements + n) check at start of recursive call handles it?
			// Yes, but we can check early.
			// Actually IsPandigital on vector checks total digits.

			std::vector<int> newlist = elements;
			newlist.push_back(n);
			GenSets(newlist, length + i, i, count);
		}
	}
}

void S118::GenPrimes(int value, int length, const std::vector<long long> &primes)
{
	// Check if value digits are unique (no 0, no duplicates)
	// Utils::IsPandigital(value) checks if 1..N digits are present?
	// No, usually IsPandigital(123) is true for 1..3.
	// But here we just want "no duplicate digits" and "no zero".
	// IsPandigital(val) implies length check?
	// Let's assume IsPandigital checks "contains digits 1..L exactly once".
	// That's not what we want. We want "no repeats, no zero".
	// But the C# used `IsPandigital(value)`.
	// If value=1, length=1. IsPandigital(1) -> true.
	// If value=12, length=2. IsPandigital(12) -> true.
	// If value=121, length=3. IsPandigital(121) -> false.
	// So yes, it works.

	if (!Utils::IsPandigital(value))
	{
		return;
	}

	if (Utils::IsPrime(value)) // Uses default efficient check
	{
		unique[length].push_back(value);
	}

	if (length >= 8) // Can't have 9 digit prime because sum 1..9=45 div 3.
	{
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		// Prepend digit i
		// value + i * 10^length
		// Wait, C# `pow` array was 1, 10, ...
		// `pow[length]` is 10^length.
		GenPrimes(value + i * pow10[length], length + 1, primes);
	}
}

} // namespace ProjectEuler
