#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S45 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int64_t N = 1000000;
};
} // namespace ProjectEuler
