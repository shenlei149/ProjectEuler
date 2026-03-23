#include "S116.h"
#include "../Utils.h"
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S116::GetAnswer()
{
	long long red = GetRedCount();
	long long green = GetGreenCount();
	long long blue = GetBlueCount();
	return std::to_string(red + green + blue);
}

long long S116::GetRedCount()
{
	vector<vector<long long>> reds(3, vector<long long>(Layer, 0));
	reds[0][0] = 1;
	reds[1][0] = 1;
	reds[2][0] = 0;

	for (int i = 1; i < Layer; i++)
	{
		reds[1][i] = reds[0][i] = reds[0][i - 1] + reds[2][i - 1];
		reds[2][i] = reds[1][i - 1];
	}

	return reds[0][Layer - 1] + reds[2][Layer - 1] - 1;
}

long long S116::GetGreenCount()
{
	vector<vector<long long>> greens(4, vector<long long>(Layer, 0));
	greens[0][0] = 1;
	greens[1][0] = 1;
	greens[2][0] = 0;
	greens[3][0] = 0;

	for (int i = 1; i < Layer; i++)
	{
		greens[1][i] = greens[0][i] = greens[0][i - 1] + greens[3][i - 1];
		greens[2][i] = greens[1][i - 1];
		greens[3][i] = greens[2][i - 1];
	}

	return greens[0][Layer - 1] + greens[3][Layer - 1] - 1;
}

long long S116::GetBlueCount()
{
	vector<vector<long long>> blues(5, vector<long long>(Layer, 0));
	blues[0][0] = 1;
	blues[1][0] = 1;
	blues[2][0] = 0;
	blues[3][0] = 0;
	blues[4][0] = 0;

	for (int i = 1; i < Layer; i++)
	{
		blues[1][i] = blues[0][i] = blues[0][i - 1] + blues[4][i - 1];
		blues[2][i] = blues[1][i - 1];
		blues[3][i] = blues[2][i - 1];
		blues[4][i] = blues[3][i - 1];
	}

	return blues[0][Layer - 1] + blues[4][Layer - 1] - 1;
}

} // namespace ProjectEuler
