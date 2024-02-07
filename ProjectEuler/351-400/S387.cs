using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S387 : ISolution
    {
        private static readonly long[] Digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
        private static readonly long[] PrimesLastDigits = [1, 3, 7, 9];

        public string GetAnswer()
        {
            var truncatableNumbers = new List<long>();

            List<long> last = [1, 2, 3, 4, 5, 6, 7, 8, 9];
            for (int i = 0; i < 12; i++)
            {
                List<long> cur = [];
                foreach (long l in last)
                {
                    foreach (long lastDigit in Digits)
                    {
                        long tmp = l * 10 + lastDigit;
                        int digitsSum = Utils.DigitSum(tmp);
                        if (tmp % digitsSum == 0)
                        {
                            cur.Add(tmp);
                        }
                    }
                }

                last = cur;
                truncatableNumbers.AddRange(last);
            }

            var strongTruncatableNumbers = truncatableNumbers.Where(l => Utils.IsPrime(l / Utils.DigitSum(l))).ToList();

            var strongTruncatablePrimes = new List<long>();
            foreach (var l in strongTruncatableNumbers)
            {
                foreach (var digit in PrimesLastDigits)
                {
                    long tmp = l * 10 + digit;
                    if (Utils.IsPrime(tmp))
                    {
                        strongTruncatablePrimes.Add(tmp);
                    }
                }
            }

            return strongTruncatablePrimes.Sum().ToString();
        }
    }
}
