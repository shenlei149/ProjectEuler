using System;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S110 : ISolution
    {
        private readonly int MAX = 4_000_000;
        private readonly int[] Primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
        private readonly int[] MaxPower = new int[] { 9, 5, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
        // 18,700,260,099,721,200
        private BigInteger min = long.MaxValue;

        public string GetAnswer()
        {
            Check(new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0);
            return min.ToString();
        }

        private void Check(int[] power, int index)
        {
            if (index == power.Length)
            {
                int count = 1;
                foreach (var item in power)
                {
                    count *= (1 + item * 2);
                }
                count++;
                count /= 2;

                if (count > MAX)
                {
                    var n = Primes.Zip(power, (i, j) => (long)Math.Pow(i, j))
                        .Select(l => (BigInteger)l).Aggregate(BigInteger.Multiply);
                    if (n < min)
                    {
                        min = n;
                    }
                }
            }
            else
            {
                for (int i = 0; i <= MaxPower[index]; i++)
                {
                    var copy = power.ToArray();
                    copy[index] = i;
                    Check(copy, index + 1);
                }
            }
        }
    }
}
