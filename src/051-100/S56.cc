#include "S56.h"
#include "../Utils.h"
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S56::GetAnswer()
{
	int maxSum = 0;
	for (int a = 1; a < 100; a++)
	{
		BigInt num(a);
		// Check if BigInt has Pow. If not, use loop.
		// Assuming Utils has Pow or similar.
		// If not, simply multiply.
		BigInt p(1);
		for (int b = 1; b < 100; b++)
		{
			p = p * num; // operator*
			string s = p.toString();
			int sum = 0;
			for (char c : s)
			{
				sum += c - '0';
			}
			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}
	return std::to_string(maxSum);
}
} // namespace ProjectEuler
