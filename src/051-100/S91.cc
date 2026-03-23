#include "S91.h"
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{
std::string S91::GetAnswer()
{
	int limit = 50;
	int count = 0;

	for (int x1 = 0; x1 <= limit; x1++)
	{
		for (int y1 = 0; y1 <= limit; y1++)
		{
			if (x1 == 0 && y1 == 0)
			{
				continue;
			}

			for (int x2 = 0; x2 <= limit; x2++)
			{
				for (int y2 = 0; y2 <= limit; y2++)
				{
					if (x2 == 0 && y2 == 0)
					{
						continue;
					}
					if (x1 == x2 && y1 == y2)
					{
						continue;
					}

					// Check right angle
					// Vectors:
					// OP = (x1, y1)
					// OQ = (x2, y2)
					// PQ = (x2-x1, y2-y1)

					// Dot products:
					// OP . OQ = x1*x2 + y1*y2
					// OP . PQ = x1*(x2-x1) + y1*(y2-y1)
					// OQ . PQ = x2*(x2-x1) + y2*(y2-y1)

					bool right = false;
					if (x1 * x2 + y1 * y2 == 0)
					{
						right = true; // Angle at O
					}
					else if (x1 * (x2 - x1) + y1 * (y2 - y1) == 0)
					{
						right = true; // Angle at P
					}
					else if (x2 * (x2 - x1) + y2 * (y2 - y1) == 0)
					{
						right = true; // Angle at Q
					}

					if (right)
					{
						count++;
					}
				}
			}
		}
	}

	// Each triangle counted twice (P, Q) vs (Q, P).
	return std::to_string(count / 2);
}
} // namespace ProjectEuler
