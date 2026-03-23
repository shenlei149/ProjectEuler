#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S14 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetChainLength(long long number);

private:
	std::vector<int> termsLength;
};
} // namespace ProjectEuler
