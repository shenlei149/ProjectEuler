#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S83 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool CanMoveToLeft(int point);
	bool CanMoveToRight(int point);
	bool CanUp(int point);
	bool CanDown(int point);

private:
	int dim = 80;
};
} // namespace ProjectEuler
