#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S61 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	struct Node
	{
		int value;
		int type; // 3 to 8
	};

	std::vector<std::vector<int>> numbers; // numbers[type] = list of 4-digit numbers
	void GenerateNumbers();
	bool FindCycle(int lastValue, int count, int typeMask, int firstValue, int sum, int &result);
};
} // namespace ProjectEuler
