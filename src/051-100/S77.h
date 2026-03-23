#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S77 : public ISolution
{
public:
	std::string GetAnswer() override;
	int Count(int sum, std::vector<int> primes);
	int Count(int sum, int index, std::vector<int> primes);

private:
	int Max = 5000;
};
} // namespace ProjectEuler
