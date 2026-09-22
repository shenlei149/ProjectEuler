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
	void TryDelta(int64_t delta);
	int64_t GetMaxN(int64_t delta);
	std::vector<int64_t> StealthyNumbers;
	int64_t MAX = 100000000000000;
};
} // namespace ProjectEuler
