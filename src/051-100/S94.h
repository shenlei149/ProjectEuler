#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S94 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool Meet(long long a, long long c);
};
} // namespace ProjectEuler
