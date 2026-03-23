#include "S81.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S81::GetAnswer()
{
	InitMatrix(matrixStr);

	if (matrix.empty())
	{
		return "0";
	}
	int rows = matrix.size();
	int cols = matrix[0].size();

	// Use DP to find min path sum
	// matrix[i][j] += min(matrix[i-1][j], matrix[i][j-1])

	// We can update in place
	// First row: only from left
	for (int j = 1; j < cols; j++)
	{
		matrix[0][j] += matrix[0][j - 1];
	}

	// First col: only from up
	for (int i = 1; i < rows; i++)
	{
		matrix[i][0] += matrix[i - 1][0];
	}

	// Rest
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			matrix[i][j] += std::min(matrix[i - 1][j], matrix[i][j - 1]);
		}
	}

	return std::to_string(matrix[rows - 1][cols - 1]);
}

void S81::InitMatrix(std::string data)
{
	matrix.clear();
	std::stringstream ss(data);
	std::string line;

	while (std::getline(ss, line))
	{
		if (line.empty())
		{
			continue;
		}

		// Replace commas with spaces
		for (char &c : line)
		{
			if (c == ',')
			{
				c = ' ';
			}
		}

		std::stringstream ssLine(line);
		int val;
		std::vector<int> row;
		while (ssLine >> val)
		{
			row.push_back(val);
		}
		if (!row.empty())
		{
			matrix.push_back(row);
		}
	}
}

} // namespace ProjectEuler
