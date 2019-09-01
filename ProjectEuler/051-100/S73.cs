namespace ProjectEuler
{
    public class S73 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            var primes = Utils.GenPrimes(12001);
            double l = (double)1 / 3;
            double h = (double)1 / 2;
            for (int i = 5; i <= 12000; i++)
            {
                var ps = Utils.Factorize(i, primes).Keys;
                for (int j = i / 3; j < i / 2 + 1; j++)
                {
                    bool meet = true;
                    foreach (var p in ps)
                    {
                        if (j % p == 0)
                        {
                            meet = false;
                            break;
                        }
                    }

                    if (meet)
                    {
                        double div = (double)j / i;

                        if (div > l && div < h)
                        {
                            count++;
                        }
                    }
                }
            }

            return count.ToString();
        }
    }
}
