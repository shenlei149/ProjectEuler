#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S51 : public ISolution
{
public:
	std::string GetAnswer() override;
	std::vector<std::vector<int>> HandleGroup(std::vector<int> primes, std::string pattern);

private:
	std::vector<std::string> patterns = { "110001", "101001", "100101", "100011", "011001",
										  "010101", "010011", "001101", "001011", "000111" };
};
} // namespace ProjectEuler
