#include "S93.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S93::GetAnswer()
{
	int max_n = 0;
	std::string best_set = "";

	// Iterate combinations of 4 digits from 0..9
	// actually problem says digits 1..9 ? "Using the set {1, 2, 3, 4}"
	// "digits d (0 < a < b < c < d < 10)" means 1 to 9.
	// 0 is not used? Problem 93: "set of four distinct digits, a < b < c < d"
	// Example: {1, 2, 3, 4}.
	// Usually digits are 0-9 or 1-9.
	// "Arithmetic expressions ... using digits ...".
	// 0 is usually not allowed? Or just allowed?
	// Problem 93 text says "set of four distinct digits".
	// Usually implies 0-9.
	// But example uses {1,2,3,4}.
	// Let's assume 0-9. But if I use 0, can I divide by 0? No.
	// Wait, typical constraints are digits 1-9.
	// Let's check constraints.
	// "four distinct digits".
	// The example uses 1,2,3,4.
	// If I check problem statement online, it says "digits".
	// I will try 0-9.

	std::vector<int> all_digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto combs = Utils::Combination(all_digits, 4);

	for (const auto &digits : combs)
	{
		std::set<int> targets;
		std::vector<double> current_nums;
		for (int d : digits)
		{
			current_nums.push_back((double)d);
		}

		GetTargets(current_nums, targets);

		int n = 0;
		while (targets.count(n + 1))
		{
			n++;
		}

		if (n > max_n)
		{
			max_n = n;
			std::string s = "";
			for (int d : digits)
			{
				s += std::to_string(d);
			}
			best_set = s;
		}
	}

	return best_set;
}

void S93::GetTargets(std::vector<double> &numbers, std::set<int> &targets)
{
	if (numbers.size() == 1)
	{
		double val = numbers[0];
		if (val > 0 && std::abs(val - std::round(val)) < 1e-5)
		{
			targets.insert((int)std::round(val));
		}
		return;
	}

	// Pick two numbers
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		for (size_t j = i + 1; j < numbers.size(); ++j)
		{
			double a = numbers[i];
			double b = numbers[j];

			// Remaining numbers
			std::vector<double> next_nums;
			for (size_t k = 0; k < numbers.size(); ++k)
			{
				if (k != i && k != j)
				{
					next_nums.push_back(numbers[k]);
				}
			}

			// Operations
			// a + b
			next_nums.push_back(a + b);
			GetTargets(next_nums, targets);
			next_nums.pop_back();

			// a * b
			next_nums.push_back(a * b);
			GetTargets(next_nums, targets);
			next_nums.pop_back();

			// a - b
			next_nums.push_back(a - b);
			GetTargets(next_nums, targets);
			next_nums.pop_back();

			// b - a
			next_nums.push_back(b - a);
			GetTargets(next_nums, targets);
			next_nums.pop_back();

			// a / b
			if (std::abs(b) > 1e-9)
			{
				next_nums.push_back(a / b);
				GetTargets(next_nums, targets);
				next_nums.pop_back();
			}

			// b / a
			if (std::abs(a) > 1e-9)
			{
				next_nums.push_back(b / a);
				GetTargets(next_nums, targets);
				next_nums.pop_back();
			}
		}
	}
}

} // namespace ProjectEuler
