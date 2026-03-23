#include "S323.h"
#include "../Utils.h"
#include <iomanip>
#include <sstream>

using namespace std;

namespace ProjectEuler
{
std::string S323::GetAnswer()
{
	std::vector<Probability> probabilities;
	probabilities.emplace_back(0, 1);

	BigInt twoPow32 = Utils::Pow(2, 32);
	for (int i = 1;; i++)
	{
		auto baseDenominator = Utils::Pow(2, i);
		auto baseNumerator = baseDenominator - 1;
		auto lastBaseDenominator = Utils::Pow(2, i - 1);
		auto lastBaseNumerator = lastBaseDenominator - 1;
		auto denominator = Utils::Pow(baseDenominator, 32);
		auto numerator = Utils::Pow(baseNumerator, 32);
		auto lastNumerator = Utils::Pow(lastBaseNumerator, 32);

		probabilities.emplace_back(numerator - lastNumerator * twoPow32, denominator);

		if (probabilities[i].Denominator / probabilities[i].Numerator / (BigInt)i > Utils::Pow(10, 12))
		{
			break;
		}
	}

	BigInt ansDenominator = probabilities.back().Denominator;
	BigInt ansNumerator = 0;

	// We need to calculate sum( i * P_i )
	// P_i = probabilities[i].Numerator / probabilities[i].Denominator
	// ansNumerator = sum( i * probabilities[i].Numerator * (ansDenominator / probabilities[i].Denominator) )

	for (size_t i = 1; i < probabilities.size(); i++)
	{
		Probability current = probabilities[i];
		BigInt times = ansDenominator / current.Denominator;
		// times * current.Numerator * i
		ansNumerator += times * current.Numerator * (long long)i;
	}

	// Expected value = ansNumerator / ansDenominator.
	// Calculate ansNumerator * 10^10 / ansDenominator for 10 decimal places.
	BigInt times10 = (ansNumerator * 10000000000LL) / ansDenominator;

	// Convert to double.
	// times10 should fit in long long because answer is small ~6.35.
	// 6.35 * 10^10 ~ 6*10^10 < 9*10^18.

	// But BigInt might not have implicit conversion.
	// Assuming ToString() exists.
	std::string s = times10.ToString();
	long long val = std::stoll(s);

	double answer = (double)val / 10000000000.0;

	std::stringstream ss;
	ss << std::fixed << std::setprecision(10) << answer;
	return ss.str();
}

} // namespace ProjectEuler
