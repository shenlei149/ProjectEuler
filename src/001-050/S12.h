#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S12 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetDivisorsCount(int number);
};
} // namespace ProjectEuler
