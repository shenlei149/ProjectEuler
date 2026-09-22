#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S853 : public ISolution
{
public:
	std::string GetAnswer() override;

private:
	int64_t ToLong(const std::vector<int> &power);
	bool Next(std::vector<int> &power, int64_t &n);
	bool Period120(int64_t n);

	std::vector<int> bases = { 2, 3, 5, 7, 11, 31, 41, 61, 2521 };
	std::vector<int> max_powers = { 3, 1, 1, 1, 1, 1, 1, 1, 1 }; // Derived or assumed max power
	// Actually code iterated until > N.

	int64_t N = 1000000000LL;
	// f120 can be larger than N?
	// We only care about n < N.

	// Cache for period check
	// We need array of size > 120.
	int64_t f[130];
};
} // namespace ProjectEuler
