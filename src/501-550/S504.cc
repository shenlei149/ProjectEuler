#include "S504.h"
#include "../Utils.h"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
// Need GCD. C++17 has std::gcd in <numeric>.

int S504::GetInsideVector(int a, int b)
{
	// Pick's Theorem for triangle (0,0), (a,0), (0,b)
	// Area = a*b/2
	// Boundary points on edges.
	// On (0,0)-(a,0): a+1
	// On (0,0)-(0,b): b+1
	// On (a,0)-(0,b): gcd(a,b)+1
	// Total B = (a+1)+(b+1)+(gcd(a,b)+1) - 3 (double counted corners) = a+b+gcd(a,b).
	// I = A - B/2 + 1
	// I = (ab)/2 - (a+b+gcd(a,b))/2 + 1
	// I = (ab - a - b - gcd(a,b))/2 + 1.

	return (a * b - a - b - std::gcd(a, b)) / 2 + 1;
}

int S504::GetNumberOfVector(int a, int b, int c, int d)
{
	// Inside points of quadrilateral formed by (a,0), (0,b), (-c,0), (0,-d).
	// It's union of 4 triangles meeting at (0,0).
	// (0,0) is inside.
	// Points on positive x-axis inside: a-1.
	// Points on positive y-axis inside: b-1.
	// Points on negative x-axis inside: c-1.
	// Points on negative y-axis inside: d-1.
	// Plus origin: 1.
	// Plus strictly inside points of 4 triangles.

	int inside = GetInsideVector(a, b) + GetInsideVector(b, c) + GetInsideVector(c, d) + GetInsideVector(d, a);

	return inside + (a - 1) + (b - 1) + (c - 1) + (d - 1) + 1;
	// = inside + a + b + c + d - 3.
}

std::string S504::GetAnswer()
{
	NumbersOfInsideVector.assign(M + 1, std::vector<int>(M + 1));

	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			NumbersOfInsideVector[i][j] = GetInsideVector(i, j);
		}
	}

	int count = 0;
	for (int a = 1; a <= M; ++a)
	{
		for (int b = 1; b <= M; ++b)
		{
			for (int c = 1; c <= M; ++c)
			{
				for (int d = 1; d <= M; ++d)
				{
					// Optimization: pass memoized values or use inline
					int n = NumbersOfInsideVector[a][b] + NumbersOfInsideVector[b][c] + NumbersOfInsideVector[c][d] +
							NumbersOfInsideVector[d][a] + a + b + c + d - 3;

					int root = (int)std::sqrt(n);
					if (root * root == n)
					{
						count++;
					}
				}
			}
		}
	}

	return std::to_string(count);
}
} // namespace ProjectEuler
