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
	bool CanBeSplit(long long n, long long target);
};
} // namespace ProjectEuler
