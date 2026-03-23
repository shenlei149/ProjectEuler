#include "S84.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S84::GetAnswer()
{
	int sides = 4;
	int pos = 0;
	int doubles = 0;
	std::vector<int> visits(40, 0);
	int limit = 1000000;

	std::mt19937 rng(12345);
	std::uniform_int_distribution<int> dist(1, sides);

	std::vector<int> ccCards(16);
	std::vector<int> chCards(16);
	for (int i = 0; i < 16; i++)
	{
		ccCards[i] = i;
	}
	for (int i = 0; i < 16; i++)
	{
		chCards[i] = i;
	}
	std::shuffle(ccCards.begin(), ccCards.end(), rng);
	std::shuffle(chCards.begin(), chCards.end(), rng);

	int ccIdx = 0;
	int chIdx = 0;

	for (int i = 0; i < limit; i++)
	{
		int d1 = dist(rng);
		int d2 = dist(rng);

		if (d1 == d2)
		{
			doubles++;
		}
		else
		{
			doubles = 0;
		}

		if (doubles == 3)
		{
			pos = 10;
			doubles = 0;
		}
		else
		{
			pos = (pos + d1 + d2) % 40;

			if (pos == 30)
			{
				pos = 10; // G2J
			}

			// CC
			if (pos == 2 || pos == 17 || pos == 33)
			{
				int card = ccCards[ccIdx];
				ccIdx = (ccIdx + 1) % 16;
				if (card == 0)
				{
					pos = 0;
				}
				else if (card == 1)
				{
					pos = 10;
				}
			}

			// CH
			if (pos == 7 || pos == 22 || pos == 36)
			{
				int card = chCards[chIdx];
				chIdx = (chIdx + 1) % 16;
				if (card == 0)
				{
					pos = 0;
				}
				else if (card == 1)
				{
					pos = 10;
				}
				else if (card == 2)
				{
					pos = 11;
				}
				else if (card == 3)
				{
					pos = 24;
				}
				else if (card == 4)
				{
					pos = 39;
				}
				else if (card == 5)
				{
					pos = 5;
				}
				else if (card == 6 || card == 7)
				{
					if (pos == 7)
					{
						pos = 15;
					}
					else if (pos == 22)
					{
						pos = 25;
					}
					else if (pos == 36)
					{
						pos = 5;
					}
				}
				else if (card == 8)
				{
					if (pos == 7)
					{
						pos = 12;
					}
					else if (pos == 22)
					{
						pos = 28;
					}
					else if (pos == 36)
					{
						pos = 12;
					}
				}
				else if (card == 9)
				{
					pos = (pos - 3 + 40) % 40;
				}
			}
		}
		if (pos == 30)
		{
			pos = 10;
		}
		visits[pos]++;
	}

	std::vector<std::pair<int, int>> sorted;
	for (int i = 0; i < 40; i++)
	{
		sorted.push_back({ visits[i], i });
	}
	std::sort(sorted.rbegin(), sorted.rend());

	std::string res = "";
	for (int i = 0; i < 3; i++)
	{
		if (sorted[i].second < 10)
		{
			res += "0";
		}
		res += std::to_string(sorted[i].second);
	}
	return res;
}
} // namespace ProjectEuler
