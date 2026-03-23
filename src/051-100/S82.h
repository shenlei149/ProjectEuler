#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S82 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int dim = 80;
};
} // namespace ProjectEuler
