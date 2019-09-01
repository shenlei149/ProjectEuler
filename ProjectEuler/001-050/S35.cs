using System.Collections.Generic;

namespace ProjectEuler
{
    public class S35 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            var primes = Utils.GenPrimes(1000000);
            for (int i = 0; i < primes.Length; i++)
            {
                if (primes[i] != 0)
                {
                    if (IsCircularPrime(primes[i], primes))
                    {
                        count++;
                    }
                }
            }

            return count.ToString();
        }

        private static List<long> GetRotations(long i)
        {
            string tmp = i.ToString();
            int length = tmp.Length;
            tmp += tmp;

            List<long> rotations = new List<long>();
            for (int j = 0; j < length; j++)
            {
                rotations.Add(long.Parse(tmp.Substring(j, length)));
            }

            return rotations;
        }

        private static bool IsCircularPrime(long prime, long[] primes)
        {
            var rotations = GetRotations(prime);

            foreach (var i in rotations)
            {
                if (primes[i] == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
