using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S686 : ISolution
    {
        private static readonly Dictionary<int, int[]> Next =
            new Dictionary<int, int[]>
            {
                { 196, new int[]{ 289,485 }},
                { 289, new int[]{ 196 }},
                { 485, new int[]{ 196, 485 }},
            };

        private static readonly double Log102 = Math.Log10(2);

        public string GetAnswer()
        {
            int n = 1;
            int j = 90;
            int diff = 196;
            while (true)
            {
                var nexts = Next[diff];
                foreach (var next in nexts)
                {
                    int newJ = j + next;
                    var d = newJ * Log102;
                    var rem = d - (int)d;

                    var leading = Math.Pow(10, rem);
                    int num = (int)(leading * 100);

                    if (num == 123)
                    {
                        diff = next;
                        j = newJ;
                        n++;
                        break;
                    }
                }

                if (n == 678910)
                {
                    return j.ToString();
                }
            }
        }
    }
}
