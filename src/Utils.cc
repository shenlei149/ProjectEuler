#include "Utils.h"
#include <random>

namespace ProjectEuler
{

// Helper random
static std::mt19937_64 rng(std::random_device {}());

BigInt Utils::Pow(int64_t b, int n)
{
	if (n == 0)
	{
		return BigInt(1);
	}
	if (n == 1)
	{
		return BigInt(b);
	}

	BigInt half = Pow(b, n / 2);
	if (n % 2 == 0)
	{
		return half * half;
	}
	else
	{
		return half * half * BigInt(b);
	}
}

int Utils::GetCoprimeCount(int n)
{
	int ret = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			n /= i;
			ret *= i - 1;
			while (n % i == 0)
			{
				n /= i;
				ret *= i;
			}
		}
	}
	if (n > 1)
	{
		ret *= n - 1;
	}
	return ret;
}

int64_t Utils::GetLcm(int64_t a, int64_t b) { return (a / GetGcd(a, b)) * b; }

int64_t Utils::GetGcd(int64_t a, int64_t b)
{
	int64_t r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int64_t Utils::GetGcd(int64_t m, int64_t n, int64_t &a, int64_t &b)
{
	a = 0;
	b = 1;
	int64_t ap = 1;
	int64_t bp = 0;
	int64_t q = m / n;
	int64_t r = m % n;
	while (r > 0)
	{
		m = n;
		n = r;
		int64_t t = ap;
		ap = a;
		a = t - q * a;
		t = bp;
		bp = b;
		b = t - q * b;
		q = m / n;
		r = m % n;
	}
	return n;
}

std::vector<int64_t> Utils::TrialDivisionFactor(int64_t n, const std::vector<int64_t> &primes)
{
	std::vector<int64_t> results;
	int index = 0;
	while (true)
	{
		if (primes[index] != 0)
		{
			if (n < primes.size() && primes[n] != 0)
			{ // Check bounds! C# code relies on array size
				results.push_back(n);
				break;
			}
			if (n % primes[index] == 0)
			{
				results.push_back(primes[index]);
				do
				{
					n /= primes[index];
				}
				while (n % primes[index] == 0);
			}
			if (n == 1)
			{
				break;
			}
		}
		index++;
		if (index >= primes.size())
		{
			break; // Safety break
		}
	}
	return results;
}

std::map<int64_t, int> Utils::Factorize(int64_t n, const std::vector<int64_t> &primes)
{
	std::vector<int64_t> factors;
	Factorize(n, primes, factors);

	std::map<int64_t, int> maps;
	for (auto factor : factors)
	{
		maps[factor]++;
	}
	return maps;
}

void Utils::Factorize(int64_t n, const std::vector<int64_t> &primes, std::vector<int64_t> &factors)
{
	if (n == 1)
	{
		return;
	}

	// Bounds check for primes array access
	if (n < primes.size() && primes[n] == n)
	{
		factors.push_back(n);
		return;
	}

	// If simple trial division works? Or Pollard Rho?
	// C# code calls PollardRho if not in primes array.
	int64_t divisor = PollardRho(n);
	if (divisor == n)
	{ // Prime
		factors.push_back(n);
	}
	else
	{
		Factorize(divisor, primes, factors);
		Factorize(n / divisor, primes, factors);
	}
}

int64_t Utils::PollardRho(int64_t n)
{
	if (n % 2 == 0)
	{
		return 2;
	}
	if (IsPrime(n))
	{
		return n; // Optimization
	}

	int64_t x = std::uniform_int_distribution<int64_t>(1, n - 1)(rng);
	int64_t c = std::uniform_int_distribution<int64_t>(1, n - 1)(rng);
	int64_t y = x;
	int64_t g = 1;

	auto f = [&](int64_t x) { return ((__int128)x * x + c) % n; };

	while (g == 1)
	{
		x = f(x);
		y = f(f(y));
		g = GetGcd(std::abs(x - y), n);
		if (g == n)
		{ // Failure, retry
			x = std::uniform_int_distribution<int64_t>(1, n - 1)(rng);
			c = std::uniform_int_distribution<int64_t>(1, n - 1)(rng);
			y = x;
			g = 1;
		}
	}
	return g;
}

int64_t Utils::GetCombinationsCount(int64_t total, int64_t pickedCount)
{
	int64_t count = 1;
	for (int i = 0; i < pickedCount; i++)
	{
		count *= total - i;
	}
	for (int i = 0; i < pickedCount; i++)
	{
		count /= i + 1;
	}
	return count;
}

bool Utils::IsPandigital(const std::vector<int> &numbers)
{
	int digits[10] = { 0 };
	for (auto n : numbers)
	{
		int64_t y = n; // Assuming n fits in int64_t
		while (y != 0)
		{
			digits[y % 10]++;
			y /= 10;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (digits[i] > 1)
		{
			return false;
		}
	}
	return true;
}

bool Utils::IsPandigital(int y)
{
	int digits[10] = { 0 };
	while (y != 0)
	{
		digits[y % 10]++;
		y /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digits[i] != 0 && digits[i] != 1)
		{
			return false; // Allowed 0 or 1 count? C# says "i == 0 || i == 1"
		}
	}
	return true;
}

bool Utils::IsPandigital(const std::string &s, bool canContainsZero)
{
	if (!canContainsZero && s.find('0') != std::string::npos)
	{
		return false;
	}
	std::set<char> distinct(s.begin(), s.end());
	return distinct.size() == s.length();
}

int Utils::DigitSum(int64_t number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += (int)(number % 10);
		number /= 10;
	}
	return sum;
}

std::vector<int64_t> Utils::GenPrimeSieve(int64_t end)
{
	std::vector<int64_t> primes(end);
	for (int64_t i = 0; i < end; i++)
	{
		primes[i] = i;
	}

	if (end > 1)
	{
		primes[1] = 0;
	}

	for (int64_t i = 0; i * i < end; i++)
	{
		if (primes[i] != 0)
		{
			int64_t p = primes[i];
			for (int64_t j = 2; j * p < end; j++)
			{
				primes[j * p] = 0;
			}
		}
	}
	return primes;
}

std::vector<int64_t> Utils::GenPrimes(int64_t end)
{
	std::vector<int64_t> results;
	std::vector<bool> primes(end, true);

	if (end > 0)
	{
		primes[0] = false;
	}
	if (end > 1)
	{
		primes[1] = false;
	}

	for (int64_t i = 0; i * i < end; i++)
	{
		if (primes[i])
		{
			int64_t p = i;
			for (int64_t j = 2; j * p < end; j++)
			{
				primes[j * p] = false;
			}
			results.push_back(i);
		}
	}
	for (int64_t i = std::sqrt(end) + 1; i < end; i++)
	{
		if (primes[i])
		{
			results.push_back(i);
		}
	}
	// Correct the loop range to match logic, simplified
	// Above logic splits the loop but simpler is just iterate all
	return results;
}

int64_t Utils::Factorial(int64_t i)
{
	if (i < 0)
	{
		throw std::invalid_argument("i should be natural number");
	}
	if (i == 0 || i == 1)
	{
		return 1;
	}
	return i * Factorial(i - 1);
}

bool Utils::IsPalindrome(const std::string &s)
{
	for (size_t i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}

bool Utils::IsPrime(int64_t number, const std::vector<int64_t> &primes)
{
	if (number <= 1)
	{
		return false;
	}
	if (number == 2)
	{
		return true;
	}

	int64_t max = (int64_t)std::ceil(std::sqrt(number));
	for (int64_t n : primes)
	{
		if (n == 0)
		{
			continue; // Skip 0s in primes array if using GenPrimes result
		}
		if (n > max)
		{
			break;
		}
		if (number % n == 0)
		{
			return false;
		}
	}
	return true;
}

bool Utils::IsPrime(int64_t number)
{
	if (number <= 1)
	{
		return false;
	}
	if (number == 2 || number == 3)
	{
		return true;
	}
	if (number % 2 == 0)
	{
		return false;
	}

	int64_t max = (int64_t)std::ceil(std::sqrt(number));
	for (int64_t i = 3; i <= max; i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool Utils::IsPermutation(int64_t x, int64_t y)
{
	if (x == y)
	{
		return true;
	}
	int digits[10] = { 0 };
	while (y != 0)
	{
		digits[y % 10]++;
		y /= 10;
	}
	while (x != 0)
	{
		digits[x % 10]--;
		x /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digits[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int64_t Utils::Reverse(int64_t x)
{
	int64_t re = 0;
	while (x != 0)
	{
		int d = x % 10;
		x /= 10;
		re = re * 10 + d;
	}
	return re;
}

} // namespace ProjectEuler
