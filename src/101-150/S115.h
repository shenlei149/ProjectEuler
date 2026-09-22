#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S115 : public ISolution
{
public:
	std::string GetAnswer() override;
	int64_t F(int m, int n);
};
} // namespace ProjectEuler
