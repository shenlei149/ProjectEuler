#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S64 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetPeriod(int S);
};
} // namespace ProjectEuler
