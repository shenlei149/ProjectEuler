#include "S816.h"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
struct Point
{
	long long x, y;

	bool operator<(const Point &other) const
	{
		if (x != other.x)
		{
			return x < other.x;
		}
		return y < other.y;
	}
};

std::string S816::GetAnswer()
{
	int k = 2000000; // k=2000000 points

	// Generate points
	// s0 = 290797
	// s_n+1 = s_n^2 mod 50515093
	// P_n = (s_2n, s_2n+1)

	std::vector<long long> s(2 * k);
	long long curr = 290797;
	long long mod = 50515093;

	s[0] = curr;
	for (int i = 1; i < 2 * k; ++i)
	{
		curr = (curr * curr) % mod;
		s[i] = curr;
	}

	std::vector<Point> P(k);
	for (int i = 0; i < k; ++i)
	{
		P[i] = { s[2 * i], s[2 * i + 1] };
	}

	std::sort(P.begin(), P.end());

	// Closest pair problem
	// Brute force is O(N^2) - too slow for 2e6.
	// Divide and conquer is O(N log N).
	// Or simple strip optimization:
	// Sort by X.
	// Iterate points. Check neighbors in X within current min_dist.
	// Maintain a set of active points sorted by Y?
	// Or just the simple loop:
	// For each i, check j=i+1..k.
	// If P[j].x - P[i].x >= d, break.
	// If dist < d, d = dist.
	// But we need to filter by Y too to be efficient.
	// Pure X-sort loop is still O(N^2) in worst case, but random points O(N).
	// These are pseudo-random.
	// Let's try optimized loop.

	double min_dist_sq = 1e18; // Large value

	// Better algorithm:
	// Divide and Conquer or a Grid.
	// Or simply the X-sorted sweep.
	// To be safe, I'll use a small window check.
	// Usually checking next 10-20 points is heuristic, but not guaranteed.
	// The guaranteed approach maintains a Y-sorted structure.
	// Since I'm porting, I'll stick to the X-sort loop provided in old code but add Y check optimization.
	// Old code:
	/*
	for (int i = 0; i < P.size() - 1; i++) {
		 auto p = P[i];
		 for (int j = i + 1; j < P.size(); j++) {
			  if ((other.X - p.X) > distance) break;
			  ...
		 }
	}
	*/
	// This is exactly what I described.

	long long d_sq = -1; // -1 means unset

	for (int i = 0; i < k; ++i)
	{
		for (int j = i + 1; j < k; ++j)
		{
			long long dx = P[j].x - P[i].x;
			long long dy = P[j].y - P[i].y; // can be negative

			if (d_sq != -1 && dx * dx >= d_sq)
			{
				break;
			}

			long long dist = dx * dx + dy * dy;
			if (d_sq == -1 || dist < d_sq)
			{
				d_sq = dist;
			}
		}
	}

	double d = std::sqrt(d_sq);
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(9) << d;
	return oss.str();
}
} // namespace ProjectEuler
