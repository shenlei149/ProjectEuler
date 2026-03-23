#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S938 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	double GetPBy(int red, int black);

	int RED = 24690;
	int BLACK = 12345;
	// p[r][b]
	// Use vector of vectors
	std::vector<std::vector<double>> p;
};
} // namespace ProjectEuler
