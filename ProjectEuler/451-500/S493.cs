using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S493 : ISolution
    {
        public string GetAnswer()
        {
            var combinationsCount = new long[11];
            for (int i = 0; i < 11; i++)
            {
                combinationsCount[i] = Utils.GetCombinationsCount(10, i);
            }

            BigInteger count = 0;
            for (int i = 0; i < 11; i++)
            {
                long ic = combinationsCount[i];
                int inc = i == 0 ? 0 : 1;

                for (int j = 0; j < 11 && i + j <= 20; j++)
                {
                    long jc = combinationsCount[j];
                    int jnc = j == 0 ? inc : inc + 1;

                    for (int k = 0; k < 11 && i + j + k <= 20; k++)
                    {
                        long kc = combinationsCount[k];
                        int knc = k == 0 ? jnc : jnc + 1;

                        for (int l = 0; l < 11 && i + j + k + l <= 20; l++)
                        {
                            long lc = combinationsCount[l];
                            int lnc = l == 0 ? knc : knc + 1;

                            for (int m = 0; m < 11 && i + j + k + l + m <= 20; m++)
                            {
                                long mc = combinationsCount[m];
                                int mnc = m == 0 ? lnc : lnc + 1;

                                for (int n = 0; n < 11 && i + j + k + l + m + n <= 20; n++)
                                {
                                    long nc = combinationsCount[n];
                                    int nnc = n == 0 ? mnc : mnc + 1;

                                    int q = 20 - i - j - k - l - m - n;
                                    if (q >= 0 && q <= 10)
                                    {
                                        long qc = combinationsCount[q];
                                        int qnc = q == 0 ? nnc : nnc + 1;

                                        long tmp = ic * jc * kc * lc * mc * nc * qc;

                                        count += qnc * tmp;
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
    }
}
