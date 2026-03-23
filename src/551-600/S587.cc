#include "S587.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace ProjectEuler
{
std::string S587::GetAnswer()
{
	int n = 16;
	while (true)
	{
		double y = (n - std::sqrt(2 * n) + 1) / (n * n + 1);
		double x = y * n;
		double sTriangle = x * y / 2;
		double sTrapezoid = (y + 1) * (1 - x) / 2;
		double theta = std::atan((1 - x) / (1 - y));
		double sConcaveTriangle = sTriangle + sTrapezoid - theta / 2;
		double sL = 1 - M_PI / 4;
		if (sConcaveTriangle / sL < 0.001)
		{
			break;
		}

		n++;
	}

	return std::to_string(n);
}
} // namespace ProjectEuler
