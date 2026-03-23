#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S179 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int N = 10000000;
};
} // namespace ProjectEuler
