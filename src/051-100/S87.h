#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S87 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int MAX = 50000000;
};
} // namespace ProjectEuler
