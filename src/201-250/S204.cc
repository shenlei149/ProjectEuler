#include "S204.h"

#include <vector>

#include "../Utils.h"

namespace ProjectEuler
{

namespace
{

int64_t GetValue(const std::vector<int32_t> &powers, const std::vector<int64_t> &primes)
{
	int64_t value = 1;
	for (size_t i = 0; i < powers.size(); ++i)
	{
		for (int32_t j = 0; j < powers[i]; ++j)
		{
			value *= primes[i];
		}
	}
	return value;
}

} // namespace

constexpr int32_t Type { 100 };
constexpr int64_t Max { 1'000'000'000 };

std::string S204::GetAnswer()
{
	auto primes = Utils::GenPrimes(Type + 1);

	std::vector<int32_t> powers(primes.size(), 0);
	int32_t count = 1;
	int64_t value = 1;
	while (true)
	{
		// Advance the least significant power that can be increased
		powers[0]++;
		value *= primes[0];

		if (value > Max)
		{
			// Reset the value and increment the next power
			for (size_t i = 0; i < powers.size(); ++i)
			{
				powers[i] = 0;
				if (i + 1 < powers.size())
				{
					powers[i + 1]++;
				}
				else
				{
					return std::to_string(count);
				}
				value = GetValue(powers, primes);
				if (value <= Max)
				{
					break;
				}
			}
		}

		count++;
	}

	return std::string {};
}

} // namespace ProjectEuler
