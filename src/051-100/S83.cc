#include "S83.h"
#include "Matrix81.h"
#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S83::GetAnswer()
{
	const auto &matrix = MATRIX_81;
	int rows = matrix.size();
	if (rows == 0)
	{
		return "0";
	}
	int cols = matrix[0].size();

	// Dijkstra
	// dist[i][j]
	std::vector<std::vector<long long>> dist(rows, std::vector<long long>(cols, LLONG_MAX));

	// Priority queue stores {cost, r, c}
	// Min-heap
	using State = std::tuple<long long, int, int>;
	std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

	dist[0][0] = matrix[0][0];
	pq.push({ dist[0][0], 0, 0 });

	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };

	while (!pq.empty())
	{
		auto [d, r, c] = pq.top();
		pq.pop();

		if (d > dist[r][c])
		{
			continue;
		}
		if (r == rows - 1 && c == cols - 1)
		{
			return std::to_string(d);
		}

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
			{
				if (dist[r][c] + matrix[nr][nc] < dist[nr][nc])
				{
					dist[nr][nc] = dist[r][c] + matrix[nr][nc];
					pq.push({ dist[nr][nc], nr, nc });
				}
			}
		}
	}

	return "0";
}

bool S83::CanMoveToLeft(int point) { return false; } // Unused

bool S83::CanMoveToRight(int point) { return false; } // Unused

bool S83::CanUp(int point) { return false; } // Unused

bool S83::CanDown(int point) { return false; } // Unused

} // namespace ProjectEuler
