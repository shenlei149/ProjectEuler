#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S32 : public ISolution
{
public:
	std::string GetAnswer() override;
	// Helper function declaration fix
	int CharsToInt(const std::vector<char> &chars);
	bool IsPandigitalProduct(int i, std::vector<char> factorDigits);

private:
	std::map<std::string, std::set<int>> cache;
};
} // namespace ProjectEuler
