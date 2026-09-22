#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S35 : public ISolution
{
public:
	std::string GetAnswer() override;
	std::vector<int64_t> GetRotations(int64_t i);
	bool IsCircularPrime(int64_t prime, const std::vector<int64_t> &primes);
};
} // namespace ProjectEuler
