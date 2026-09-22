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
	int64_t P(int s, int64_t N);
};
} // namespace ProjectEuler
