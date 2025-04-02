
using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S757 : ISolution
    {
        private static readonly long MAX = 100_000_000_000_000;
        private static readonly HashSet<long> StealthyNumbers = [];

        public string GetAnswer()
        {
            for (long delta = 1; delta < (long)Math.Pow(MAX, 1.0 / 3.0) + 1; delta++)
            {
                TryDelta(delta);
            }

            return StealthyNumbers.Count.ToString();
        }

        private static void TryDelta(long delta)
        {
            var n = GetMaxN(delta);
            if (n * (n + 1) * delta * (delta + 1) > MAX)
            {
                n--;
            }

            if (n < delta) // ensure c\leq d
            {
                return;
            }

            for (long m = delta; m <= n; m++)
            {
                long a = m * delta;
                long b = (m + 1) * (delta + 1);
                StealthyNumbers.Add(a * b);
            }
        }

        private static long GetMaxN(long delta)
        {
            return (long)Math.Sqrt(MAX / (delta * (delta + 1)));
        }
    }
}
