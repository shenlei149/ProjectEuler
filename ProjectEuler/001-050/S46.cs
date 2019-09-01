using System;

namespace ProjectEuler
{
    public class S46 : ISolution
    {
        public string GetAnswer()
        {
            for (int i = 35; ; i += 2)
            {
                if (!IsGoldbachNumber(i))
                {
                    return i.ToString();
                }
            }
        }

        private static bool IsGoldbachNumber(int number)
        {
            int length = (int)Math.Sqrt(number / 2) + 1;
            for (int i = 0; i < length; i++)
            {
                int tmp = number - i * i * 2;
                if (Utils.IsPrime(tmp))
                {
                    return true;
                }
            }

            return false;
        }
    }
}
