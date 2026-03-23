#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S932 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	bool Is2005Number(long long root, long long square);
	long long RootUpper = 100000000 - 1; // 10^8 - 1? Code said 100_000_000 - 1
	std::vector<long long> POW;
};
} // namespace ProjectEuler
