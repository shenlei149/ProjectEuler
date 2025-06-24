using System;

namespace ProjectEuler
{
    public class S932 : ISolution
    {
        static readonly long RootUpper = 100_000_000 - 1;

        static readonly long[] POW = [ 1, 10, 100, 1_000, 10_000, 100_000,
                                       1_000_000, 10_000_000, 100_000_000 ];

        // 72673459417881349
        public string GetAnswer()
        {
            long sum = 0;
            for (long i = 4; i < RootUpper; i++)
            {
                long square = i * i;
                if (Is2005Number(i, square))
                {
                    sum += square;
                }
            }

            return sum.ToString();
        }

        private static bool Is2005Number(long root, long square)
        {
            string s = square.ToString();
            int length = s.Length % 2 == 0 ? 1 : 2;
            for (int i = s.Length / 2; i < s.Length / 2 + length; i++)
            {
                if (s[i] == '0')
                {
                    continue;
                }

                (long first, long second) = Math.DivRem(square, POW[s.Length - i]);

                if (first + second == root)
                {
                    return true;
                }
            }

            return false;
        }
    }
}
