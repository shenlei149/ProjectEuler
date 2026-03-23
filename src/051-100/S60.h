#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S60 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	bool IsPrime(long long n);
	bool Check(long long a, long long b);
	void FindClique(std::vector<int> &clique, int startIdx, const std::vector<int> &primes, int &minSum);
};
} // namespace ProjectEuler
