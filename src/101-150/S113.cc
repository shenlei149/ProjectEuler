#include "S113.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S113::GetAnswer()
{
	long long increasing = GetIncreasingCount();
	long long decreasing = GetDecreasingCount();

	return std::to_string((increasing + decreasing - 9 * Power));
}

long long S113::GetDecreasingCount()
{
	//          9,8,7...,2,1,0
	// 1 digits 1,1,1...,1,1,1
	// 2 digits
	// n digits
	std::vector<std::vector<long long>> matrix(Power, std::vector<long long>(10));
	long long total = 0;
	for (int i = 0; i < 10; i++)
	{
		matrix[0][i] = 1;
		total += 1; // 1-digit numbers
	}

	for (int i = 1; i < Power; i++)
	{
		long long count = 0;
		for (int j = 0; j < 10; j++)
		{
			count += matrix[i - 1][j];
			matrix[i][j] = count;
			total += count;
		}
	}
	return total - Power; // Remove "0" cases (0, 00, 000...)
}

long long S113::GetIncreasingCount()
{
	//          9,8,7...,3,2,1
	// 1 digits 1,1,1...,1,1,1
	// 2 digits
	// n digits
	std::vector<std::vector<long long>> matrix(Power, std::vector<long long>(9));
	long long total = 0;
	for (int i = 0; i < 9; i++)
	{
		matrix[0][i] = 1;
		total += 1;
	}

	for (int i = 1; i < Power; i++)
	{
		long long count = 0;
		for (int j = 0; j < 9; j++)
		{
			count += matrix[i - 1][j];
			matrix[i][j] = count;
			total += count;
		}
	}
	return total;
}

} // namespace ProjectEuler
