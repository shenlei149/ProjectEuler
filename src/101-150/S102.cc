#include "S102.h"
#include "../Utils.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S102::GetAnswer()
{
	int count = 0;
	std::stringstream ss(Triangles);
	std::string line;

	// Remove first 3 bytes if they are BOM? No, just assume standard string.

	// Split lines by '\n' or ','? The file seems to have multiple lines.
	// The previous view of S102.h showed: std::string Triangles = "..."
	// If it's CSV, it might be newlines.

	while (std::getline(ss, line))
	{
		if (line.empty())
		{
			continue;
		}
		if (line.back() == '\r')
		{
			line.pop_back();
		}
		if (line.empty())
		{
			continue;
		}

		std::stringstream ls(line);
		std::string val;
		std::vector<int> coords;
		while (std::getline(ls, val, ','))
		{
			if (!val.empty())
			{
				coords.push_back(std::stoi(val));
			}
		}

		if (coords.size() < 6)
		{
			continue;
		}

		int Ax = coords[0];
		int Ay = coords[1];
		int Bx = coords[2];
		int By = coords[3];
		int Cx = coords[4];
		int Cy = coords[5];

		int Ox = 0;
		int Oy = 0;

		// Using Barycentric technique or cross product side test.
		// A point O is inside triangle ABC if O is on the same side of AB as C,
		// on same side of BC as A, and on same side of CA as B.

		bool sameSideAB = IsSameSide(Ax, Ay, Bx, By, Cx, Cy, Ox, Oy); // C and O same side of AB
		bool sameSideBC = IsSameSide(Bx, By, Cx, Cy, Ax, Ay, Ox, Oy); // A and O same side of BC
		bool sameSideCA = IsSameSide(Cx, Cy, Ax, Ay, Bx, By, Ox, Oy); // B and O same side of CA

		if (sameSideAB && sameSideBC && sameSideCA)
		{
			count++;
		}
	}

	return std::to_string(count);
}

bool S102::IsSameSide(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Ox, int Oy)
{
	long long cp1 = (long long)(Bx - Ax) * (Cy - Ay) - (long long)(By - Ay) * (Cx - Ax);
	long long cp2 = (long long)(Bx - Ax) * (Oy - Ay) - (long long)(By - Ay) * (Ox - Ax);
	// If both cross products have the same sign
	return (cp1 * cp2) >= 0;
}

int S102::CrossProduct(int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
	// Not used directly here, integrated into IsSameSide
	return 0;
}

} // namespace ProjectEuler
