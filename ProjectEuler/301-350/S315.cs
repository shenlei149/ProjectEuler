using System.Linq;

namespace ProjectEuler
{
    public class S315 : ISolution
    {
        private static readonly int[,] Overlap = new int[10, 10]
        {
            { 6,2,4,4,3,4,5,4,6,5},
            { 2,2,1,2,2,1,1,2,2,2},
            { 4,1,5,4,2,3,4,2,5,4},
            { 4,2,4,5,3,4,4,3,5,5},
            { 3,2,2,3,4,3,3,3,4,4},
            { 4,1,3,4,3,5,5,3,5,5},
            { 5,1,4,4,3,5,6,3,6,5},
            { 4,2,2,3,3,3,3,4,4,4},
            { 6,2,5,5,4,5,6,4,7,6},
            { 5,2,4,5,4,5,5,4,6,6},
        };

        public string GetAnswer()
        {
            int count = 0;
            const int MAX = 20000000;
            var primes = Utils.GenPrimes(MAX).Where(p => p > MAX / 2).ToArray();

            foreach (var p in primes)
            {
                if (p != 0)
                {
                    count += GetCount((int)p);
                }
            }

            return count.ToString();
        }

        private static int GetCount(int p)
        {
            int count = 0;
            while (p >= 10)
            {
                int sum = Utils.DigitSum(p);
                count += GetCount(p, sum);
                p = sum;
            }

            return count * 2;
        }

        private static int GetCount(int num1, int num2)
        {
            int count = 0;

            while (num1 > 0 && num2 > 0)
            {
                count += Overlap[num1 % 10, num2 % 10];
                num1 /= 10;
                num2 /= 10;
            }

            return count;
        }
    }
}
