#include "S40.h"
#include "../Utils.h"
#include <string>

using namespace std;

namespace ProjectEuler
{
std::string S40::GetAnswer()
{
	std::string sb = ".";
	for (int i = 1;; i++)
	{
		sb += std::to_string(i);
		if (sb.size() > 1000000)
		{
			break;
		}
	}

	int answer = (sb[1] - '0') * (sb[10] - '0') * (sb[100] - '0') * (sb[1000] - '0') * (sb[10000] - '0') *
				 (sb[100000] - '0') * (sb[1000000] - '0');

	return std::to_string(answer);
}

} // namespace ProjectEuler
