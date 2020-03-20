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
                    int first = (int)leading;
                    int second = (int)(leading * 10) - first * 10;
                    int third = (int)(leading * 100) - first * 100 - second * 10;

                    if (first == 1 && second == 2 && third == 3)
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
