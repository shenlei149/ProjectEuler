using System;

namespace ProjectEuler
{
    public class S30 : ISolution
    {
        public string GetAnswer()
        {
            int sum = 0;
            for (int i = 2; i < 999999; i++)
            {
                if (IsPowerNumber(i, 5))
                {
                    sum += i;
                }
            }

            return sum.ToString();
        }

        private static bool IsPowerNumber(int number, int power)
        {
            int originalNumber = number;
            int powerSum = 0;
            while (number != 0)
            {
                powerSum += (int)Math.Pow(number % 10, power);
                number /= 10;
            }

            return powerSum == originalNumber;
        }
    }
}
