#pragma once
#include "../ISolution.h"
#include <string>

namespace ProjectEuler
{
class S820 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int D(int k);
	int PowerMod(int baseValue, int exponent, int modulus);
	int MAX = 10000000;
};
} // namespace ProjectEuler
