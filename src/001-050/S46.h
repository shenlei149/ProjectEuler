#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S46 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool IsGoldbachNumber(int number);
};
} // namespace ProjectEuler
