#include "S47.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S47::GetAnswer()
{
	auto primes = Utils::GenPrimeSieve(200000);
	std::vector<long long> results;
	for (long long i = 646;; i++)
	{
		if (Utils::Factorize(i, primes).size() == 4)
		{
			results.push_back(i);
			if (results.size() == 4)
			{
				if (results[0] == results[1] - 1 && results[1] == results[2] - 1 && results[2] == results[3] - 1)
				{
					break;
				}
				else
				{
					results.erase(results.begin());
				}
			}
		}
		else
		{
			results.clear();
		}
	}

	return std::to_string(results[0]);
}

} // namespace ProjectEuler
