using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S347 : ISolution
    {
        private static readonly int MAX = 10000000;

        public string GetAnswer()
        {
            var Ms = new List<long>();

            var primes = Utils.GenPrimes(MAX / 2);
            for (int i = 0; ; i++)
            {
                if (primes[i] == 0)
                {
                    continue;
                }

                if (primes[i] > Math.Sqrt(MAX))
                {
                    break;
                }

                for (int j = i + 1; j < primes.Length; j++)
                {
                    if (primes[j] == 0)
                    {
                        continue;
                    }

                    long p = primes[i];
                    long q = primes[j];
                    if (p * q < MAX)
                    {
                        Ms.Add(GetM(p, q));
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return Ms.Sum().ToString(); ;
        }

        private static long GetM(long p, long q)
        {
            var max = 0L;
            var e1Max = (int)(Math.Log(MAX) / Math.Log(p));
            var e2Max = (int)(Math.Log(MAX) / Math.Log(q));
            for (int e1 = 0; e1 < e1Max; e1++)
            {
                for (int e2 = 0; e2 < e2Max; e2++)
                {
                    var product = Math.Pow(p, e1 + 1) * Math.Pow(q, e2 + 1);
                    if (product > MAX)
                    {
                        break;
                    }

                    if (product <= MAX && product > max)
                    {
                        max = (long)product;
                    }
                }
            }

            return max;
        }
    }
}
