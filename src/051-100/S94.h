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
	bool Meet(int64_t a, int64_t c);
};
} // namespace ProjectEuler
