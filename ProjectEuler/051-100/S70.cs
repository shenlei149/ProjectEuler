using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S70 : ISolution
    {
        public string GetAnswer()
        {
            var primesForTesting = Utils.GenPrimes(10000000);
            int[] primes = Utils.GenPrimes(1000).Where(l => l != 0).Select(Convert.ToInt32).ToArray();

            int n = 0;
            double minRatio = double.MaxValue;

            List<int> numbers = new List<int>();
            for (int i = 1000000; i < 10000000; i++)
            {
                if (Meet(i, primes))
                {
                    numbers.Add(i);
                }
            }

            foreach (var i in numbers)
            {
                if (primesForTesting[i] != 0)
                {
                    continue;
                }

                int count = Utils.GetCoprimeCount(i);
                if (((double)i) / count < minRatio)
                {
                    if (Utils.IsPermutation(i, count))
                    {
                        minRatio = ((double)i) / count;
                        n = i;
                    }
                }
            }

            return n.ToString();
        }

        private static bool Meet(int i, int[] primes)
        {
            foreach (var prime in primes)
            {
                if (i % prime == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
