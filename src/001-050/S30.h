#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S30 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool IsPowerNumber(int number, int power);
};
} // namespace ProjectEuler
