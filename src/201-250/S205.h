#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S205 : public ISolution
{
public:
	std::string GetAnswer() override;
	void GenPeterResults(std::string num, int nth);
	void GenColinResults(std::string num, int nth);

private:
	std::vector<std::string> PeterResults;
	std::vector<std::string> ColinResults;
};
} // namespace ProjectEuler
