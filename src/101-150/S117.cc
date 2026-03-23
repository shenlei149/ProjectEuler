#include "S117.h"
#include "../Utils.h"
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S117::GetAnswer()
{
	vector<vector<long long>> reds(3, vector<long long>(Layer, 0));
	vector<vector<long long>> greens(4, vector<long long>(Layer, 0));
	vector<vector<long long>> blues(5, vector<long long>(Layer, 0));

	reds[0][0] = 1;
	reds[1][0] = 1;
	reds[2][0] = 0;
	greens[0][0] = 1;
	greens[1][0] = 1;
	greens[2][0] = 0;
	greens[3][0] = 0;
	blues[0][0] = 1;
	blues[1][0] = 1;
	blues[2][0] = 0;
	blues[3][0] = 0;
	blues[4][0] = 0;

	for (int i = 1; i < Layer; i++)
	{
		long long next_blank = reds[0][i - 1] + reds[2][i - 1] + greens[3][i - 1] + blues[4][i - 1];
		reds[1][i] = reds[0][i] = next_blank;
		greens[1][i] = greens[0][i] = next_blank;
		blues[1][i] = blues[0][i] = next_blank;

		reds[2][i] = reds[1][i - 1];
		greens[2][i] = greens[1][i - 1];
		greens[3][i] = greens[2][i - 1];
		blues[2][i] = blues[1][i - 1];
		blues[3][i] = blues[2][i - 1];
		blues[4][i] = blues[3][i - 1];
	}

	long long result = reds[0][Layer - 1] + reds[2][Layer - 1] + greens[3][Layer - 1] + blues[4][Layer - 1];
	return std::to_string(result);
}

} // namespace ProjectEuler
