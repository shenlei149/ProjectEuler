#pragma once
#include "../BigInt.h"
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S323 : public ISolution
{
public:
	std::string GetAnswer() override;

	struct Probability
	{
		BigInt Numerator;
		BigInt Denominator;

		Probability(BigInt n, BigInt d)
			: Numerator(n)
			, Denominator(d)
		{}
	};
};
} // namespace ProjectEuler
