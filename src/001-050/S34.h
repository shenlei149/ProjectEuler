#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S34 : public ISolution
{
public:
	std::string GetAnswer() override;
	int DigitFactorials(int n);

private:
	std::vector<int> factorials;
};
} // namespace ProjectEuler
