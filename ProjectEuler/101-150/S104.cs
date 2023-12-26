using System;
using System.Numerics;

namespace ProjectEuler
{
    public class S104 : ISolution
    {
        public string GetAnswer()
        {
            int[] fn_2 = [1];
            int[] fn_1 = [1];
            BigInteger f1 = 1;
            BigInteger f2 = 1;
            int i = 3;
            while (true)
            {
                BigInteger fnBig = f1 + f2;
                int[] fn = Add(fn_1, fn_2);
                if (IsPandigitalFibonacci(fn))
                {
                    int digits = (int)Math.Floor(BigInteger.Log10(fnBig) + 1);
                    var dividend = BigInteger.Pow(10, digits - 9);
                    var firstNineDigits = fnBig / dividend;
                    if (Utils.IsPandigital(firstNineDigits.ToString(), false))
                    {
                        return i.ToString();
                    }
                }

                fn_2 = fn_1;
                fn_1 = fn;
                f2 = f1;
                f1 = fnBig;
                i++;
            }
        }

        private static bool IsPandigitalFibonacci(int[] fn)
        {
            int[] digitalCounts = new int[10];
            for (int i = 0; i < 9; i++)
            {
                digitalCounts[fn[i]]++;
            }

            for (int i = 1; i < 10; i++)
            {
                if (digitalCounts[i] != 1)
                {
                    return false;
                }
            }

            return true;
        }

        private static int[] Add(int[] fn_1, int[] fn_2)
        {
            int[] ret = new int[9];
            int n1 = fn_1.Length - 1;
            int n2 = fn_2.Length - 1;
            int nr = ret.Length - 1;
            int carry = 0;
            for (; nr >= 0; n1--, n2--, nr--)
            {
                int a = n1 >= 0 ? fn_1[n1] : 0;
                int b = n2 >= 0 ? fn_2[n2] : 0;
                int sum = a + b + carry;
                ret[nr] = sum % 10;
                carry = sum / 10;
            }

            return ret;
        }

    }
}
