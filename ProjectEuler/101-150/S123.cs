using System.Linq;

namespace ProjectEuler
{
    public class S123 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(1000000).Where(p => p != 0).ToList();
            int n = 7039;
            for (; n < primes.Count; n += 2)
            {
                var r = 2 * n * primes[n - 1];
                if (r > 10000000000)
                {
                    break;
                }
            }

            return n.ToString();
        }
    }
}
