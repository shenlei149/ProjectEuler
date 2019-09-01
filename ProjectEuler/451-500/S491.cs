using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S491 : ISolution
    {
        private static readonly long Factorial10 = Utils.Factorial(10);

        public string GetAnswer()
        {
            long ret = 0;
            HashSet<string> combinations = new HashSet<string>();
            var allDigits = new List<int> { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9 };
            var odds = Utils.Combination(allDigits, 10);

            foreach (var odd in odds)
            {
                int sum = odd.Sum();
                if (sum == 23 || sum == 34 || sum == 45 || sum == 56 || sum == 67)
                {
                    string com = string.Join("_", odd);
                    if (!combinations.Contains(com))
                    {
                        combinations.Add(com);
                        var even = GetRemainNumbers(odd);
                        ret += GetPCount(even) * GetPCount(odd);
                    }
                }
            }

            return (ret * 9 / 10).ToString();
        }

        private static long GetPCount(IEnumerable<int> source)
        {
            long ret = Factorial10;
            int n = 10 - source.Distinct().Count();
            for (int i = 0; i < n; i++)
            {
                ret /= 2;
            }

            return ret;
        }

        private static IEnumerable<int> GetRemainNumbers(IEnumerable<int> subtracter)
        {
            var bits = new bool[20];
            foreach (var bit in subtracter)
            {
                if (bits[bit * 2])
                {
                    bits[bit * 2 + 1] = true;
                }
                else
                {
                    bits[bit * 2] = true;
                }
            }

            var ret = new List<int>();
            for (int i = 0; i < bits.Length; i++)
            {
                if (!bits[i])
                {
                    ret.Add(i / 2);
                }
            }

            return ret;
        }
    }
}
