#pragma once
#include "../ISolution.h"
#include <climits>
#include <string>
#include <vector>

namespace ProjectEuler
{
class S108 : public ISolution
{
public:
	std::string GetAnswer() override;
	void Search(int index, long long current_n, long long count, int limit, int max_exponent);

private:
	std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	long long min_n = LLONG_MAX;
};
} // namespace ProjectEuler
