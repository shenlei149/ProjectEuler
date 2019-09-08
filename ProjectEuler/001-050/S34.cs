using System.Collections.Generic;

namespace ProjectEuler
{
    public class S34 : ISolution
    {
        private static readonly List<int> factorials = new List<int>
        {
            (int)Utils.Factorial(0),
            (int)Utils.Factorial(1),
            (int)Utils.Factorial(2),
            (int)Utils.Factorial(3),
            (int)Utils.Factorial(4),
            (int)Utils.Factorial(5),
            (int)Utils.Factorial(6),
            (int)Utils.Factorial(7),
            (int)Utils.Factorial(8),
            (int)Utils.Factorial(9),
        };

        public string GetAnswer()
        {
            int sum = 0;
            // 2540160 = 9! * 7
            for (int i = 3; i < 2540160; i++)
            {
                if (i == DigitFactorials(i))
                {
                    sum += i;
                }
            }

            return sum.ToString();
        }

        private static int DigitFactorials(int n)
        {
            int sum = 0;
            while (n != 0)
            {
                sum += factorials[n % 10];
                n /= 10;
            }

            return sum;
        }


    }
}
