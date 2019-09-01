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
            long ret = 1;

            long[] primes = Utils.GenPrimes(n);

            // https://en.wikipedia.org/wiki/Legendre%27s_formula
            var factors = new Dictionary<long, int>();
            foreach (var p in primes)
            {
                if (p != 0)
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
            }

            // http://mathworld.wolfram.com/UnitaryDivisorFunction.html
            foreach (var pair in factors)
            {
                var p = pair.Key;
                var k = pair.Value * 2;

                long r = 1;
                for (int i = 0; i < k; i++)
                {
                    r *= p;
                    r %= m;
                }

                ret *= (r + 1);
                ret %= m;
            }

            return ret.ToString();
        }
    }
}
