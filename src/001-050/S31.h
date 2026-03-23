#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S31 : public ISolution
{
public:
	std::string GetAnswer() override;
	int CountCoins(int amount, int index);

private:
	std::vector<int> kindOfCoins;
};
} // namespace ProjectEuler
