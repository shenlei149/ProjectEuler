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
	std::vector<long long> GetRotations(long long i);
	bool IsCircularPrime(long long prime, const std::vector<long long> &primes);
};
} // namespace ProjectEuler
