#include "S44.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S44::GetAnswer()
{
	std::vector<int> pentagonNumbers;
	for (int i = 1; i < 3000; i++)
	{
		pentagonNumbers.push_back(i * (3 * i - 1) / 2);
	}

	std::vector<int> numbers = pentagonNumbers;
	int length = numbers.size();
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			int sum = numbers[i] + numbers[j];
			int diff = numbers[j] - numbers[i];
			if (std::binary_search(numbers.begin(), numbers.end(), sum) &&
				std::binary_search(numbers.begin(), numbers.end(), diff))
			{
				return std::to_string(diff);
			}
		}
	}

	return "";
}

} // namespace ProjectEuler
