#include "S99.h"
#include "../Utils.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S99::GetAnswer()
{
	std::stringstream ss(baseexp);
	std::string token;

	double maxVal = -1.0;
	int maxIndex = -1;
	int currentIndex = 0;

	// The data is comma separated pairs, space separated?
	// "519432,525806 632382,518061"
	// operator>> will read "519432,525806"
	while (ss >> token)
	{
		size_t comma = token.find(',');
		if (comma == std::string::npos)
		{
			continue;
		}

		try
		{
			int base = std::stoi(token.substr(0, comma));
			int exp = std::stoi(token.substr(comma + 1));

			double val = exp * std::log10((double)base);
			if (val > maxVal)
			{
				maxVal = val;
				maxIndex = currentIndex;
			}
			currentIndex++;
		}
		catch (...)
		{
			// Ignore parse errors
		}
	}

	return std::to_string(maxIndex + 1);
}

} // namespace ProjectEuler
