#include "S607.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace ProjectEuler
{
struct Point
{
	double x;
	double y;

	double Distance(Point other)
	{
		double diffX = x - other.x;
		double diffY = y - other.y;
		return std::sqrt(diffX * diffX + diffY * diffY);
	}
};

double Duration(std::vector<Point> &points)
{
	static const std::vector<double> speed = { 10, 9, 8, 7, 6, 5, 10 };
	double result = 0;
	for (size_t i = 0; i < speed.size(); i++)
	{
		Point p1 = points[i];
		Point p2 = points[i + 1];
		double way = p1.Distance(p2);
		result += way / speed[i];
	}
	return result;
}

void Mutate(std::vector<Point> &points, double delta)
{
	double oldDuration = Duration(points);

	int id = rand() % 6 + 1; // 1 to 6
	// Original C# might have had different logic.
	// The points are:
	// 0: (0,0)
	// 1: (current, current) -> Start of marsh?
	// ... marsh layers ...
	// 6: End of marsh?
	// 7: (100/sqrt(2), 100/sqrt(2))

	// There are 5 layers of marsh + 2 outer regions = 7 segments.
	// Points count = 8.
	// Inner points that can move are 1 to 6.

	if (rand() % 2 != 0)
	{
		delta = -delta;
	}

	points[id].y += delta;
	if (Duration(points) >= oldDuration)
	{
		points[id].y -= delta;
	}
}

std::string S607::GetAnswer()
{
	std::vector<Point> points;
	points.push_back({ 0, 0 });

	double scaling = std::sqrt(2);
	double direct = 50 * scaling;
	double current = (100 - direct) / 2 / scaling;

	points.push_back({ current, current });

	for (int i = 1; i <= 5; i++)
	{
		points.push_back({ current + i * 10, current + i * 10 });
	}

	points.push_back({ 100 / scaling, 100 / scaling });

	const int NumIterations = 10000;
	for (double delta = 0.01; delta >= 0.00001; delta /= 10)
	{
		for (int i = 0; i < NumIterations; i++)
		{
			Mutate(points, delta);
		}
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(10) << Duration(points);
	return oss.str();
}
} // namespace ProjectEuler
