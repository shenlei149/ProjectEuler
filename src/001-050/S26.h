#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S26 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetRecurringCycle(int n, int m);
};
} // namespace ProjectEuler
