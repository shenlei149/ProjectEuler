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
	bool Is2005Number(int64_t root, int64_t square);
	int64_t RootUpper = 100000000 - 1; // 10^8 - 1? Code said 100_000_000 - 1
	std::vector<int64_t> POW;
};
} // namespace ProjectEuler
