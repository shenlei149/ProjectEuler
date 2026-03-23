#include "S66.h"
#include "../Utils.h"
#include <cmath>

using namespace std;

namespace ProjectEuler
{
BigInt S66::GetX(int D)
{
	int limit = sqrt(D);
	if (limit * limit == D)
	{
		return BigInt(0);
	}

	long long m_int = 0;
	long long d_int = 1;
	long long a0_int = limit;
	long long a_int = limit;

	BigInt h_prev2(0);
	BigInt h_prev(1);

	BigInt k_prev2(1);
	BigInt k_prev(0);

	while (true)
	{
		BigInt bigA(a_int);

		BigInt h = bigA * h_prev + h_prev2;
		BigInt k = bigA * k_prev + k_prev2;

		BigInt x = h;
		BigInt y = k;
		BigInt D_big(D);

		BigInt lhs = x * x;
		BigInt rhs = D_big * y * y;

		if (lhs > rhs)
		{
			BigInt res = lhs - rhs;
			if (res.toString() == "1")
			{
				return x;
			}
		}

		m_int = d_int * a_int - m_int;
		d_int = (D - m_int * m_int) / d_int;
		a_int = (a0_int + m_int) / d_int;

		h_prev2 = h_prev;
		h_prev = h;
		k_prev2 = k_prev;
		k_prev = k;
	}
}

std::string S66::GetAnswer()
{
	BigInt maxX(0);
	int resultD = 0;

	for (int D = 2; D <= 1000; D++)
	{
		BigInt x = GetX(D);
		if (x.toString() != "0")
		{
			if (x.toString().length() > maxX.toString().length())
			{
				maxX = x;
				resultD = D;
			}
			else if (x.toString().length() == maxX.toString().length())
			{
				if (x.toString() > maxX.toString())
				{
					maxX = x;
					resultD = D;
				}
			}
		}
	}
	return std::to_string(resultD);
}
} // namespace ProjectEuler
