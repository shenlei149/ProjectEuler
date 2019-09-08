using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S64 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;

            var l1 = Enumerable.Range(1, 10000);
            var l2 = Enumerable.Range(1, 100).Select(x => x * x);
            var candidates = l1.Except(l2);
            foreach (var c in candidates)
            {
                if (GetPeriod(c) % 2 != 0)
                {
                    count++;
                }
            }

            return count.ToString();
        }

        /*
         * Refer to 
         * https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
         */
        private static int GetPeriod(int S)
        {
            int a0 = (int)Math.Sqrt(S);
            int m = 0;
            int d = 1;
            int a = a0;
            var periods = new List<Tuple<int, int, int>>();
            while (true)
            {
                m = d * a - m;
                d = (S - m * m) / d;
                a = (a0 + m) / d;
                var cur = Tuple.Create(m, d, a);
                int index = periods.IndexOf(cur);
                if (index >= 0)
                {
                    return periods.Count - index;
                }
                else
                {
                    periods.Add(cur);
                }
            }
        }
    }
}
