#include "S493.h"
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S493::GetAnswer()
{
	// 70 balls, 7 colors, 10 of each. Pick 20.
	// E[number of distinct colors] = sum_{c=1}^7 P(color c is chosen).
	// P(color c is chosen) = 1 - P(color c is NOT chosen).
	// Color c is NOT chosen if all 20 balls are from the other 60 balls.
	// P(c not chosen) = C(60, 20) / C(70, 20).
	// E = 7 * (1 - C(60, 20) / C(70, 20)).

	// Ratio = (60! / (20! 40!)) / (70! / (20! 50!))
	// = (60! 50!) / (40! 70!)
	// = (60! / 70!) * (50! / 40!)
	// = (50 * 49 * ... * 41) / (70 * 69 * ... * 61)

	double ratio = 1.0;
	for (int i = 0; i < 10; ++i)
	{
		ratio *= (50.0 - i) / (70.0 - i);
	}

	double expected = 7.0 * (1.0 - ratio);

	// 9 decimal places
	char buffer[64];
	snprintf(buffer, sizeof(buffer), "%.9f", expected);
	return std::string(buffer);
}
} // namespace ProjectEuler
