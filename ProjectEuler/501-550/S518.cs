using System;
using System.Collections.Generic;
using System.Text;

namespace ProjectEuler
{
    public class S518 : ISolution
    {
        public string GetAnswer()
        {
            int end = 100000000;
            long sum = 0;
            var primes = Utils.GenPrimes(end);
            for (int i = 0; i < primes.Length; i++)
            {
                if (primes[i] != 0)
                {
                    var a = primes[i] + 1;
                    var factors = Utils.Factorize(a, primes);
                    var step = 1;
                    foreach (var f in factors)
                    {
                        step *= (int)Math.Pow(f.Key, (f.Value + 1) / 2);
                    }
                    for (long b = a + step; b < end; b += step)
                    {
                        var c = b * b / a;
                        if (c >= end)
                        {
                            break;
                        }

                        if (primes[b - 1] != 0 && primes[c - 1] != 0)
                        {
                            sum += a + b + c - 3;
                        }
                    }
                }
            }

            return sum.ToString();
        }
    }
}
