#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S173 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int N = 1000000;
	// int N = 100;
};
} // namespace ProjectEuler
