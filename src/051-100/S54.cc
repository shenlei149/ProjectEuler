#include "S54.h"
#include "../Utils.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

namespace ProjectEuler
{

std::string S54::GetAnswer()
{
	// Data is in pokers1000 member variable
	std::string data = pokers1000;
	std::vector<std::string> lines;
	std::string line;
	for (char c : data)
	{
		if (c == '\n')
		{
			if (!line.empty())
			{
				if (line.back() == '\r')
				{
					line.pop_back();
				}
				lines.push_back(line);
				line.clear();
			}
		}
		else
		{
			line += c;
		}
	}
	if (!line.empty())
	{
		lines.push_back(line);
	}

	int count = 0;
	for (const auto &l : lines)
	{
		std::vector<std::string> parts;
		std::string part;
		for (char c : l)
		{
			if (c == ' ')
			{
				if (!part.empty())
				{
					parts.push_back(part);
					part.clear();
				}
			}
			else
			{
				part += c;
			}
		}
		if (!part.empty())
		{
			parts.push_back(part);
		}

		if (parts.size() < 10)
		{
			continue;
		}

		std::vector<std::string> p1_cards(parts.begin(), parts.begin() + 5);
		std::vector<std::string> p2_cards(parts.begin() + 5, parts.end());

		if (GetWinner(GetHandPattern(p1_cards), GetHandPattern(p2_cards)))
		{
			count++;
		}
	}
	return std::to_string(count);
}

bool S54::GetWinner(HandPattern p1, HandPattern p2)
{
	if (p1.pattern > p2.pattern)
	{
		return true;
	}
	if (p1.pattern < p2.pattern)
	{
		return false;
	}

	// Same pattern
	// Check value (if applicable for single value comparison)
	if (p1.value > p2.value)
	{
		return true;
	}
	if (p1.value < p2.value)
	{
		return false;
	}

	// Check remainders (kickers)
	for (size_t i = 0; i < p1.remainders.size(); i++)
	{
		if (i >= p2.remainders.size())
		{
			break; // Safety
		}
		if (p1.remainders[i] > p2.remainders[i])
		{
			return true;
		}
		if (p1.remainders[i] < p2.remainders[i])
		{
			return false;
		}
	}
	return false;
}

S54::HandPattern S54::GetHandPattern(std::vector<std::string> pokers)
{
	HandPattern result;
	std::vector<int> values;
	std::vector<char> suits;

	for (const auto &p : pokers)
	{
		char r = p[0];
		char s = p[1];
		int v = 0;
		if (isdigit(r))
		{
			v = r - '0';
		}
		else if (r == 'T')
		{
			v = 10;
		}
		else if (r == 'J')
		{
			v = 11;
		}
		else if (r == 'Q')
		{
			v = 12;
		}
		else if (r == 'K')
		{
			v = 13;
		}
		else if (r == 'A')
		{
			v = 14;
		}
		values.push_back(v);
		suits.push_back(s);
	}

	// Sort values descending for easier pattern matching
	std::sort(values.begin(), values.end(), std::greater<int>());

	bool flush = true;
	for (size_t i = 1; i < suits.size(); i++)
	{
		if (suits[i] != suits[0])
		{
			flush = false;
			break;
		}
	}

	bool straight = true;
	for (size_t i = 0; i < values.size() - 1; i++)
	{
		if (values[i] != values[i + 1] + 1)
		{
			straight = false;
			break;
		}
	}
	// Wheel straight logic usually A=14, so 14,5,4,3,2 is wheel.
	// Check if values are 14, 5, 4, 3, 2
	if (!straight && values[0] == 14 && values[1] == 5 && values[2] == 4 && values[3] == 3 && values[4] == 2)
	{
		straight = true;
		// Treat 5 as high card for straight comparison?
		// But in GetWinner we compare remainders.
		// So we should fix values order: 5, 4, 3, 2, 1 (A becomes 1).
		// But for now let's stick to standard high straight. Euler 54 doesn't specify.
	}

	if (flush && straight)
	{
		result.pattern = values[0] == 14 ? Pattern::RoyalFlush : Pattern::StraightFlush;
		result.value = values[0]; // High card of straight
		result.remainders = values;
		return result;
	}

	std::map<int, int> counts;
	for (int v : values)
	{
		counts[v]++;
	}

	std::vector<pair<int, int>> freq; // count, value
	for (const auto &[val, count] : counts)
	{
		freq.push_back({ count, val });
	}
	// Sort by count desc, then value desc
	std::sort(freq.begin(),
			  freq.end(),
			  [](const pair<int, int> &a, const pair<int, int> &b)
			  {
				  if (a.first != b.first)
				  {
					  return a.first > b.first;
				  }
				  return a.second > b.second;
			  });

	if (freq[0].first == 4)
	{
		result.pattern = Pattern::FourOfAKind;
		result.value = freq[0].second;
		result.remainders = { freq[0].second, freq[1].second }; // Quad value, then kicker
		return result;
	}
	if (freq[0].first == 3 && freq[1].first == 2)
	{
		result.pattern = Pattern::FullHouse;
		result.value = freq[0].second;
		result.remainders = { freq[0].second, freq[1].second }; // Triplet value, Pair value
		return result;
	}
	if (flush)
	{
		result.pattern = Pattern::Flush;
		result.value = values[0]; // High card
		result.remainders = values;
		return result;
	}
	if (straight)
	{
		result.pattern = Pattern::Straight;
		result.value = values[0];
		result.remainders = values;
		return result;
	}
	if (freq[0].first == 3)
	{
		result.pattern = Pattern::ThreeOfAKind;
		result.value = freq[0].second;
		result.remainders = { freq[0].second, freq[1].second, freq[2].second }; // Triplet, kicker1, kicker2
		return result;
	}
	if (freq[0].first == 2 && freq[1].first == 2)
	{
		result.pattern = Pattern::TwoPairs;
		result.value = freq[0].second;											// Higher pair
		result.remainders = { freq[0].second, freq[1].second, freq[2].second }; // Pair1, Pair2, kicker
		return result;
	}
	if (freq[0].first == 2)
	{
		result.pattern = Pattern::OnePair;
		result.value = freq[0].second;
		result.remainders = { freq[0].second, freq[1].second, freq[2].second, freq[3].second }; // Pair, k1, k2, k3
		return result;
	}

	result.pattern = Pattern::HighCard;
	result.value = values[0];
	result.remainders = values;
	return result;
}

} // namespace ProjectEuler
