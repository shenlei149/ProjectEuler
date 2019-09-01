using System;
using System.Linq;

namespace ProjectEuler
{
    public class S49 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(10000).Where(l => l > 1487).Select(Convert.ToInt32).ToArray();
            int length = primes.Length;

            for (int i = 0; i < length - 2; i++)
            {
                for (int j = i + 1; j < length - 1; j++)
                {
                    if (Utils.IsPermutation(primes[i], primes[j]))
                    {
                        for (int k = j + 1; k < length; k++)
                        {
                            if (primes[j] * 2 == primes[i] + primes[k] && Utils.IsPermutation(primes[i], primes[k]))
                            {
                                return string.Format("{0}{1}{2}", primes[i], primes[j], primes[k]);
                            }
                        }
                    }
                }
            }

            return string.Empty;
        }
    }
}
