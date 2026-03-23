#include "S82.h"
#include "Matrix81.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S82::GetAnswer()
{
	// 80x80 matrix
	const auto &matrix = MATRIX_81;
	int rows = matrix.size();
	if (rows == 0)
	{
		return "0";
	}
	int cols = matrix[0].size();

	// DP state: min cost to reach (i, j)
	// We process column by column
	std::vector<long long> col_costs(rows);

	// Initialize with first column
	for (int i = 0; i < rows; ++i)
	{
		col_costs[i] = matrix[i][0];
	}

	for (int j = 1; j < cols; ++j)
	{
		// Step 1: Move right from previous column
		for (int i = 0; i < rows; ++i)
		{
			col_costs[i] += matrix[i][j];
		}

		// Step 2: Sweep down (check if coming from above is cheaper)
		for (int i = 1; i < rows; ++i)
		{
			col_costs[i] = std::min(col_costs[i], col_costs[i - 1] + matrix[i][j]);
		}

		// Step 3: Sweep up (check if coming from below is cheaper)
		for (int i = rows - 2; i >= 0; --i)
		{
			col_costs[i] = std::min(col_costs[i], col_costs[i + 1] + matrix[i][j]);
		}
	}

	long long min_path = col_costs[0];
	for (int i = 1; i < rows; ++i)
	{
		min_path = std::min(min_path, col_costs[i]);
	}

	return std::to_string(min_path);
}
} // namespace ProjectEuler
