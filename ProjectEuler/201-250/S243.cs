using System.Linq;
using System;

namespace ProjectEuler
{
    public class S243 : ISolution
    {
        public string GetAnswer()
        {
            int[] primes = Utils.GenPrimes(50).Where(l => l != 0).Select(Convert.ToInt32).ToArray();
            long c = 1;
            long d = 1;
            foreach (var p in primes)
            {
                c *= p - 1;
                d *= p;
                if (c * 94744L < d * 15499L)
                {
                    break;
                }
            }

            for (int i = 2; i <= primes.Last(); i++)
            {
                long n = d * i;
                if (c * n * 94744L < d * (n - 1) * 15499L)
                {
                    return n.ToString();
                }
            }

            return string.Empty;
        }
    }
}
