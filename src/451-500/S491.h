#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S491 : public ISolution
{
public:
	std::string GetAnswer() override;
	long long GetPCount(std::vector<int> source);
	std::vector<int> GetRemainNumbers(std::vector<int> subtracter);

private:
	long long Factorial10 = 3628800;
};
} // namespace ProjectEuler
