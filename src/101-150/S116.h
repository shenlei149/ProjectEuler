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
	long long GetRedCount();
	long long GetGreenCount();
	long long GetBlueCount();

private:
	int Layer = 50;
};
} // namespace ProjectEuler
