using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S348 : ISolution
    {
        public string GetAnswer()
        {
            var counts = new Dictionary<int, int>();
            for (int i = 2; i < Math.Sqrt(int.MaxValue); i++)
            {
                for (int j = 2; j < 1291; j++)
                {
                    long sum = i * i + j * j * j;
                    if (sum > int.MaxValue)
                    {
                        break;
                    }

                    int s = (int)sum;
                    if (Utils.IsPalindrome(s.ToString()))
                    {
                        if (counts.ContainsKey(s))
                        {
                            counts[s]++;
                        }
                        else
                        {
                            counts[s] = 1;
                        }
                    }
                }
            }

            var candidates = counts.Where(pair => pair.Value == 4).Select(pair => pair.Key).ToList();
            candidates.Sort();

            return candidates.Take(5).Sum().ToString();
        }
    }
}
