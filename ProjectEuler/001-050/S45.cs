using System.Linq;

namespace ProjectEuler
{
    public class S45 : ISolution
    {
        private static readonly long N = 1000000;

        public string GetAnswer()
        {
            long[] Ts = new long[N];
            long[] Ps = new long[N];
            long[] Hs = new long[N];

            for (long i = 1; i <= N; i++)
            {
                Ts[i - 1] = i * (i + 1) / 2;
                Ps[i - 1] = i * (3 * i - 1) / 2;
                Hs[i - 1] = i * (2 * i - 1);
            }

            return Ts.Intersect(Ps).Intersect(Hs).Take(3).Last().ToString();
        }
    }
}
