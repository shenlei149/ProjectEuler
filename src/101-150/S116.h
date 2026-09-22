#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S116 : public ISolution
{
public:
	std::string GetAnswer() override;
	int64_t GetRedCount();
	int64_t GetGreenCount();
	int64_t GetBlueCount();

private:
	int Layer = 50;
};
} // namespace ProjectEuler
