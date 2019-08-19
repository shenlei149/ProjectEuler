using System;
using System.Linq;

namespace ProjectEuler
{
    public class S357 : ISolution
    {
        public string GetAnswer()
        {
            long[] primes = Utils.GenPrimes(100000000);
            var candidates = primes.Where(p => p != 0 && (p - 1) % 4 != 0)
                .Select(p => p - 1).ToArray();

            long result = 0;
            foreach (int n in candidates)
            {
                bool meet = true;
                int h = (int)Math.Sqrt(n);
                for (int i = 2; i <= h; i++)
                {
                    if (n % i != 0)
                    {
                        continue;
                    }

                    int d = n / i;
                    if (primes[d + i] == 0)
                    {
                        meet = false;
                        break;
                    }
                }

                if (meet)
                {
                    result += n;
                }
            }

            return result.ToString();
        }
    }
}
