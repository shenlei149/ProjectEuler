#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S52 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool HasSpecifiedDigit(int number, int spec);
	bool HasZeroOrFive(int number);
	bool HasTwoOrThree(int number);
	bool HasFourOrFiveOrSix(int number);
	bool HasMoreThanSix(int number);
};
} // namespace ProjectEuler
