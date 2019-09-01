using System;

namespace ProjectEuler
{
    public class S36 : ISolution
    {
        public string GetAnswer()
        {
            int sum = 0;
            for (int i = 1; i < 1000000; i++)
            {
                if (Utils.IsPalindrome(i.ToString()) && Utils.IsPalindrome(Convert.ToString(i, 2)))
                {
                    sum += i;
                }
            }

            return sum.ToString();
        }
    }
}
