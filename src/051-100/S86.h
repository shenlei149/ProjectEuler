#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S86 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetCountByA(int a);
};
} // namespace ProjectEuler
