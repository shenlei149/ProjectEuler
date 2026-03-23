#pragma once
#include "../ISolution.h"
#include <map>
#include <vector>

namespace ProjectEuler
{
class S74 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	std::map<int, int> cache;
	int GetChainLength(int n);
	int Factorial(int n);
};
} // namespace ProjectEuler
