using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S56 : ISolution
    {
        public string GetAnswer()
        {
            int max = 0;
            for (int i = 1; i < 100; i++)
            {
                for (int j = 1; j < 100; j++)
                {
                    BigInteger product = BigInteger.Pow(i, j);
                    int sum = product.ToString().Sum(c => c - '0');
                    if (sum > max)
                    {
                        max = sum;
                    }
                }
            }

            return max.ToString();
        }
    }
}
