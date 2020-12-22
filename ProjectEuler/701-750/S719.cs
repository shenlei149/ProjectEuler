using System.Linq;
using System;
using System.Text;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S719 : ISolution
    {
        private Dictionary<int, List<Pattern>> patterns = new Dictionary<int, List<Pattern>>();
        private Dictionary<string, List<Pattern>> mappings = new Dictionary<string, List<Pattern>>();

        public string GetAnswer()
        {
            for (int i = 2; i <= 12; i++)
            {
                patterns[i] = GetAllPatternsByLength(i);
            }

            long END = 1_000_000; // 128088830547982 ~62s
            long sum = END * END;

            // 1, 4, 9 cannot be split into 2 or more numbers
            for (long i = 4; i < END; i++)
            {
                long S = i * i;
                if (CanBeSplit(i, S))
                {
                    sum += S;
                }
            }

            return sum.ToString();
        }

        private bool CanBeSplit(long root, long S)
        {
            int rootLength = (int)Math.Floor(Math.Log10(root) + 1);
            int sLength = (int)Math.Floor(Math.Log10(S) + 1);
            var patterns = GetPatterns(rootLength, sLength);
            string strS = S.ToString();
            foreach (var pattern in patterns)
            {
                int sum = 0;
                foreach (var pair in pattern.Pairs)
                {
                    sum += int.Parse(strS.Substring(pair.Item1, pair.Item2));
                }

                if (sum == root)
                {
                    return true;
                }
            }

            return false;
        }

        private List<Pattern> GetPatterns(int rootLength, int length)
        {
            string key = rootLength + "_" + length;
            if (!mappings.ContainsKey(key))
            {
                if (rootLength * 2 == length)
                {
                    mappings[key] = patterns[length].Where(p => p.GetMaxLength() == rootLength).ToList();
                }
                else
                {
                    mappings[key] = patterns[length].Where(p => p.GetMaxLength() == rootLength || p.GetMaxLength() == rootLength - 1).ToList();
                }
            }

            return mappings[key];
        }

        private List<Pattern> GetAllPatternsByLength(int length)
        {
            var result = new List<Pattern>() { new Pattern().AddPair(Tuple.Create(0, length)) };
            for (int i = 1; i < length; i++)
            {
                var subPatterns = GetAllPatternsByLength(length - i);
                result.AddRange(subPatterns.Select(pattern => pattern.AddOffset(i).AddPair(Tuple.Create(0, i))));
            }

            return result;
        }

        class Pattern
        {
            // (start, length)
            public List<Tuple<int, int>> Pairs { get; private set; }
            private int max;

            public Pattern()
            {
                Pairs = new List<Tuple<int, int>>();
            }

            public Pattern AddPair(Tuple<int, int> pair)
            {
                Pairs.Add(pair);
                if (pair.Item2 > max)
                {
                    max = pair.Item2;
                }

                return this;
            }

            public Pattern AddOffset(int offset)
            {
                var result = new Pattern();
                foreach (var pair in Pairs)
                {
                    result.AddPair(Tuple.Create(pair.Item1 + offset, pair.Item2));
                }

                return result;
            }

            public int GetMaxLength()
            {
                return max;
            }

            public override string ToString()
            {
                var sb = new StringBuilder();
                sb.Append('[');
                foreach (var pair in Pairs)
                {
                    sb.Append('(').Append(pair.Item1).Append(',').Append(pair.Item2).Append(')');

                }
                sb.Append(']');

                return sb.ToString();
            }
        }
    }
}
