#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S120 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetMaxRByA(int a);
};
} // namespace ProjectEuler
