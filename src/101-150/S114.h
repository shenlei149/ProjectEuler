#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S114 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int Layer = 50;
	int RedBlockLength = Layer;
};
} // namespace ProjectEuler
