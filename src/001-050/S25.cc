#include "S25.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S25::GetAnswer()
{
	BigInt f1 = 1;
	BigInt f2 = 1;
	int count = 2;
	while (true)
	{
		BigInt next = f1 + f2;
		count++;
		if (next.toString().size() == 1000)
		{
			return std::to_string(count);
		}

		f1 = f2;
		f2 = next;
	}
}

} // namespace ProjectEuler
