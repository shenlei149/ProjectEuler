#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S206 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool HasRightForm(long long i);
};
} // namespace ProjectEuler
