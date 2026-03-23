#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S78 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int MOD = 1000000;
};
} // namespace ProjectEuler
