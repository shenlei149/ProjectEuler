#include "S67.h"
#include "../Utils.h"
#include <algorithm>
#include <sstream>

using namespace std;

namespace ProjectEuler
{
std::string S67::GetAnswer()
{
	InitMatrix(triangle);
	ComputedSum();

	return std::to_string(GetMaxNumber());
}

int S67::GetMaxNumber()
{
	int max = 0;
	int height = matrix.size();
	if (height == 0)
	{
		return 0;
	}
	int width = matrix[height - 1].size();
	for (int i = 0; i < width; i++)
	{
		if (matrix[height - 1][i] > max)
		{
			max = matrix[height - 1][i];
		}
	}

	return max;
}

void S67::ComputedSum()
{
	// Bottom up? No, code was top down.
	// matrix[i, j] = max(matrix[i, j] + matrix[i-1, j-1], matrix[i, j] + matrix[i-1, j])
	// This modifies matrix in place.

	for (size_t i = 1; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++) // j can start at 0?
		{
			// Problem 67 is triangle.
			// Row 0: 1 elem. Row 1: 2 elems.
			// Element (i, j) can come from (i-1, j-1) or (i-1, j).
			// Boundary checks needed.

			int parent1 = 0;
			int parent2 = 0;

			if (j > 0 && j - 1 < matrix[i - 1].size())
			{
				parent1 = matrix[i - 1][j - 1];
			}
			// If j=0, parent1 is invalid (can't come from left-up).
			// But wait, it's max path sum.
			// Path valid moves: down-left or down-right?
			// Usually "adjacent numbers on the row below".
			// So (i,j) -> (i+1, j) or (i+1, j+1).
			// Reverse: (i,j) comes from (i-1, j) or (i-1, j-1).
			// If j=0, only from (i-1, 0).
			// If j=i, only from (i-1, i-1).

			if (j < matrix[i - 1].size())
			{
				parent2 = matrix[i - 1][j];
			}

			int val = matrix[i][j];

			// If valid parents exist, take max.
			// If j=0, parent2 is valid.
			// If j=i, parent1 is valid.
			// If 0 < j < i, both valid.

			int best = 0;
			if (j > 0)
			{
				best = max(best, parent1);
			}
			if (j < matrix[i - 1].size())
			{
				best = max(best, parent2);
			}

			matrix[i][j] = val + best;
		}
	}
}

void S67::InitMatrix(std::string data)
{
	std::stringstream ss(data);
	std::string line;
	matrix.clear();
	while (std::getline(ss, line))
	{
		if (line.empty())
		{
			continue;
		}
		std::vector<int> row;
		std::stringstream ssLine(line);
		int val;
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
