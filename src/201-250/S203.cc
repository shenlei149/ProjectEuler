#include "S203.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S203::GetAnswer()
{
	std::vector<std::vector<int64_t>> rows;
	rows.reserve(51);

	std::set<int64_t> distinctNumbers;

	for (int i = 0; i < 51; i++)
	{
		std::vector<int64_t> row(i + 1);
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
			{
				row[j] = 1;
			}
			else
			{
				const auto &lastRow = rows[i - 1];
				row[j] = lastRow[j - 1] + lastRow[j];
			}
			distinctNumbers.insert(row[j]);
		}
		rows.push_back(row);
	}

	if (distinctNumbers.empty())
	{
		return "0";
	}

	int64_t maxVal = *distinctNumbers.rbegin();
	int64_t primeLimit = (int64_t)std::sqrt(maxVal);

	auto primes = Utils::GenPrimes(primeLimit + 1);

	int64_t sum = 0;
	for (int64_t n : distinctNumbers)
	{
		bool isSquareFree = true;
		for (int64_t p : primes)
		{
			int64_t sq = p * p;
			if (sq > n)
			{
				break;
			}
			if (n % sq == 0)
			{
				isSquareFree = false;
				break;
			}
		}

		if (isSquareFree)
		{
			sum += n;
		}
	}

	return std::to_string(sum);
}

} // namespace ProjectEuler
