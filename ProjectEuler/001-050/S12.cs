using System;
using System.Collections.Generic;
using System.Text;

namespace ProjectEuler
{
    public class S12 : ISolution
    {
        public string GetAnswer()
        {
            int triangle = 0;
            int i = 1;
            while (true)
            {
                triangle += i;
                if (GetDivisorsCount(triangle) > 500)
                {
                    break;
                }

                i++;
            }

            return triangle.ToString();
        }

        int GetDivisorsCount(int number)
        {
            int count = 0;
            int sqrt = (int)Math.Sqrt(number);
            for (int i = 1; i <= sqrt; i++)
            {
                if (number % i == 0)
                {
                    count++;
                }
            }

            if (sqrt * sqrt == number)
            {
                // perfect square
                return count * 2 - 1;
            }
            else
            {
                return count * 2;
            }
        }
    }
}
