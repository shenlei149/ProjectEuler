#include "S938.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace ProjectEuler
{
std::string S938::GetAnswer()
{
	p.resize(RED + 1);

	// Initialize p[0]
	p[0].resize(BLACK + 1);
	p[0][0] = 0;
	for (int b = 1; b <= BLACK; b++)
	{
		p[0][b] = 1.0;
	}

	for (int r = 1; r <= RED; r++)
	{
		p[r].resize(BLACK + 1);
		p[r][0] = 0;
		for (int b = 1; b <= BLACK; b++)
		{
			p[r][b] = GetPBy(r, b);
		}

		// Memory optimization: clear rows r-3
		// We need r-2.
		if (r >= 3)
		{
			p[r - 3].clear();
			p[r - 3].shrink_to_fit();
		}
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(10) << p[RED][BLACK];
	return oss.str();
}

double S938::GetPBy(int red, int black)
{
	// P(r, b) probability that A wins (or something)
	// Transitions:
	// Pick 2 balls.
	// Total (r+b)(r+b-1).

	// Pick R, B: 2*r*b. State -> (r, b-1).
	// Pick R, R: r(r-1). State -> (r-2, b).
	// Pick B, B: b(b-1). State -> (r, b). (Redraw?)
	// If B,B drawn, they are put back? Or discarded and we draw again?
	// Usually "draw with replacement" or "draw until non-BB".
	// Let's assume standard "draw 2 without replacement".
	// If BB, state remains same? "discard B, B"?
	// Original code: `p_b_b = ... / (1.0 - b_b_choice_p)`.
	// This implies infinite series 1 + p + p^2... = 1/(1-p).
	// So yes, if BB, we retry (effectively state stays same).

	double dem = (double)(red + black) * (red + black - 1);

	// Prob of getting R, B (one each)
	double r_b_choice_p = 2.0 * red * black / dem;
	double term1 = p[red][black - 1] * r_b_choice_p;

	double term2 = 0;
	if (red >= 2)
	{
		// Prob of getting R, R
		double r_r_choice_p = (double)red * (red - 1) / dem;
		term2 = p[red - 2][black] * r_r_choice_p;
	}

	// Prob of getting B, B
	double b_b_choice_p = (double)black * (black - 1) / dem;

	// P(r,b) = (P(r,b-1)*P(RB) + P(r-2,b)*P(RR) + P(r,b)*P(BB))
	// P(r,b) * (1 - P(BB)) = ...
	// P(r,b) = ... / (1 - P(BB)).

	return (term1 + term2) / (1.0 - b_b_choice_p);
}
} // namespace ProjectEuler
