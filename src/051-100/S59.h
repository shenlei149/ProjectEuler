#pragma once
#include "../ISolution.h"
#include <string>
#include <vector>

namespace ProjectEuler
{
class S59 : public ISolution
{
public:
	std::string GetAnswer() override;
	std::vector<int> Encrypt(std::vector<int> message, std::vector<int> key);
};
} // namespace ProjectEuler
