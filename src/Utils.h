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
	static BigInt Pow(long long b, int n);

	static long long Pow(long long base, long long exp, long long mod)
	{
		long long res = 1;
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
	static long long GetLcm(long long a, long long b);
	static long long GetGcd(long long a, long long b);
	static long long GetGcd(long long m, long long n, long long &a, long long &b);

	static std::vector<long long> TrialDivisionFactor(long long n, const std::vector<long long> &primes);
	static std::map<long long, int> Factorize(long long n, const std::vector<long long> &primes);

	static long long GetCombinationsCount(long long total, long long pickedCount);
	static bool IsPandigital(const std::vector<int> &numbers);
	static bool IsPandigital(int y);
	static bool IsPandigital(const std::string &s, bool canContainsZero);
	static int DigitSum(long long number);

	static std::vector<long long> GenPrimeSieve(long long end);
	static std::vector<long long> GenPrimes(long long end); // no zero

	static long long Factorial(long long i);
	static bool IsPalindrome(const std::string &s);
	static bool IsPrime(long long number, const std::vector<long long> &primes);
	static bool IsPrime(long long number);

	// Permutations
	template<typename T>
	static std::vector<std::vector<T>> Permutations(std::vector<T> source)
	{
		std::vector<std::vector<T>> result;
		std::sort(source.begin(), source.end());
		do
		{
			result.push_back(source);
		}
		while (std::next_permutation(source.begin(), source.end()));
		return result;
	}

	static bool IsPermutation(long long x, long long y);
	static long long Reverse(long long x);

private:
	static void Factorize(long long n, const std::vector<long long> &primes, std::vector<long long> &factors);
	static long long PollardRho(long long n);
};

} // namespace ProjectEuler
