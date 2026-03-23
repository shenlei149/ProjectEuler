#pragma once
#include "../ISolution.h"
#include <set>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S93 : public ISolution
{
public:
	std::string GetAnswer() override;
	void GetTargets(std::vector<double> &numbers, std::set<int> &targets);
};
} // namespace ProjectEuler
