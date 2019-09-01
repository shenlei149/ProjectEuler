using System;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S55 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            for (int i = 1; i < 10000; i++)
            {
                if (IsLychrel(i))
                {
                    count++;
                }
            }

            return count.ToString();
        }

        private static bool IsLychrel(BigInteger number)
        {
            for (int i = 0; i < 50; i++)
            {
                number += BigInteger.Parse(new string(number.ToString().Reverse().ToArray()));
                if (Utils.IsPalindrome(number.ToString()))
                {
                    return false;
                }
            }

            return true;
        }
    }
}
