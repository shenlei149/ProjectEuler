#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S187 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	long long MAX = 100000000;
};
} // namespace ProjectEuler
