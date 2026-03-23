#pragma once
#include <string>

namespace ProjectEuler
{
class ISolution
{
public:
	virtual ~ISolution() = default;
	virtual std::string GetAnswer() = 0;
};
} // namespace ProjectEuler
