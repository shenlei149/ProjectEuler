#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S75 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int64_t L = 1500000;
};
} // namespace ProjectEuler
