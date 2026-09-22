#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S429 : public ISolution
{
public:
	std::string GetAnswer() override;
	int64_t PowMod(int64_t p, int k, int64_t m);
};
} // namespace ProjectEuler
