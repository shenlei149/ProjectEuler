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
	long long S(long long f);
	long long GetRemainder(long long l);

private:
	long long Mod = 1000000007;
};
} // namespace ProjectEuler
