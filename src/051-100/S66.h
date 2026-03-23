#pragma once
#include "../ISolution.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S66 : public ISolution
{
public:
	std::string GetAnswer() override;
	BigInt GetX(int n);
};
} // namespace ProjectEuler
