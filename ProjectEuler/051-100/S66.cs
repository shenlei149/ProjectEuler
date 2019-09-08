using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S66 : ISolution
    {
        public string GetAnswer()
        {
            var D = Enumerable.Range(1, 1000).Where(i => Math.Pow((int)Math.Sqrt(i), 2) != i);
            BigInteger max = 0;
            long ret = 0;
            foreach (var d in D)
            {
                BigInteger cur = GetX(d);
                if (max < cur)
                {
                    max = cur;
                    ret = d;
                }
            }

            return ret.ToString();
        }

        // http://www.kurims.kyoto-u.ac.jp/EMIS/journals/GMN/yahoo_site_admin/assets/docs/1_GMN-8492-V28N2.190180001.pdf
        private static BigInteger GetX(int n)
        {
            var a = new List<BigInteger>() { 0, 1 };
            var b = new List<BigInteger>() { 1, 0 };
            var c = new List<int>() { n, 1 };

            int i = 1;
            do
            {
                int q = (int)((Math.Sqrt(n - c[i - 1] * c[i]) + Math.Sqrt(n)) / c[i]);
                c.Add((int)(2 * q * Math.Sqrt(n - c[i - 1] * c[i]) + c[i - 1] - q * q * c[i]));
                a.Add(q * a[i] + a[i - 1]);
                b.Add(q * b[i] + b[i - 1]);

                i++;
            } while (a.Last() * a.Last() - n * b.Last() * b.Last() != 1);

            return a.Last();
        }
    }
}
