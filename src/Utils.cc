#include "Utils.h"
#include <random>

namespace ProjectEuler
{

// Helper random
static std::mt19937_64 rng(std::random_device {}());

BigInt Utils::Pow(long long b, int n)
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

long long Utils::GetLcm(long long a, long long b) { return (a / GetGcd(a, b)) * b; }

long long Utils::GetGcd(long long a, long long b)
{
	long long r = a % b;
	while (r > 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

long long Utils::GetGcd(long long m, long long n, long long &a, long long &b)
{
	a = 0;
	b = 1;
	long long ap = 1;
	long long bp = 0;
	long long q = m / n;
	long long r = m % n;
	while (r > 0)
	{
		m = n;
		n = r;
		long long t = ap;
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

std::vector<long long> Utils::TrialDivisionFactor(long long n, const std::vector<long long> &primes)
{
	std::vector<long long> results;
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

std::map<long long, int> Utils::Factorize(long long n, const std::vector<long long> &primes)
{
	std::vector<long long> factors;
	Factorize(n, primes, factors);

	std::map<long long, int> maps;
	for (auto factor : factors)
	{
		maps[factor]++;
	}
	return maps;
}

void Utils::Factorize(long long n, const std::vector<long long> &primes, std::vector<long long> &factors)
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
	long long divisor = PollardRho(n);
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

long long Utils::PollardRho(long long n)
{
	if (n % 2 == 0)
	{
		return 2;
	}
	if (IsPrime(n))
	{
		return n; // Optimization
	}

	long long x = std::uniform_int_distribution<long long>(1, n - 1)(rng);
	long long c = std::uniform_int_distribution<long long>(1, n - 1)(rng);
	long long y = x;
	long long g = 1;

	auto f = [&](long long x) { return ((__int128)x * x + c) % n; };

	while (g == 1)
	{
		x = f(x);
		y = f(f(y));
		g = GetGcd(std::abs(x - y), n);
		if (g == n)
		{ // Failure, retry
			x = std::uniform_int_distribution<long long>(1, n - 1)(rng);
			c = std::uniform_int_distribution<long long>(1, n - 1)(rng);
			y = x;
			g = 1;
		}
	}
	return g;
}

long long Utils::GetCombinationsCount(long long total, long long pickedCount)
{
	long long count = 1;
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
		long long y = n; // Assuming n fits in long long
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

int Utils::DigitSum(long long number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += (int)(number % 10);
		number /= 10;
	}
	return sum;
}

std::vector<long long> Utils::GenPrimeSieve(long long end)
{
	std::vector<long long> primes(end);
	for (long long i = 0; i < end; i++)
	{
		primes[i] = i;
	}

	if (end > 1)
	{
		primes[1] = 0;
	}

	for (long long i = 0; i * i < end; i++)
	{
		if (primes[i] != 0)
		{
			long long p = primes[i];
			for (long long j = 2; j * p < end; j++)
			{
				primes[j * p] = 0;
			}
		}
	}
	return primes;
}

std::vector<long long> Utils::GenPrimes(long long end)
{
	std::vector<long long> results;
	std::vector<bool> primes(end, true);

	if (end > 0)
	{
		primes[0] = false;
	}
	if (end > 1)
	{
		primes[1] = false;
	}

	for (long long i = 0; i * i < end; i++)
	{
		if (primes[i])
		{
			long long p = i;
			for (long long j = 2; j * p < end; j++)
			{
				primes[j * p] = false;
			}
			results.push_back(i);
		}
	}
	for (long long i = std::sqrt(end) + 1; i < end; i++)
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

long long Utils::Factorial(long long i)
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

bool Utils::IsPrime(long long number, const std::vector<long long> &primes)
{
	if (number <= 1)
	{
		return false;
	}
	if (number == 2)
	{
		return true;
	}

	long long max = (long long)std::ceil(std::sqrt(number));
	for (long long n : primes)
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

bool Utils::IsPrime(long long number)
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

	long long max = (long long)std::ceil(std::sqrt(number));
	for (long long i = 3; i <= max; i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool Utils::IsPermutation(long long x, long long y)
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

long long Utils::Reverse(long long x)
{
	long long re = 0;
	while (x != 0)
	{
		int d = x % 10;
		x /= 10;
		re = re * 10 + d;
	}
	return re;
}

} // namespace ProjectEuler
