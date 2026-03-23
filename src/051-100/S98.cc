#include "S98.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S98::GetAnswer()
{
	// Parse words
	std::string data = literalWords; // from header
	// Remove quotes if present?
	// Header has: "A,ABILITY,..." (including quotes)
	if (data.size() > 1 && data.front() == '"')
	{
		data.erase(0, 1);
	}
	if (data.size() > 0 && data.back() == '"')
	{
		data.pop_back();
	}

	std::vector<std::string> words;
	std::stringstream ss(data);
	std::string segment;
	while (std::getline(ss, segment, ','))
	{
		words.push_back(segment);
	}

	// Group by anagram
	std::map<std::string, std::vector<std::string>> anagram_groups;
	for (const auto &w : words)
	{
		std::string sorted = w;
		std::sort(sorted.begin(), sorted.end());
		anagram_groups[sorted].push_back(w);
	}

	// Filter pairs
	std::vector<std::pair<std::string, std::string>> pairs;
	int max_len = 0;
	for (const auto &kv : anagram_groups)
	{
		if (kv.second.size() >= 2)
		{
			// Add all pairs
			for (size_t i = 0; i < kv.second.size(); i++)
			{
				for (size_t j = i + 1; j < kv.second.size(); j++)
				{
					pairs.push_back({ kv.second[i], kv.second[j] });
					if ((int)kv.second[i].length() > max_len)
					{
						max_len = kv.second[i].length();
					}
				}
			}
		}
	}

	// Precompute squares
	std::map<int, std::vector<long long>> squares_by_len;
	long long n = 1;
	while (true)
	{
		long long sq = n * n;
		std::string s = std::to_string(sq);
		if (s.length() > max_len)
		{
			break;
		}
		squares_by_len[s.length()].push_back(sq);
		n++;
	}

	long long max_square = 0;

	for (const auto &p : pairs)
	{
		std::string w1 = p.first;
		std::string w2 = p.second;
		int len = w1.length();

		const auto &candidates = squares_by_len[len];

		for (long long sq : candidates)
		{
			std::string s_sq = std::to_string(sq);

			// Try to map w1 to sq
			std::vector<int> char_map(26, -1);
			std::vector<int> digit_used(10, 0);
			bool possible = true;

			for (int i = 0; i < len; i++)
			{
				int digit = s_sq[i] - '0';
				int char_idx = w1[i] - 'A';

				if (char_map[char_idx] != -1)
				{
					if (char_map[char_idx] != digit)
					{
						possible = false;
						break;
					}
				}
				else
				{
					if (digit_used[digit])
					{
						possible = false;
						break;
					}
					char_map[char_idx] = digit;
					digit_used[digit] = 1;
				}
			}

			if (possible)
			{
				// Check w2
				long long num2 = 0;
				// Avoid leading zero for num2? Problem implies square number.
				// 1296 (CARE) -> RACE (9216).
				// If mapping results in leading zero, length decreases?
				// Problem says "we form a square number".
				// Usually squares don't start with 0.
				if (char_map[w2[0] - 'A'] == 0)
				{
					continue;
				}

				for (char c : w2)
				{
					num2 = num2 * 10 + char_map[c - 'A'];
				}

				// Check if num2 is square
				long long root = round(sqrt(num2));
				if (root * root == num2)
				{
					// Check length (no leading zeros meant num2 has same length)
					// Check if anagram relationship holds on digits?
					// w1 and w2 are anagrams.
					// char_map maps chars to digits.
					// So num1 and num2 must be digit anagrams.
					// This is guaranteed by construction.

					if (sq > max_square)
					{
						max_square = sq;
					}
					if (num2 > max_square)
					{
						max_square = num2;
					}
				}
			}
		}
	}

	return std::to_string(max_square);
}
} // namespace ProjectEuler
