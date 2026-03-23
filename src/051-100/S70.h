#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S70 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool Meet(int i, std::vector<int> primes);
};
} // namespace ProjectEuler
