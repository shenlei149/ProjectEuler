#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S684 : public ISolution
{
public:
	std::string GetAnswer() override;
	int64_t S(int64_t f);
	int64_t GetRemainder(int64_t l);

private:
	int64_t Mod = 1000000007;
};
} // namespace ProjectEuler
