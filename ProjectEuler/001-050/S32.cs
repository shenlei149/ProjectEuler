using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S32 : ISolution
    {
        private static readonly char[] digits = new char[] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        private static readonly Dictionary<string, HashSet<int>> cache = new Dictionary<string, HashSet<int>>();

        public string GetAnswer()
        {
            int sum = 0;
            for (int i = 1000; i < 10000; i++)
            {
                if (Utils.IsPandigital(i.ToString(), false))
                {
                    char[] products = i.ToString().ToCharArray();
                    char[] factorDigits = digits.Except(products).ToArray();

                    if (IsPandigitalProduct(i, factorDigits))
                    {
                        sum += i;
                    }
                }
            }

            return sum.ToString();
        }

        private static int CharsToInt(IEnumerable<char> chars)
        {
            int i = 0;
            foreach (var c in chars)
            {
                i *= 10;
                i += c - '0';
            }

            return i;
        }

        private static bool IsPandigitalProduct(int i, char[] factorDigits)
        {
            string s = string.Concat(factorDigits);
            if (!cache.ContainsKey(s))
            {
                cache[s] = new HashSet<int>();
                var factors = factorDigits.Permutations();
                foreach (var item in factors)
                {
                    for (int k = 1; k < 5; k++)
                    {
                        int n1 = CharsToInt(item.Take(k));
                        int n2 = CharsToInt(item.Skip(k));
                        cache[s].Add(n1 * n2);
                    }
                }
            }

            return cache[s].Contains(i);
        }
    }
}
