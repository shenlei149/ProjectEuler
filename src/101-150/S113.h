#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S113 : public ISolution
{
public:
	std::string GetAnswer() override;
	int64_t GetDecreasingCount();
	int64_t GetIncreasingCount();

private:
	int Power = 100;
};
} // namespace ProjectEuler
