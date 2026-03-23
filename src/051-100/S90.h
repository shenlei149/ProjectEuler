#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S90 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool Check(const std::vector<int> &d1, const std::vector<int> &d2);
};
} // namespace ProjectEuler
