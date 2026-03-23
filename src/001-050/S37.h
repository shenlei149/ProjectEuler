#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S37 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool IsTruncatablePrimes(int number);
};
} // namespace ProjectEuler
