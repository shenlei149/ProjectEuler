using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S78 : ISolution
    {
        private static readonly int MOD = 1_000_000;

        // https://en.wikipedia.org/wiki/Partition_%28number_theory%29
        public string GetAnswer()
        {
            var q = new List<int>();
            int iq = 0;
            for (; iq < 10; iq++)
            {
                q.Add(iq * (iq * 3 - 1) / 2);
                q.Add(iq * (iq * 3 + 1) / 2);
            }

            var p = new List<int>() { 1, 1, 2 };
            int ip = 3;
            while (true)
            {
                int k = 0;
                p.Add(0);
                for (int j = 2; q[j] <= ip; j++)
                {
                    int flag = k & 2;
                    if (flag == 0)
                    {
                        p[ip] = (p[ip] + p[ip - q[j]] + MOD) % MOD;
                    }
                    else
                    {
                        p[ip] = (p[ip] - p[ip - q[j]] + MOD) % MOD;
                    }

                    k++;
                }

                if (p[ip] == 0)
                {
                    return ip.ToString();
                }

                ip++;

                if (q.Last() < ip * 1.5)
                {
                    q.Add(iq * (iq * 3 - 1) / 2);
                    q.Add(iq * (iq * 3 + 1) / 2);
                    iq++;
                }
            }
        }
    }
}
