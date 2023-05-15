using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    internal static class Utils
    {
        private static readonly Random rand = new Random();

        public static BigInteger Pow(long b, int n)
        {
            if (n == 0)
            {
                return 1;
            }

            if (n == 1)
            {
                return b;
            }

            var half = Pow(b, n / 2);
            if (n % 2 == 0)
            {
                return half * half;
            }
            else
            {
                return half * half * b;
            }
        }

        public static IEnumerable<IEnumerable<T>> Combination<T>(IEnumerable<T> source, int n)
        {
            if (source.Count() < n)
            {
                return null;
            }

            int[] temp = new int[n];
            List<List<T>> list = new List<List<T>>();
            Combination(ref list, source, source.Count(), n, temp, n);
            return list;
        }

        private static void Combination<T>(ref List<List<T>> list, IEnumerable<T> t, int n, int m, int[] b, int M)
        {
            for (int i = n; i >= m; i--)
            {
                b[m - 1] = i - 1;
                if (m > 1)
                {
                    Combination(ref list, t, i - 1, m - 1, b, M);
                }
                else
                {
                    List<T> temp = new List<T>(M);
                    for (int j = 0; j < b.Length; j++)
                    {
                        temp.Insert(j, t.ElementAt(b[j]));
                    }
                    list.Add(temp);
                }
            }
        }

        public static int GetCoprimeCount(int n)
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

        public static long GetLcm(long a, long b)
        {
            long gcd = GetGcd(a, b);

            return a / gcd * b;
        }

        public static Dictionary<long, int> Factorize(long n, long[] primes)
        {
            List<long> factors = new List<long>();
            Factorize(n, primes, factors);

            var maps = new Dictionary<long, int>();
            foreach (var factor in factors)
            {
                if (maps.ContainsKey(factor))
                {
                    maps[factor]++;
                }
                else
                {
                    maps[factor] = 1;
                }
            }

            return maps;
        }

        private static void Factorize(long n, long[] primes, List<long> factors)
        {
            if (n == 1)
            {
                return;
            }

            if (primes[n] == n)
            {
                factors.Add(n);
                return;
            }

            long divisor = PollardRho(n);
            Factorize(divisor, primes, factors);
            Factorize(n / divisor, primes, factors);
        }

        //pollard rho implementation
        private static long PollardRho(long n)
        {
            if (n % 2 == 0)
                return 2;

            long x = rand.Next() % n + 1;
            long c = rand.Next() % n + 1;
            long y = x;
            long g = 1;

            //fn is f(x) = x*x + c
            while (g == 1)
            {
                x = ((x * x) % n + c) % n;
                y = ((y * y) % n + c) % n;
                y = ((y * y) % n + c) % n;
                g = GetGcd(Math.Abs(x - y), n);
            }

            return g;
        }

        public static long GetGcd(long a, long b)
        {
            long r = a % b;
            while (r > 0)
            {
                a = b;
                b = r;
                r = a % b;
            }

            return b;
        }

        public static long GetCombinationsCount(long total, long pickedCount)
        {
            long count = 1;

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

        public static bool IsPandigital(IEnumerable<int> numbers)
        {
            int[] digits = new int[10];

            foreach (var n in numbers)
            {
                var y = n;
                while (y != 0)
                {
                    digits[y % 10]++;
                    y /= 10;
                }
            }

            return digits.All(i => i <= 1);
        }

        public static bool IsPandigital(int y)
        {
            int[] digits = new int[10];

            while (y != 0)
            {
                digits[y % 10]++;
                y /= 10;
            }

            return digits.All(i => i == 0 || i == 1);
        }

        public static bool IsPandigital(string s, bool canContainsZero)
        {
            if (!canContainsZero && s.Contains('0'))
            {
                return false;
            }

            return s.Distinct().Count() == s.Length;
        }

        // am + bn = d
        public static long GetGcd(long m, long n, out long a, out long b)
        {
            a = 0;
            b = 1;
            long ap = 1; // a'
            long bp = 0; // b'
            long q = m / n;
            long r = m % n;
            while (r > 0)
            {
                m = n;
                n = r;
                long t = ap;
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

        public static int DigitSum(long number)
        {
            int sum = 0;
            while (number != 0)
            {
                sum += (int)(number % 10);
                number /= 10;
            }

            return sum;
        }

        /// <summary>
        /// Use sieving method to genarate primes from 0 to end
        /// </summary>
        /// <returns>The array contains primes and 0 if its index is not prime</returns>
        public static long[] GenPrimes(long end)
        {
            var primes = new long[end];
            for (long i = 0; i < primes.Length; i++)
            {
                primes[i] = i;
            }

            primes[1] = 0;

            for (long i = 0; i <= Math.Sqrt(primes.Length); i++)
            {
                if (primes[i] != 0)
                {
                    long p = primes[i];
                    for (long j = 2; j * p < end; j++)
                    {
                        primes[j * p] = 0;
                    }
                }
            }

            return primes;
        }

        public static long Factorial(long i)
        {
            if (i < 0)
            {
                throw new ArgumentException("i should be natural number");
            }

            if (i == 0 || i == 1)
            {
                return 1;
            }

            return i * Factorial(i - 1);
        }

        public static bool IsPalindrome(string s)
        {
            if (s == null)
            {
                return true;
            }

            for (int i = 0; i < s.Length / 2; i++)
            {
                if (s[i] != s[s.Length - i - 1])
                {
                    return false;
                }
            }

            return true;
        }

        public static bool IsPrime(long number, long[] primes)
        {
            if (number <= 1)
            { return false; }

            if (number == 2)
            { return true; }

            long max = (long)Math.Ceiling(Math.Sqrt(number));
            foreach (long n in primes)
            {
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

        public static bool IsPrime(long number)
        {
            // I think the negative number is not prime
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

            long max = (long)Math.Ceiling(Math.Sqrt(number));
            for (long i = 3; i <= max; i += 2)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Returns all permutations of the input <see cref="IEnumerable{T}"/>.
        /// </summary>
        /// <param name="source">The list of items to permute.</param>
        /// <returns>A collection containing all permutations of the input <see cref="IEnumerable&lt;T&gt;"/>.</returns>
        public static IEnumerable<IEnumerable<T>> Permutations<T>(this IEnumerable<T> source)
        {
            if (source == null)
            {
                throw new ArgumentNullException(nameof(source));
            }

            // Ensure that the source IEnumerable is evaluated only once
            return PermutationsImpl(source.ToArray());
        }

        private static IEnumerable<IEnumerable<T>> PermutationsImpl<T>(IEnumerable<T> source)
        {
            var c = source.Count();
            if (c == 1)
            {
                yield return source;
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    foreach (var p in PermutationsImpl(source.Take(i).Concat(source.Skip(i + 1))))
                    {
                        yield return source.Skip(i).Take(1).Concat(p);
                    }
                }
            }
        }

        public static bool IsPermutation(long x, long y)
        {
            if (x == y)
            {
                return true;
            }

            int[] digits = new int[10];

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

            return digits.All(i => i == 0);
        }

        public static long Reverse(long x)
        {
            long re = 0;
            while (x != 0)
            {
                var d = x % 10;
                x /= 10;

                re *= 10;
                re += d;
            }

            return re;
        }
    }
}
