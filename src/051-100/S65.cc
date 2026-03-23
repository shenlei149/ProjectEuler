#include "S65.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S65::GetAnswer()
{
	BigInt h2(0);
	BigInt h1(1);
	BigInt h(0);

	for (int i = 0; i < 100; i++)
	{
		long long a;
		if (i == 0)
		{
			a = 2;
		}
		else
		{
			if (i % 3 == 2)
			{
				a = 2 * (i / 3 + 1);
			}
			else
			{
				a = 1;
			}
		}

		BigInt bigA(a);
		h = bigA * h1 + h2;
		h2 = h1;
		h1 = h;
	}

	string s = h.toString();
	int sum = 0;
	for (char c : s)
	{
		sum += c - '0';
	}

	return std::to_string(sum);
}
} // namespace ProjectEuler
