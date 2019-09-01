using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S87 : ISolution
    {
        private static readonly int MAX = 50000000;

        public string GetAnswer()
        {
            List<int> numbers = new List<int>();
            int[] primes = Utils.GenPrimes(7500).Where(l => l != 0).Select(Convert.ToInt32).ToArray();
            for (int i = 0; primes[i] < 7072; i++)
            {
                int first = primes[i] * primes[i];
                for (int j = 0; first < MAX && primes[j] < 369; j++)
                {
                    int second = first + primes[j] * primes[j] * primes[j];
                    for (int k = 0; second < MAX && primes[k] < 85; k++)
                    {
                        int third = second + primes[k] * primes[k] * primes[k] * primes[k];
                        if (third < MAX)
                        {
                            numbers.Add(third);
                        }
                    }
                }
            }

            return numbers.Distinct().Count().ToString();
        }
    }
}
