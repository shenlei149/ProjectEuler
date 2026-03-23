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
class S110 : public ISolution
{
public:
	std::string GetAnswer() override;
	void Check(std::vector<int> power, int index);

private:
	int MAX = 4'000'000;
	std::vector<int> Primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	std::vector<int> MaxPower = { 9, 5, 4, 2, 2, 2, 1, 1, 1, 1, 1, 1 };
	BigInt min;

public:
	S110()
	{
		// Initialize min with a large value if BigInt supports it, or handle logic differently
		// Since BigInt might not have MaxValue, we can start with a valid candidate.
		// But for now, let's just leave it default constructed or set it in Solve/GetAnswer.
	}
};
} // namespace ProjectEuler
