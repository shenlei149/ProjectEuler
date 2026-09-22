#include "S45.h"
#include "../Utils.h"

using namespace std;

namespace ProjectEuler
{
std::string S45::GetAnswer()
{
	std::vector<int64_t> Ts(N);
	std::vector<int64_t> Ps(N);
	std::vector<int64_t> Hs(N);

	for (int64_t i = 1; i <= N; i++)
	{
		Ts[i - 1] = i * (i + 1) / 2;
		Ps[i - 1] = i * (3 * i - 1) / 2;
		Hs[i - 1] = i * (2 * i - 1);
	}

	std::vector<int64_t> tp_intersection;
	std::set_intersection(Ts.begin(), Ts.end(), Ps.begin(), Ps.end(), std::back_inserter(tp_intersection));

	std::vector<int64_t> final_intersection;
	std::set_intersection(tp_intersection.begin(),
						  tp_intersection.end(),
						  Hs.begin(),
						  Hs.end(),
						  std::back_inserter(final_intersection));

	if (final_intersection.size() >= 3)
	{
		return std::to_string(final_intersection[2]);
	}
	return "0";
}

} // namespace ProjectEuler
