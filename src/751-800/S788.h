#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S788 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	long long Count(int D);
	long long GetCombinationsCountWithCache(long long total, long long pickedCount);

	long long Mod = 1000000007;
	int MaxD = 2022;
	std::vector<long long> Power9;
	std::vector<std::vector<long long>> cache;
};
} // namespace ProjectEuler
