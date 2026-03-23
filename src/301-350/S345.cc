#include "S345.h"
#include "../Utils.h"
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S345::GetAnswer()
{
	Init();
	InitMaxNumber();

	vector<int> columns(MatrixLength, -1);
	MaxSum = 0;

	for (int searchTo = 0; searchTo < MatrixLength; searchTo++)
	{
		SearchMaxSum(0, columns, searchTo);
	}

	return std::to_string(MaxSum);
}

void S345::SearchMaxSum(int row, std::vector<int> &columns, int searchTo)
{
	// Calculate current sum of assigned columns 0..row-1
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		sum += matrix[i][columns[i]];
	}

	if (row == searchTo + 1)
	{
		if (sum > MaxSum)
		{
			MaxSum = sum;
		}
	}
	else
	{
		// Pruning: Calculate possible max sum if we continue
		// sum so far + sum of max possible values for remaining rows (row..searchTo)
		int possibleMax = sum;
		for (int curRow = row; curRow <= searchTo; curRow++)
		{
			possibleMax += MaxNumber[curRow];
		}

		if (possibleMax <= MaxSum)
		{
			return;
		}

		for (int col = 0; col < MatrixLength; col++)
		{
			// Check if col is already used in 0..row-1
			bool used = false;
			for (int i = 0; i < row; i++)
			{
				if (columns[i] == col)
				{
					used = true;
					break;
				}
			}

			if (!used)
			{
				columns[row] = col;
				SearchMaxSum(row + 1, columns, searchTo);
			}
		}
	}
}

// Helpers removed, integrated.
bool S345::CheckValid(std::vector<int> columns, int row, int col) { return false; }

int S345::GetSum(std::vector<int> columns, int row) { return 0; }

void S345::InitMaxNumber()
{
	MaxNumber.assign(MatrixLength, 0);
	for (int i = 0; i < MatrixLength; i++)
	{
		int max_val = 0;
		for (int j = 0; j < MatrixLength; j++)
		{
			if (matrix[i][j] > max_val)
			{
				max_val = matrix[i][j];
			}
		}
		MaxNumber[i] = max_val;
	}
}

void S345::Init()
{
	matrix.assign(MatrixLength, vector<int>(MatrixLength));
	stringstream ss(Data);
	int val;
	int count = 0;
	while (ss >> val)
	{
		matrix[count / MatrixLength][count % MatrixLength] = val;
		count++;
	}
}

} // namespace ProjectEuler
