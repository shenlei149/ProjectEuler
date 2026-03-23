#include "S96.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S96::GetAnswer()
{
	std::stringstream ss(content);
	std::string token;
	long long sum = 0;

	while (ss >> token)
	{
		if (token == "Grid")
		{
			ss >> token; // Skip grid number

			int grid[9][9];
			for (int i = 0; i < 9; i++)
			{
				ss >> token;
				for (int j = 0; j < 9; j++)
				{
					grid[i][j] = token[j] - '0';
				}
			}

			if (Solve(grid))
			{
				int val = grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2];
				sum += val;
			}
		}
	}

	return std::to_string(sum);
}

bool S96::Solve(int grid[9][9])
{
	int row, col;
	if (!FindUnassignedLocation(grid, row, col))
	{
		return true; // success!
	}

	for (int num = 1; num <= 9; num++)
	{
		if (IsSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (Solve(grid))
			{
				return true;
			}
			grid[row][col] = 0;
		}
	}
	return false;
}

bool S96::FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool S96::IsSafe(int grid[9][9], int row, int col, int num)
{
	// Check row
	for (int c = 0; c < 9; c++)
	{
		if (grid[row][c] == num)
		{
			return false;
		}
	}

	// Check col
	for (int r = 0; r < 9; r++)
	{
		if (grid[r][col] == num)
		{
			return false;
		}
	}

	// Check box
	int boxStartRow = row - row % 3;
	int boxStartCol = col - col % 3;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (grid[r + boxStartRow][c + boxStartCol] == num)
			{
				return false;
			}
		}
	}

	return true;
}

} // namespace ProjectEuler
