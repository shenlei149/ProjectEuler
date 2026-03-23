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
	long long F(int m, int n);
};
} // namespace ProjectEuler
