using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S88 : ISolution
    {
        private static readonly int Max = 12_000;

        public string GetAnswer()
        {
            return GenerateMinProductSumNumber().Distinct().Sum().ToString();
        }

        private static int[] GenerateMinProductSumNumber()
        {
            int[] ks = new int[Max + 1];
            ks[0] = 0;
            ks[1] = 0;
            for (int i = 2; i < ks.Length; i++)
            {
                ks[i] = int.MaxValue;
            }

            int[] digits = new int[15] { 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

            do
            {
                int product = digits.Aggregate(1, (a, b) => a * b);
                int sum = digits.Sum();
                int diff = product - sum;

                if (diff <= Max - 15 && diff >= -13 && ks[diff + 15] > product)
                {
                    ks[diff + 15] = product;
                }

                if (diff >= Max - 15)
                {
                    bool ok = Carry(digits);
                    if (!ok)
                    {
                        break;
                    }
                }
                else
                {
                    digits[0]++;
                }
            } while (true);

            return ks;
        }

        private static bool Carry(int[] digits)
        {
            for (int i = 0; i < digits.Length - 1; i++)
            {
                if (digits[i] != digits[i + 1])
                {
                    digits[i + 1]++;
                    for (int j = 0; j <= i; j++)
                    {
                        digits[j] = digits[i + 1];
                    }

                    return true;
                }
            }

            return false;
        }
    }
}
