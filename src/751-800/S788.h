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
	int64_t Count(int D);
	int64_t GetCombinationsCountWithCache(int64_t total, int64_t pickedCount);

	int64_t Mod = 1000000007;
	int MaxD = 2022;
	std::vector<int64_t> Power9;
	std::vector<std::vector<int64_t>> cache;
};
} // namespace ProjectEuler
