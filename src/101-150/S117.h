#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S117 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int Layer = 50;
};
} // namespace ProjectEuler
