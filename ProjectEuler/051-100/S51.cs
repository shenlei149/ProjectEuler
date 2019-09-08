using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S51 : ISolution
    {
        private static readonly string[] patterns = new string[] { "110001", "101001", "100101",
            "100011", "011001", "010101", "010011", "001101", "001011", "000111" };

        public string GetAnswer()
        {
            var groups = new List<List<int>>();
            for (int i = 0; i < patterns.Length; i++)
            {
                groups.Add(new List<int>());
            }

            var primes = Utils.GenPrimes(1000000).Where(l => l > 100000).Select(l => (int)l).ToArray();
            foreach (var p in primes)
            {
                var pStr = p.ToString();
                for (int i = 0; i < patterns.Length; i++)
                {
                    string pattern = patterns[i];
                    char[] chars = new char[3];
                    int index = 0;
                    for (int j = 0; j < pattern.Length; j++)
                    {
                        if (pattern[j] == '0')
                        {
                            chars[index] = pStr[j];
                            index++;
                        }
                    }

                    if (chars[0] == chars[1] && chars[1] == chars[2])
                    {
                        groups[i].Add(p);
                    }
                }
            }

            for (int i = 0; i < patterns.Length; i++)
            {
                var group = groups[i];
                var eight = HandleGroup(group, patterns[i]);
                if (eight.Count > 0)
                {
                    return eight.First().First().ToString();
                }
            }

            return string.Empty;
        }

        private static List<List<int>> HandleGroup(List<int> primes, string pattern)
        {
            Dictionary<int, List<int>> subGroups = new Dictionary<int, List<int>>();
            for (int i = 0; i < primes.Count; i++)
            {
                int p = primes[i];
                int key = 0;
                for (int j = pattern.Length - 1; j >= 0; j--)
                {
                    if (pattern[j] == '1')
                    {
                        key *= 10;
                        key += p % 10;
                    }

                    p /= 10;
                }

                if (subGroups.ContainsKey(key))
                {
                    subGroups[key].Add(primes[i]);
                }
                else
                {
                    subGroups[key] = new List<int> { primes[i] };
                }
            }

            return subGroups.Values.Where(ints => ints.Count == 8).ToList();
        }
    }
}
