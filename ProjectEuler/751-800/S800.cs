using System;
using System.Linq;

namespace ProjectEuler
{
    public class S800 : ISolution
    {
        // private static int M = 800;
        private static int M = 800800;

        public string GetAnswer()
        {
            // var primes = Utils.GenPrimes(10_000).Where(l => l != 0).ToArray();
            var primes = Utils.GenPrimes(15710000).Where(l => l != 0).ToArray();
            double[] logs = new double[primes.Length];
            for (int i = 0; i < primes.Length; i++)
            {
                logs[i] = Math.Log(primes[i]);
            }

            var limit = M * Math.Log(M);

            long count = 0;
            int pindex = 0;
            while (true)
            {
                int p = (int)primes[pindex];
                var logp = logs[pindex];
                int q = (int)(M * Math.Log(M, p)) - p;
                if (q <= p)
                { break; }

                int qindex = Array.BinarySearch(primes, q);
                if (qindex < 0)
                    qindex = ~qindex;

                q = (int)primes[qindex];
                while (true)
                {
                    if (q * logp + p * logs[qindex] < limit)
                    { break; }

                    qindex--;
                    q = (int)primes[qindex];

                    if (qindex <= pindex)
                    { break; }
                }

                count += qindex - pindex;

                pindex++;
            }

            return count.ToString();
        }
    }
}
