using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S74 : ISolution
    {
        private readonly int MAX = 1000000;

        public string GetAnswer()
        {
            Dictionary<int, int> nexts = new Dictionary<int, int>();
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

            Dictionary<int, int> length = new Dictionary<int, int>();
            for (int i = 3; i < MAX; i++)
            {
                HashSet<int> numbers = new HashSet<int>();
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
                int product = 1;
                for (int j = 2; j <= m; j++)
                {
                    product *= j;
                }

                sum += product;

                i /= 10;
            }

            return sum;
        }
    }
}
