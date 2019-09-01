using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S125 : ISolution
    {
        private static readonly int MAX = 100000000;

        public string GetAnswer()
        {
            var squars = Enumerable.Range(1, (int)Math.Sqrt(MAX / 2)).Select(i => i * i).ToArray();
            var candidates = new List<long>();
            for (int i = 0; i < squars.Length - 1; i++)
            {
                long sum = squars[i];
                for (int j = i + 1; j < squars.Length; j++)
                {
                    if (sum + squars[j] < MAX)
                    {
                        sum += squars[j];
                        candidates.Add(sum);
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return candidates.Distinct().Where(l => Utils.IsPalindrome(l.ToString())).Sum().ToString();
        }
    }
}
