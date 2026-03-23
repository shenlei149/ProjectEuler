#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S27 : public ISolution
{
public:
	std::string GetAnswer() override;

	struct ABAndMaxPrime
	{
		int A;
		int B;
		int PrimeCount;
	};
};
} // namespace ProjectEuler
