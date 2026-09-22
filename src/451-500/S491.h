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
	int64_t GetPCount(std::vector<int> source);
	std::vector<int> GetRemainNumbers(std::vector<int> subtracter);

private:
	int64_t Factorial10 = 3628800;
};
} // namespace ProjectEuler
