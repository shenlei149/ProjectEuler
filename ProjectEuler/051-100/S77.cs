using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectEuler
{
    public class S77 : ISolution
    {
        private static readonly int Max = 5000;

        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(Max).Where(l => l != 0).Reverse().Select(Convert.ToInt32).ToArray();
            for (int i = 2; i < Max; i++)
            {
                int count = Count(i, primes);
                if (count >= Max)
                {
                    return i.ToString();
                }
            }

            return string.Empty;
        }

        private static int Count(int sum, int[] primes)
        {
            int index = Array.BinarySearch(primes, sum);
            if (index < 0)
            {
                index = ~index;
            }

            return Count(sum, index, primes);
        }

        private static int Count(int sum, int index, int[] primes)
        {
            if (sum == 0)
            {
                return 1;
            }

            if (sum < 0 || index >= primes.Length)
            {
                return 0;
            }

            return Count(sum - primes[index], index, primes) + Count(sum, index + 1, primes);
        }
    }
}
