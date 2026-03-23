#pragma once
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace ProjectEuler
{

class BigInt
{
public:
	std::vector<int> digits;

	BigInt() = default;

	BigInt(long long n)
	{
		if (n == 0)
		{
			digits.push_back(0);
		}
		while (n > 0)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}

	BigInt(const std::string &s)
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			digits.push_back(s[i] - '0');
		}
		removeLeadingZeros();
	}

	void removeLeadingZeros()
	{
		while (digits.size() > 1 && digits.back() == 0)
		{
			digits.pop_back();
		}
	}

	std::string toString() const
	{
		if (digits.empty())
		{
			return "0";
		}
		std::string s;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			s += std::to_string(digits[i]);
		}
		return s;
	}

	std::string ToString() const { return toString(); }

	std::string ToString(std::string fmt) const { return toString(); } // Ignore format for now

	BigInt &operator+=(const BigInt &other)
	{
		*this = *this + other;
		return *this;
	}

	bool operator<(const BigInt &other) const
	{
		if (digits.size() != other.digits.size())
		{
			return digits.size() < other.digits.size();
		}
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] != other.digits[i])
			{
				return digits[i] < other.digits[i];
			}
		}
		return false;
	}

	bool operator>(const BigInt &other) const { return other < *this; }

	bool operator==(const BigInt &other) const { return digits == other.digits; }

	bool operator!=(const BigInt &other) const { return !(*this == other); }

	bool operator<=(const BigInt &other) const { return !(*this > other); }

	bool operator>=(const BigInt &other) const { return !(*this < other); }

	BigInt operator+(const BigInt &other) const
	{
		BigInt result;
		int carry = 0;
		for (size_t i = 0; i < std::max(digits.size(), other.digits.size()) || carry; ++i)
		{
			int sum = carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
			result.digits.push_back(sum % 10);
			carry = sum / 10;
		}
		return result;
	}

	BigInt operator-(const BigInt &other) const
	{
		// Assumes *this >= other
		BigInt result;
		int borrow = 0;
		for (size_t i = 0; i < digits.size(); ++i)
		{
			int sub = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
			if (sub < 0)
			{
				sub += 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}
			result.digits.push_back(sub);
		}
		result.removeLeadingZeros();
		return result;
	}

	BigInt operator*(const BigInt &other) const
	{
		if (digits.empty() || other.digits.empty())
		{
			return BigInt(0);
		}
		if ((digits.size() == 1 && digits[0] == 0) || (other.digits.size() == 1 && other.digits[0] == 0))
		{
			return BigInt(0);
		}

		BigInt result;
		result.digits.resize(digits.size() + other.digits.size(), 0);
		for (size_t i = 0; i < digits.size(); ++i)
		{
			int carry = 0;
			for (size_t j = 0; j < other.digits.size() || carry; ++j)
			{
				long long cur =
					result.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
				result.digits[i + j] = cur % 10;
				carry = cur / 10;
			}
		}
		result.removeLeadingZeros();
		return result;
	}

	// Division
	static std::pair<BigInt, BigInt> div_mod(const BigInt &dividend, const BigInt &divisor)
	{
		if (divisor.digits.size() == 1 && divisor.digits[0] == 0)
		{
			return { BigInt(0), BigInt(0) }; // Should throw
		}
		if (dividend < divisor)
		{
			return { BigInt(0), dividend };
		}

		BigInt quotient;
		BigInt remainder(0);

		// Optimize if dividend is small

		for (int i = dividend.digits.size() - 1; i >= 0; --i)
		{
			// remainder = remainder * 10 + digit
			if (remainder.digits.size() == 1 && remainder.digits[0] == 0)
			{
				remainder.digits.clear();
			}
			remainder.digits.insert(remainder.digits.begin(), dividend.digits[i]);

			int count = 0;
			while (remainder >= divisor)
			{
				remainder = remainder - divisor;
				count++;
			}
			quotient.digits.push_back(count);
		}

		std::reverse(quotient.digits.begin(), quotient.digits.end());
		quotient.removeLeadingZeros();
		remainder.removeLeadingZeros();
		return { quotient, remainder };
	}

	BigInt operator/(const BigInt &other) const { return div_mod(*this, other).first; }

	BigInt operator%(const BigInt &other) const { return div_mod(*this, other).second; }

	// Allow BigInt / int etc
	BigInt operator/(long long other) const { return *this / BigInt(other); }

	// Multiplication by int
	BigInt operator*(long long other) const { return *this * BigInt(other); }

	static BigInt Sqrt(const BigInt &n)
	{
		if (n.digits.empty() || (n.digits.size() == 1 && n.digits[0] == 0))
		{
			return BigInt(0);
		}

		// Initial guess: 10^(digits/2 + 1) to ensure we start from above
		// n has D digits. Sqrt has ceil(D/2) digits.
		int d = (n.digits.size() + 1) / 2;
		std::string s = "1";
		// Add d zeros to make it 10^d, which has d+1 digits, ensuring it's > sqrt(n)
		if (d > 0)
		{
			s.append(d, '0');
		}
		BigInt x(s);
		BigInt two(2);

		while (true)
		{
			BigInt y = (x + n / x) / two;
			if (y >= x)
			{
				return x;
			}
			x = y;
		}
	}

	friend std::ostream &operator<<(std::ostream &os, const BigInt &bi)
	{
		os << bi.toString();
		return os;
	}
};

} // namespace ProjectEuler
