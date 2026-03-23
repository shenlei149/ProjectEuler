#include "S109.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S109::GetAnswer()
{
	// Generate all possible throws
	std::vector<Throw> allThrows;
	std::vector<Throw> doubles;

	// Singles
	for (int i = 1; i <= 20; ++i)
	{
		allThrows.push_back({ i, 1, "S" + std::to_string(i) });
	}
	allThrows.push_back({ 25, 1, "S25" }); // Outer Bull

	// Doubles
	for (int i = 1; i <= 20; ++i)
	{
		Throw t = { i * 2, 2, "D" + std::to_string(i) };
		allThrows.push_back(t);
		doubles.push_back(t);
	}
	doubles.push_back({ 50, 2, "D25" }); // Inner Bull
	allThrows.push_back({ 50, 2, "D25" });

	// Triples
	for (int i = 1; i <= 20; ++i)
	{
		allThrows.push_back({ i * 3, 3, "T" + std::to_string(i) });
	}

	int count = 0;
	int limit = 100;

	// A checkout consists of 1, 2, or 3 darts.
	// The last dart must be a double.

	// 1 dart: Just a double
	for (const auto &d : doubles)
	{
		if (d.score < limit)
		{
			count++;
		}
	}

	// 2 darts: Any throw + Double
	for (const auto &t1 : allThrows)
	{
		for (const auto &d : doubles)
		{
			if (t1.score + d.score < limit)
			{
				count++;
			}
		}
	}

	// 3 darts: Any throw + Any throw + Double
	// Order of first two throws does not matter for distinct checkouts.
	// e.g. T20 D20 D20 is same as D20 T20 D20?
	// Problem 109: "variations ... D1 D2 is different from D2 D1" ?
	// "Note that D1 D2 is considered different from D2 D1 as they finish on different doubles."
	// BUT "However, the combination S1 T1 D1 is considered the same as T1 S1 D1."
	// So order of first two darts does NOT matter.
	// Order of last dart matters (it defines the checkout).

	// We can iterate t1 from allThrows, and t2 from allThrows starting at index of t1.
	for (size_t i = 0; i < allThrows.size(); ++i)
	{
		for (size_t j = i; j < allThrows.size(); ++j)
		{
			for (const auto &d : doubles)
			{
				if (allThrows[i].score + allThrows[j].score + d.score < limit)
				{
					count++;
				}
			}
		}
	}

	return std::to_string(count);
}

void S109::Search(int index,
				  int currentScore,
				  int throwsCount,
				  int &count,
				  const std::vector<Throw> &allThrows,
				  const std::vector<Throw> &doubles)
{
	// Not used in this iterative approach
}

} // namespace ProjectEuler
