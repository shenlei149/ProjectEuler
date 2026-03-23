#pragma once
#include "../ISolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

namespace ProjectEuler
{
struct Edge
{
	int v, w, Weight;

	Edge(int _v, int _w, int _weight)
		: v(_v)
		, w(_w)
		, Weight(_weight)
	{}

	int Either() const { return v; }

	int Other(int vertex) const { return (vertex == v) ? w : v; }

	// For min priority queue, we need greater operator
	bool operator>(const Edge &other) const { return Weight > other.Weight; }
};

class S107 : public ISolution
{
public:
	std::string GetAnswer() override;
	void Visit(const std::vector<std::vector<int>> &matrix,
			   int v,
			   std::vector<bool> &marked,
			   std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> &pq);
	std::vector<std::vector<int>> InitMatrix(const std::vector<std::string> &graph);

	static std::vector<std::string> little;
	static std::vector<std::string> large;

private:
	int totalWeight = 0;
};
} // namespace ProjectEuler
