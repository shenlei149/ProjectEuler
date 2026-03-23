#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S112 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool IsBouncy(int number);
};
} // namespace ProjectEuler
