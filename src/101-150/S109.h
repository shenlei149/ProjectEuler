#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S109 : public ISolution
{
public:
	std::string GetAnswer() override;

	struct Throw
	{
		int score;
		int multiplier; // 1, 2, 3
		std::string name;
	};

	void Search(int index,
				int currentScore,
				int throwsCount,
				int &count,
				const std::vector<Throw> &allThrows,
				const std::vector<Throw> &doubles);
};
} // namespace ProjectEuler
