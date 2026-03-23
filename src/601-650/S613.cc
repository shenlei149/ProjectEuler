#include "S613.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace ProjectEuler
{
std::string S613::GetAnswer()
{
	// Formula from old code:
	// p = 0.5 + Log(Sqrt(0.6) * Pow(3, 4) * Pow(4, 8) / Pow(5, 12)) / 12 / PI;

	// Log(a * b / c) = Log(a) + Log(b) - Log(c).
	// Sqrt(0.6) = 0.6^0.5. Log = 0.5 * Log(0.6).
	// Pow(3,4). Log = 4 * Log(3).
	// Pow(4,8). Log = 8 * Log(4).
	// Pow(5,12). Log = 12 * Log(5).

	double term = 0.5 * std::log(0.6) + 4.0 * std::log(3.0) + 8.0 * std::log(4.0) - 12.0 * std::log(5.0);
	double p = 0.5 + term / (12.0 * M_PI);

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(10) << p;
	return oss.str();
}
} // namespace ProjectEuler
