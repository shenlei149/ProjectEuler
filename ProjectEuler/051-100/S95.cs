using System.Collections.Generic;

namespace ProjectEuler
{
    public class S95 : ISolution
    {
        private static readonly int MAX = 1_000_000;

        public string GetAnswer()
        {
            var numberToDivisorSum = new List<int>(MAX + 1);
            for (int i = 0; i <= MAX; i++)
            {
                // 1 is divisor
                numberToDivisorSum.Add(1);
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

            var numberToLength = new List<int>(MAX + 1) { 0 };
            int longest = -1;
            int index = -1;
            for (int i = 1; i <= MAX; i++)
            {
                numberToLength.Add(0);
                if (numberToDivisorSum[i] != -1)
                {
                    int length = GetChainLength(i, numberToDivisorSum);
                    numberToLength[i] = length;
                    if (length > longest)
                    {
                        index = i;
                        longest = length;
                    }
                }
            }

            return index.ToString();
        }

        private static int GetChainLength(int number, List<int> numberToDivisorSum)
        {
            var chain = new List<int>();
            int cur = number;
            while (true)
            {
                chain.Add(cur);
                int next = numberToDivisorSum[cur];
                if (next > MAX || next == -1)
                {
                    foreach (var s in chain)
                    {
                        if (s > number)
                        {
                            numberToDivisorSum[s] = -1;
                        }
                    }

                    return -1;
                }

                if (chain.Contains(next) && number != next)
                {
                    return -1;
                }

                if (next == number)
                {
                    foreach (var s in chain)
                    {
                        if (s > number)
                        {
                            numberToDivisorSum[s] = -1;
                        }
                    }

                    return chain.Count;
                }

                cur = next;
            }
        }
    }
}
