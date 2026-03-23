#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S329 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	std::vector<int> primes;
	std::string croaks = "PPPPNNPPPNPPNPN";
};
} // namespace ProjectEuler
