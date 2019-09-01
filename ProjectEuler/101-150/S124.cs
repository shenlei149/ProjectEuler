using System;

namespace ProjectEuler
{
    public class S124 : ISolution
    {
        public string GetAnswer()
        {
            long[] primes = Utils.GenPrimes(100001);

            NAndRadN[] results = new NAndRadN[100000];

            for (long i = 1; i <= 100000; i++)
            {
                var fac = Utils.Factorize(i, primes).Keys;
                long p = 1;
                foreach (var f in fac)
                {
                    p *= f;
                }

                results[i - 1] = new NAndRadN { N = i, Rad = p };
            }

            Array.Sort(results);
            return results[9999].N.ToString();
        }

        class NAndRadN : IComparable<NAndRadN>
        {
            public long N { get; set; }
            public long Rad { get; set; }

            public int CompareTo(NAndRadN other)
            {
                if (Rad == other.Rad)
                {
                    return N.CompareTo(other.N);
                }
                else
                {
                    return Rad.CompareTo(other.Rad);
                }
            }
        }
    }
}
