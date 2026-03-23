#include "S29.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S29::GetAnswer()
{
	std::set<std::string> results;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= 100; j++)
		{
			results.insert(Utils::Pow(i, j).toString());
		}
	}

	return std::to_string(results.size());
}

} // namespace ProjectEuler
