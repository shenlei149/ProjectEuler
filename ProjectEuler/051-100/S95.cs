using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S95 : ISolution
    {
        private static readonly int MAX = 1_000_000;

        public string GetAnswer()
        {
            var numberToDivisorSum = new Dictionary<int, int>(MAX);
            for (int i = 0; i < MAX; i++)
            {
                // 1 is divisor
                numberToDivisorSum[i + 1] = 1;
            }

            // i is a factor
            for (int i = 2; i <= MAX / 2; i++)
            {
                // excluding the number itself, so j starts from 2
                for (int j = 2; j <= MAX / 2; j++)
                {
                    if (i * j > MAX)
                    {
                        break;
                    }

                    numberToDivisorSum[i * j] += i;
                }
            }

            var numberToLength = new Dictionary<int, int>();
            for (int i = 1; i <= MAX; i++)
            {
                int length = GetChainLength(i, numberToDivisorSum);
                if (length != -1)
                {
                    numberToLength[i] = length;
                }
            }

            int longest = -1;
            foreach (var entry in numberToLength)
            {
                if (entry.Value > longest)
                {
                    longest = entry.Value;
                }
            }

            return numberToLength.Where(pair => pair.Value == longest)
                .OrderBy(pair => pair.Key).First().Key.ToString();
        }

        private static int GetChainLength(int number, Dictionary<int, int> numberToDivisorSum)
        {
            HashSet<int> chain = new HashSet<int>();
            int cur = number;
            while (true)
            {
                chain.Add(cur);
                int next = numberToDivisorSum[cur];
                if (next > MAX)
                {
                    return -1;
                }

                if (chain.Contains(next) && number != next)
                {
                    return -1;
                }

                if (next == number)
                {
                    return chain.Count;
                }

                cur = next;
            }
        }
    }
}
