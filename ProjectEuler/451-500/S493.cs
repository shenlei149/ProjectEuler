using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S493 : ISolution
    {
        public string GetAnswer()
        {
            BigInteger count = 0;
            for (int i = 0; i < 11; i++)
            {
                for (int j = 0; i < 11 && i + j <= 20; j++)
                {
                    for (int k = 0; k < 11 && i + j + k <= 20; k++)
                    {
                        for (int l = 0; l < 11 && i + j + k + l <= 20; l++)
                        {
                            for (int m = 0; m < 11 && i + j + k + l + m <= 20; m++)
                            {
                                for (int n = 0; n < 11 && i + j + k + l + m + n <= 20; n++)
                                {
                                    int q = 20 - i - j - k - l - m - n;
                                    if (q >= 0 && q <= 10)
                                    {
                                        var counts = new List<int> { i, j, k, l, m, n, q };
                                        long tmp = 1;
                                        foreach (var c in counts)
                                        {
                                            tmp *= Utils.GetCombinationsCount(10, c);
                                        }

                                        count += GetColors(counts) * tmp;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 1; i <= 20; i++)
            {
                count *= i;
            }

            double dc = (double)count;
            for (int i = 51; i <= 70; i++)
            {
                dc /= i;
            }

            return dc.ToString("F9");
        }

        private static int GetColors(List<int> counts)
        {
            return counts.Count(i => i != 0);
        }
    }
}
