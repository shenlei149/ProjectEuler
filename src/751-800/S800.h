#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S800 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	// int M = 800;
	int M = 800800;
};
} // namespace ProjectEuler
