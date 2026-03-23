#include "S92.h"
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S92::GetAnswer()
{
	const int CACHE_SIZE = 600;
	bool arrives_89[CACHE_SIZE] = { false };

	// Fill cache
	for (int i = 1; i < CACHE_SIZE; i++)
	{
		int curr = i;
		while (curr != 1 && curr != 89)
		{
			int next = 0;
			while (curr > 0)
			{
				int d = curr % 10;
				next += d * d;
				curr /= 10;
			}
			curr = next;
		}
		if (curr == 89)
		{
			arrives_89[i] = true;
		}
	}

	int count = 0;
	for (int i = 1; i < 10000000; i++)
	{
		int curr = i;
		int next = 0;
		// Compute first step to reduce to < 600
		while (curr > 0)
		{
			int d = curr % 10;
			next += d * d;
			curr /= 10;
		}

		// Now next is < 600 (max 9*9*7 = 567)
		if (arrives_89[next])
		{
			count++;
		}
	}

	return std::to_string(count);
}
} // namespace ProjectEuler
