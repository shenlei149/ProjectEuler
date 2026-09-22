#pragma once
#include "../ISolution.h"
#include <string>

namespace ProjectEuler
{
class S719 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	bool CanBeSplit(int64_t n, int64_t target);
};
} // namespace ProjectEuler
