using System.Linq;

namespace ProjectEuler
{
    public class S381 : ISolution
    {
        public string GetAnswer()
        {
            long sum = 0;

            var primes = Utils.GenPrimes(100000000).Where(p => p >= 5);
            foreach (var p in primes)
            {
                Utils.GetGcd(p, p - 2, out _, out long p2);
                Utils.GetGcd(p, p - 3, out _, out long p3);
                Utils.GetGcd(p, p - 4, out _, out long p4);

                long s3 = ((p2 % p) + p) % p;
                long s4 = ((s3 * p3) % p + p) % p;
                long s5 = ((s4 * p4) % p + p) % p;
                long s = ((s3 + s4 + s5) % p + p) % p;
                sum += s;
            }

            return sum.ToString();
        }
    }
}
