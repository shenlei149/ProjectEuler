namespace ProjectEuler
{
    public class S50 : ISolution
    {
        private readonly long MAX = 1000000;

        public string GetAnswer()
        {
            int maxCount = 0;
            long maxPrime = 0;
            var primes = Utils.GenPrimes(MAX);

            for (int i = 0; i < primes.Length; i++)
            {
                if (primes[i] == 0)
                {
                    continue;
                }

                long sum = 0;
                int count = 0;
                for (int j = i; j < primes.Length; j++)
                {
                    if (primes[j] == 0)
                    {
                        continue;
                    }

                    sum += primes[j];
                    count++;
                    if (sum >= MAX)
                    {
                        break;
                    }

                    if (primes[sum] != 0)
                    {
                        if (count > maxCount)
                        {
                            maxCount = count;
                            maxPrime = primes[sum];
                        }
                    }
                }
            }

            return maxPrime.ToString();
        }
    }
}
