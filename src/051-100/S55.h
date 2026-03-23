#pragma once
#include "../BigInt.h"
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S55 : public ISolution
{
public:
	std::string GetAnswer() override;
	bool IsLychrel(BigInt number);
};
} // namespace ProjectEuler
