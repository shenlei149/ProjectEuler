using System;
using System.Linq;

namespace ProjectEuler
{
    public class S500 : ISolution
    {
        public string GetAnswer()
        {
            const long mod = 500500507;
            long answer = 1;
            var primes = Utils.GenPrimes(8000000).Where(l => l != 0).ToList();

            for (int i = 0; i < 500084; i++)
            {
                answer *= primes[i];
                answer %= mod;
            }

            for (int i = 0; i < 396; i++)
            {
                answer *= (long)Math.Pow(primes[i], 2);
                answer %= mod;

            }

            for (int i = 0; i < 15; i++)
            {
                answer *= (long)Math.Pow(primes[i], 4);
                answer %= mod;
            }

            for (int i = 0; i < 4; i++)
            {
                answer *= (long)Math.Pow(primes[i], 8);
                answer %= mod;
            }

            answer *= (long)Math.Pow(primes[0], 16);

            return (answer % mod).ToString();
        }
    }
}
