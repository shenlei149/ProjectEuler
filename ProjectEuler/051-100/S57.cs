using System.Numerics;

namespace ProjectEuler
{
    public class S57 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;

            BigInteger denominator = 1;
            BigInteger numerator = 1;
            for (int i = 0; i < 1000; i++)
            {
                BigInteger a = denominator;
                BigInteger b = numerator;
                denominator = a + b;
                numerator = 2 * a + b;
                if (numerator.ToString().Length > denominator.ToString().Length)
                {
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
