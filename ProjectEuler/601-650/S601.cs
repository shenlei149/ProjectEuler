using System;
using System.Linq;

namespace ProjectEuler
{
    public class S601 : ISolution
    {
        public string GetAnswer()
        {
            return Enumerable.Range(1, 31).Select(i => P(i, 1L << 2 * i)).Sum().ToString();
        }

        private static long P(int s, long N)
        {
            long lcm = Enumerable.Range(1, s)
                .Select(Convert.ToInt64)
                .Aggregate((cur, next) => Utils.GetLcm(cur, next));

            return Enumerable.Range(1, (int)((N - 2) / lcm))
                .Select(i => i * lcm + 1)
                .Count(c => (c + s) % (s + 1) != 0);
        }
    }
}
