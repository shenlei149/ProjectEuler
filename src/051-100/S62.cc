#include "S62.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S62::GetAnswer()
{
	std::map<std::string, std::vector<long long>> cubeMapping;

	for (long long i = 1;; i++)
	{
		long long cube = i * i * i;
		std::string s = std::to_string(cube);
		std::sort(s.begin(), s.end());

		cubeMapping[s].push_back(cube);

		if (cubeMapping[s].size() == 5)
		{
			return std::to_string(cubeMapping[s][0]);
		}
	}
}
} // namespace ProjectEuler
