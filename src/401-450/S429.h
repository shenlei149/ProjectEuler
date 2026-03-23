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
	long long PowMod(long long p, int k, long long m);
};
} // namespace ProjectEuler
