#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S125 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int MAX = 100000000;
};
} // namespace ProjectEuler
