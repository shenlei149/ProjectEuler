#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S601 : public ISolution
{
public:
	std::string GetAnswer() override;
	long long P(int s, long long N);
};
} // namespace ProjectEuler
