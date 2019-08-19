using System;
using System.Numerics;

namespace ProjectEuler
{
    public class S80 : ISolution
    {
        public string GetAnswer()
        {
            int sum = 0;
            for (int i = 2; i < 100; i++)
            {
                int sqrt = (int)Math.Sqrt(i);
                if (sqrt * sqrt == i)
                {
                    continue;
                }

                sum += SqrtDigitSum(i);
            }

            return sum.ToString();
        }

        private static int SqrtDigitSum(int n)
        {
            int result = 0;
            int integerPart = (int)Math.Sqrt(n);
            result += integerPart;

            BigInteger a = new BigInteger(integerPart);
            BigInteger remainder = new BigInteger(n - integerPart * integerPart);
            for (int i = 0; i < 99; i++)
            {
                remainder *= 100;
                int b = 1;
                while ((a * 20 + b) * b < remainder)
                {
                    b++;
                }

                b--;

                remainder -= (a * 20 + b) * b;
                a = a * 10 + b;
                result += b;
            }

            return result;
        }
    }
}
