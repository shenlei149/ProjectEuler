using System;
using System.Linq;

namespace ProjectEuler
{
    public class S187 : ISolution
    {
        private static readonly long MAX = 100000000;

        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(MAX / 2).Where(l => l != 0).ToArray();
            long count = 0;
            foreach (var p in primes)
            {
                long m = MAX / p;
                int index = Array.BinarySearch(primes, m);
                if (index >= 0)
                {
                    count += index + 1;
                }
                else
                {
                    count += ~index;
                }
            }

            count += ~Array.BinarySearch(primes, (long)Math.Sqrt(MAX));

            return (count / 2).ToString();
        }
    }
}
