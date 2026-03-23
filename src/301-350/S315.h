#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S315 : public ISolution
{
public:
	std::string GetAnswer() override;
	int Overlap[10][10];
	int GetCount(int p);
	int GetCount(int num1, int num2);
};
} // namespace ProjectEuler
