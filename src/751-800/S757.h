#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S757 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	void TryDelta(long long delta);
	long long GetMaxN(long long delta);
	std::vector<long long> StealthyNumbers;
	long long MAX = 100000000000000;
};
} // namespace ProjectEuler
