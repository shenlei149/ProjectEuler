#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S751 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int Length = 16;
};
} // namespace ProjectEuler
