using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S429 : ISolution
    {
        public string GetAnswer()
        {
            long m = 1000000009;
            long n = 100000000;

            var primes = Utils.GenPrimes2(n);

            // https://en.wikipedia.org/wiki/Legendre%27s_formula
            var factors = new Dictionary<long, int>();
            foreach (var p in primes)
            {
                int i = 1;
                int power = 0;
                while (true)
                {
                    var cur = n / (long)Math.Pow(p, i);
                    if (cur == 0)
                    {
                        break;
                    }

                    power += (int)cur;
                    i++;
                }

                factors[p] = power;
            }

            // http://mathworld.wolfram.com/UnitaryDivisorFunction.html
            long ret = 1;
            foreach (var pair in factors)
            {
                var p = pair.Key;
                var k = pair.Value * 2;

                long r = PowMod(p, k, m);

                ret *= (r + 1);
                ret %= m;
            }

            return ret.ToString();
        }

        // return p^k mod m
        static long PowMod(long p, int k, long m)
        {
            if (k == 0)
            { return 1; }

            if (k == 1)
            { return p % m; }

            var half = PowMod(p, k / 2, m);
            if (k % 2 == 0)
            {
                return (half * half) % m;
            }
            else
            {
                return (((half * half) % m) * p) % m;
            }
        }
    }
}
