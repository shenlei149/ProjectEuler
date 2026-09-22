#pragma once
#include "BigInt.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

namespace ProjectEuler
{

class Utils
{
public:
	static BigInt Pow(int64_t b, int n);

	static int64_t Pow(int64_t base, int64_t exp, int64_t mod)
	{
		int64_t res = 1;
		base %= mod;
		while (exp > 0)
		{
			if (exp % 2 == 1)
			{
				res = (__int128)res * base % mod;
			}
			base = (__int128)base * base % mod;
			exp /= 2;
		}
		return res;
	}

	static BigInt Pow(BigInt b, int n)
	{
		BigInt result(1);
		for (int i = 0; i < n; i++)
		{
			result = result * b;
		}
		return result;
	}

	// Template implementation directly in header
	template<typename T>
	static std::vector<std::vector<T>> Combination(const std::vector<T> &source, int n)
	{
		if (source.size() < n)
		{
			return {};
		}

		std::vector<int> b(n);
		std::vector<std::vector<T>> list;
		Combination(list, source, source.size(), n, b, n);
		return list;
	}

private:
	template<typename T>
	static void
	Combination(std::vector<std::vector<T>> &list, const std::vector<T> &t, int n, int m, std::vector<int> &b, int M)
	{
		for (int i = n; i >= m; i--)
		{
			b[m - 1] = i - 1;
			if (m > 1)
			{
				Combination(list, t, i - 1, m - 1, b, M);
			}
			else
			{
				std::vector<T> temp(M);
				for (int j = 0; j < b.size(); j++)
				{
					temp[j] = t[b[j]];
				}
				list.push_back(temp);
			}
		}
	}

public:
	static int GetCoprimeCount(int n);
	static int64_t GetLcm(int64_t a, int64_t b);
	static int64_t GetGcd(int64_t a, int64_t b);
	static int64_t GetGcd(int64_t m, int64_t n, int64_t &a, int64_t &b);

	static std::vector<int64_t> TrialDivisionFactor(int64_t n, const std::vector<int64_t> &primes);
	static std::map<int64_t, int> Factorize(int64_t n, const std::vector<int64_t> &primes);

	static int64_t GetCombinationsCount(int64_t total, int64_t pickedCount);
	static bool IsPandigital(const std::vector<int> &numbers);
	static bool IsPandigital(int y);
	static bool IsPandigital(const std::string &s, bool canContainsZero);
	static int DigitSum(int64_t number);

	static std::vector<int64_t> GenPrimeSieve(int64_t end);
	static std::vector<int64_t> GenPrimes(int64_t end); // no zero

	static int64_t Factorial(int64_t i);
	static bool IsPalindrome(const std::string &s);
	static bool IsPrime(int64_t number, const std::vector<int64_t> &primes);
	static bool IsPrime(int64_t number);

	// Permutations
	template<typename T>
	static std::vector<std::vector<T>> Permutations(std::vector<T> source)
	{
		std::vector<std::vector<T>> result;
		std::sort(source.begin(), source.end());
		do
		{
			result.push_back(source);
		} while (std::next_permutation(source.begin(), source.end()));
		return result;
	}

	static bool IsPermutation(int64_t x, int64_t y);
	static int64_t Reverse(int64_t x);

private:
	static void Factorize(int64_t n, const std::vector<int64_t> &primes, std::vector<int64_t> &factors);
	static int64_t PollardRho(int64_t n);
};

} // namespace ProjectEuler
