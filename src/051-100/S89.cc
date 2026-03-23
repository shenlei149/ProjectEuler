#include "S89.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S89::GetAnswer()
{
	std::stringstream ss(input);
	std::string segment;
	std::vector<std::string> words;

	// Split by whitespace (handling newlines etc)
	while (ss >> segment)
	{
		words.push_back(segment);
	}

	int saved_chars = 0;

	// Patterns to replace. Order matters (greedy).
	// DCCCC (5) -> CM (2) : save 3
	// LXXXX (5) -> XC (2) : save 3
	// VIIII (5) -> IX (2) : save 3
	// CCCC  (4) -> CD (2) : save 2
	// XXXX  (4) -> XL (2) : save 2
	// IIII  (4) -> IV (2) : save 2

	// Note: Regex.Replace in C# handles all occurrences.
	// std::regex_replace does too.

	std::regex pattern("DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII");

	for (const auto &word : words)
	{
		std::string replaced = std::regex_replace(word, pattern, "RR");
		saved_chars += (word.length() - replaced.length());
	}

	return std::to_string(saved_chars);
}
} // namespace ProjectEuler
