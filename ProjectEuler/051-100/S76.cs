

using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S76 : ISolution
    {
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
            for (int ip = 3; ip < 101; ip++)
            {
                int k = 0;
                p.Add(0);
                for (int j = 2; q[j] <= ip; j++)
                {
                    int flag = k & 2;
                    if (flag == 0)
                    {
                        p[ip] = p[ip] + p[ip - q[j]];
                    }
                    else
                    {
                        p[ip] = p[ip] - p[ip - q[j]];
                    }

                    k++;
                }

                if (q.Last() < ip * 1.5)
                {
                    q.Add(iq * (iq * 3 - 1) / 2);
                    q.Add(iq * (iq * 3 + 1) / 2);
                    iq++;
                }
            }

            return (p.Last() - 1).ToString();
        }
    }
}
