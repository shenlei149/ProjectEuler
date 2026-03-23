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
	std::vector<std::vector<long long>> rows;
	rows.reserve(51);

	std::set<long long> distinctNumbers;

	for (int i = 0; i < 51; i++)
	{
		std::vector<long long> row(i + 1);
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

	long long maxVal = *distinctNumbers.rbegin();
	long long primeLimit = (long long)std::sqrt(maxVal);

	auto primes = Utils::GenPrimes(primeLimit + 1);

	long long sum = 0;
	for (long long n : distinctNumbers)
	{
		bool isSquareFree = true;
		for (long long p : primes)
		{
			long long sq = p * p;
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
