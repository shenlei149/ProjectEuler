#include "S114.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S114::GetAnswer()
{
	// reds[red_length][position]
	// red_length: 0 for grey, >0 for red block of that length ending at position
	// position: 0 to Layer-1

	// C# `new long long[RedBlockLength + 1, Layer]`
	// Dimensions: [51][50]

	int rows = RedBlockLength + 1;
	int cols = Layer;

	std::vector<std::vector<long long>> reds(rows, std::vector<long long>(cols, 0));

	// Base case at pos 0
	reds[0][0] = 1; // 1 grey
	reds[1][0] = 1; // 1 red (start of red block)
	// Others 0 by default

	for (int layer = 1; layer < cols; layer++)
	{
		// Calculate reds[0][layer] (grey at current pos)
		// Previous can be grey (0) or red block of length >= 3
		long long count = 0;

		// From grey
		count += reds[0][layer - 1];

		// From red >= 3
		for (int r = 3; r < rows; r++)
		{
			count += reds[r][layer - 1];
		}

		reds[0][layer] = count;

		// Calculate reds[r][layer] for r >= 1
		// Extend red block
		for (int r = 1; r < rows; r++)
		{
			reds[r][layer] = reds[r - 1][layer - 1];
		}
	}

	// Result is sum of valid states at last layer
	// Valid states: grey or red block >= 3
	long long result = 0;
	result += reds[0][cols - 1];
	for (int r = 3; r < rows; r++)
	{
		result += reds[r][cols - 1];
	}

	return std::to_string(result);
}
} // namespace ProjectEuler
