#include "S35.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S35::GetAnswer()
{
	int count = 0;
	auto primes = Utils::GenPrimeSieve(1000000);
	for (int i = 0; i < primes.size(); i++)
	{
		if (primes[i] != 0)
		{
			if (IsCircularPrime(primes[i], primes))
			{
				count++;
			}
		}
	}

	return std::to_string(count);
}

std::vector<int64_t> S35::GetRotations(int64_t i)
{
	std::string tmp = std::to_string(i);
	int length = tmp.size();
	tmp += tmp;

	std::vector<int64_t> rotations;
	for (int j = 0; j < length; j++)
	{
		rotations.push_back(std::stoll(tmp.substr(j, length)));
	}

	return rotations;
}

bool S35::IsCircularPrime(int64_t prime, const std::vector<int64_t> &primes)
{
	auto rotations = GetRotations(prime);

	for (auto i : rotations)
	{
		if (primes[i] == 0)
		{
			return false;
		}
	}

	return true;
}

} // namespace ProjectEuler
