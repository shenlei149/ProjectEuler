#include "S115.h"
#include "../Utils.h"
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S115::GetAnswer()
{
	int n = 50;
	while (true)
	{
		int64_t res = F(50, n);
		if (res > 1000000)
		{
			break;
		}

		n++;
	}

	return std::to_string(n);
}

int64_t S115::F(int m, int n)
{
	int Layer = n;
	int RedBlockLength = Layer;

	// Color: grey[0] or red[1:RedBlockLength]; Layer
	// dimensions: [RedBlockLength + 1][Layer]
	// In C# it was new int64_t[RedBlockLength + 1, Layer]
	// Access was reds[red, layer]
	// So first dim is red length, second is layer index.

	// However, layers are 0 to Layer-1?
	// In loop: layer < Layer. Access layer-1.
	// reds[0, layer] = count.

	// Let's use vector<vector<int64_t>> reds(RedBlockLength + 1, vector<int64_t>(Layer + 1, 0));
	// To be safe with indices.

	vector<vector<int64_t>> reds(RedBlockLength + 1, vector<int64_t>(Layer + 1, 0));

	// Original: reds[0, 0] = 1; reds[1, 0] = 1;
	reds[0][0] = 1;
	reds[1][0] = 1;
	// other reds[i][0] are 0 by init.

	for (int layer = 1; layer < Layer; layer++)
	{
		int64_t count = 0;
		for (int red = m; red <= RedBlockLength; red++)
		{
			count += reds[red][layer - 1];
		}
		count += reds[0][layer - 1]; // add #grey

		reds[0][layer] = count;

		for (int red = 1; red <= RedBlockLength; red++)
		{
			reds[red][layer] = reds[red - 1][layer - 1];
		}
	}

	int64_t result = 0;
	for (int red = m; red <= RedBlockLength; red++)
	{
		result += reds[red][Layer - 1];
	}
	result += reds[0][Layer - 1]; // add #grey

	return result;
}

} // namespace ProjectEuler
