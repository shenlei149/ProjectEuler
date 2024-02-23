using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S684 : ISolution
    {
        private static readonly long Mod = 1000000007;

        public string GetAnswer()
        {
            var fibonacci = new List<long>();
            long f0 = 0;
            long f1 = 1;
            for (int i = 2; i <= 90; i++)
            {
                long f2 = f0 + f1;
                fibonacci.Add(f2);

                f0 = f1;
                f1 = f2;
            }

            long result = 0;
            foreach (var f in fibonacci)
            {
                result += S(f);
            }

            result %= Mod;

            return result.ToString();
        }

        private static long S(long f)
        {
            long L = f / 9;
            long r = f % 9;

            long remainder = GetRemainder(L);

            long first = (r * r + 3 * r) / 2 * remainder - r;
            long second = 6 * remainder - 6 - 9 * L % Mod;

            return (first + second) % Mod;
        }

        private static long GetRemainder(long l)
        {
            if (l < 10)
            {
                return (long)Math.Pow(10, l);
            }

            var r = l % 2;
            var half = GetRemainder(l / 2);
            half = (half * half) % Mod;
            if (r == 0)
            {
                return half;
            }
            else
            {
                return (half * 10) % Mod;
            }
        }
    }
}
