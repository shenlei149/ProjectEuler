#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S504 : public ISolution
{
public:
	std::string GetAnswer() override;
	int GetNumberOfVector(int a, int b, int c, int d);
	int GetInsideVector(int a, int b);

private:
	int M = 100;
	std::vector<std::vector<int>> NumbersOfInsideVector;
};
} // namespace ProjectEuler
