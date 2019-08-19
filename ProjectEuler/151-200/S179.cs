using System;
using System.Collections.Generic;
using System.Text;

namespace ProjectEuler
{
    public class S179 : ISolution
    {
        private static readonly int N = 10_000_000;

        public string GetAnswer()
        {
            int[] numberOfDivisors = new int[N + 1];
            for (int i = 1; i <= N; i++)
            {
                for (int j = i; j <= N; j += i)
                {
                    numberOfDivisors[j]++;
                }
            }

            int count = 0;
            for (int i = 2; i < N; i++)
            {
                if (numberOfDivisors[i] == numberOfDivisors[i + 1])
                {
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
