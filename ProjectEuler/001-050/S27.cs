using System.Collections.Generic;

namespace ProjectEuler
{
    public class S27 : ISolution
    {
        struct ABAndMaxPrime
        {
            internal int A;
            internal int B;
            internal int PrimeCount;
        }

        public string GetAnswer()
        {
            var primes = new List<ABAndMaxPrime>();

            for (int a = -999; a < 1000; a++)
            {
                for (int b = -999; b < 1000; b++)
                {
                    var tmp = new ABAndMaxPrime
                    {
                        A = a,
                        B = b,
                        PrimeCount = 0
                    };

                    for (int n = 0; ; n++)
                    {
                        int formula = n * n + a * n + b;
                        if (Utils.IsPrime(formula))
                        {
                            tmp.PrimeCount++;
                        }
                        else
                        {
                            primes.Add(tmp);
                            break;
                        }
                    }
                }
            }

            var max = new ABAndMaxPrime();
            foreach (var prime in primes)
            {
                if (prime.PrimeCount > max.PrimeCount)
                {
                    max = prime;
                }
            }

            return (max.A * max.B).ToString();
        }
    }
}
