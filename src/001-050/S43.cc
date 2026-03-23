#include "S43.h"
#include "../Utils.h"
#include <cstdio>
#include <numeric>
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S43::GetAnswer()
{
	std::vector<std::string> pandigitals;
	for (int i = 0; i <= 999; ++i)
	{
		if (i % 17 == 0)
		{
			char buf[10];
			sprintf(buf, "%03d", i);
			std::string s(buf);
			if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2])
			{
				pandigitals.push_back(s);
			}
		}
	}

	std::vector<int> divisors = { 13, 11, 7, 5, 3, 2 };

	for (int div : divisors)
	{
		std::vector<std::string> next_pandigitals;
		for (const auto &s : pandigitals)
		{
			for (char c = '0'; c <= '9'; ++c)
			{
				if (s.find(c) == std::string::npos)
				{
					std::string num_str = "";
					num_str += c;
					num_str += s.substr(0, 2);
					int num = std::stoi(num_str);
					if (num % div == 0)
					{
						next_pandigitals.push_back(c + s);
					}
				}
			}
		}
		pandigitals = next_pandigitals;
	}

	long long sum = 0;
	for (const auto &s : pandigitals)
	{
		for (char c = '0'; c <= '9'; ++c)
		{
			if (s.find(c) == std::string::npos)
			{
				std::string full = c + s;
				sum += std::stoll(full);
			}
		}
	}

	return std::to_string(sum);
}

} // namespace ProjectEuler
