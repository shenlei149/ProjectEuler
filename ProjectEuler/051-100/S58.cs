using System.Linq;

namespace ProjectEuler
{
    public class S58 : ISolution
    {
        public string GetAnswer()
        {
            int total = 1;
            int primeCount = 0;
            int[] newNumbers = new int[4];
            for (int k = 1; ; k++)
            {
                newNumbers[0] = 4 * k * k - 2 * k + 1;
                newNumbers[1] = 4 * k * k + 4 * k + 1;
                newNumbers[2] = 4 * k * k + 2 * k + 1;
                newNumbers[3] = 4 * k * k + 1;

                total += 4;
                primeCount += newNumbers.Count(i => Utils.IsPrime(i));

                if (primeCount * 10 < total)
                {
                    return (2 * k + 1).ToString();
                }
            }
        }
    }
}
