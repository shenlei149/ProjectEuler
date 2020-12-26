using System.Linq;
using System;
using System.Text;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S719 : ISolution
    {
        private readonly long[] Pows = new long[] {1,10,100,1000, 10000,
            100000, 1000000, 10000000,100000000,1000000000,
            10000000000,100000000000,1000000000000};

        private readonly Dictionary<int, List<Pattern>> patterns = new Dictionary<int, List<Pattern>>();
        private readonly Dictionary<string, List<Pattern>> mappings = new Dictionary<string, List<Pattern>>();

        public string GetAnswer()
        {
            for (int i = 2; i <= 12; i++)
            {
                patterns[i] = GetAllPatternsByLength(i);
            }

            long END = 1_000_000;
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
            var patterns = GetPatterns(root, S);
            int sLength = (int)Math.Floor(Math.Log10(S) + 1);
            foreach (var pattern in patterns)
            {
                long sum = 0;
                foreach (var pair in pattern.Pairs)
                {
                    sum += S / Pows[sLength - pair.Item1 - pair.Item2] % Pows[pair.Item2];

                    if (sum > root)
                    {
                        break;
                    }
                }

                if (sum == root)
                {
                    return true;
                }
            }

            return false;
        }

        private List<Pattern> GetPatterns(long root, long S)
        {
            int rootLength = (int)Math.Floor(Math.Log10(root) + 1);
            int sLength = (int)Math.Floor(Math.Log10(S) + 1);

            while (root > 100)
            {
                root /= 10;
            }

            var t = root >= 21;
            string key = rootLength + "_" + sLength + (t ? "T" : "F");
            if (!mappings.ContainsKey(key))
            {
                if (t)
                {
                    mappings[key] = patterns[sLength].Where(p => p.GetMaxLength() == rootLength).ToList();
                }
                else
                {
                    mappings[key] = patterns[sLength].Where(p => p.GetMaxLength() == rootLength || p.GetMaxLength() == rootLength - 1).ToList();
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
