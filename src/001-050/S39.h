#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S39 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetSolutionCount(int p);
};
} // namespace ProjectEuler
