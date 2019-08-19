using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S65 : ISolution
    {
        public string GetAnswer()
        {
            BigInteger[] numerators = new BigInteger[101];
            BigInteger[] denominators = new BigInteger[101];

            numerators[1] = 2;
            numerators[2] = 3;
            denominators[1] = 1;
            denominators[2] = 1;

            for (int i = 3; i < 101; i++)
            {
                if (i % 3 == 0)
                {
                    numerators[i] = numerators[i - 1] * i * 2 / 3 + numerators[i - 2];
                    denominators[i] = denominators[i - 1] * i * 2 / 3 + denominators[i - 2];
                }
                else
                {
                    numerators[i] = numerators[i - 1] + numerators[i - 2];
                    denominators[i] = denominators[i - 1] + denominators[i - 2];
                }
            }

            return numerators[100].ToString().Select(c => c - '0').Sum().ToString();
        }
    }
}
