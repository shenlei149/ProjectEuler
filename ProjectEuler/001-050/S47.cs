namespace ProjectEuler
{
    public class S47 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(200_000);
            long[] results = new long[4];
            int index = 0;
            for (long i = 646; ; i++)
            {
                if (Utils.Factorize(i, primes).Count == 4)
                {
                    results[index] = i;
                    index++;
                    if (index == 4)
                    {
                        break;
                    }
                }
                else
                {
                    index = 0;
                }
            }

            return results[0].ToString();
        }
    }
}
