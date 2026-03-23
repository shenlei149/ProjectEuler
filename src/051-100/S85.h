#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S85 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int N = 2000000;
};
} // namespace ProjectEuler
