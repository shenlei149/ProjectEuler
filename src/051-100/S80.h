#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S80 : public ISolution
{
public:
	std::string GetAnswer() override;
	int SqrtDigitSum(int n);
};
} // namespace ProjectEuler
