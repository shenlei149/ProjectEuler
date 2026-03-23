#include "S41.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S41::GetAnswer()
{
	int max = 0;
	// sum(1..8)=36, 36%3=0
	// sum(1..9)=45, 45%3=0
	// so the number contians (1..8) or (1..9) MUST not be prime.
	for (int i = 1; i < 8; i++)
	{
		std::vector<int> numbers;
		for (int j = 1; j <= i; j++)
		{
			numbers.push_back(j);
		}

		auto per = Utils::Permutations(numbers);

		for (auto item : per)
		{
			int number = 0;
			for (auto d : item)
			{
				number *= 10;
				number += d;
			}

			if (number > max && Utils::IsPrime(number))
			{
				max = number;
			}
		}
	}

	return std::to_string(max);
}

} // namespace ProjectEuler
