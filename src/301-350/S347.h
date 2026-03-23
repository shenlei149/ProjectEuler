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
	long long GetM(long long p, long long q, long long MAX);
};
} // namespace ProjectEuler
