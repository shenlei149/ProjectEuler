#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S347 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int64_t GetM(int64_t p, int64_t q, int64_t MAX);
};
} // namespace ProjectEuler
