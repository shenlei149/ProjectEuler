#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S174 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	const int N = 1000000;
};
} // namespace ProjectEuler
