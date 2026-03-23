#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S11 : public ISolution
{
	static int matrix[20][20];
	static void InitMatrix();
	static int GetHorizontalMaxProduct();
	static int GetVerticalMaxProduct();
	static int GetDiagonalMaxProduct();

public:
	std::string GetAnswer() override;
};
} // namespace ProjectEuler
