using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S74 : ISolution
    {
        private static readonly int MAX = 1000000;
        private static readonly List<int> factorials = new() { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

        public string GetAnswer()
        {
            var nexts = new Dictionary<int, int>();
            for (int i = 1; i < MAX; i++)
            {
                int key = i;
                int value = GetNext(i);
                nexts[key] = value;

                while (value > MAX)
                {
                    key = value;
                    value = GetNext(key);
                    nexts[key] = value;
                }
            }

            var length = new Dictionary<int, int>();
            for (int i = 3; i < MAX; i++)
            {
                var numbers = new HashSet<int>();
                int cur = i;
                while (!numbers.Contains(cur))
                {
                    if (length.ContainsKey(cur))
                    {
                        length[i] = numbers.Count + length[cur];
                        break;
                    }

                    numbers.Add(cur);
                    cur = nexts[cur];
                }

                if (!length.ContainsKey(i))
                {
                    length[i] = numbers.Count;
                }
            }

            return length.Values.Count(v => v == 60).ToString();
        }

        private static int GetNext(int i)
        {
            int sum = 0;
            while (i != 0)
            {
                int m = i % 10;
                sum += factorials[m];

                i /= 10;
            }

            return sum;
        }
    }
}
