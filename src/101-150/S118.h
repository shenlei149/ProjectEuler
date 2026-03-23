#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S118 : public ISolution
{
public:
	std::string GetAnswer() override;
	void GenSets(const std::vector<int> &elements, int length, int lastLength, int &count);
	void GenPrimes(int value, int length, const std::vector<long long> &primes);

private:
	std::vector<std::vector<int>> unique;
	std::vector<int> pow10 = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
};
} // namespace ProjectEuler
