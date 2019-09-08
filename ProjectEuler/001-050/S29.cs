using System.Collections.Generic;
using System.Numerics;

namespace ProjectEuler
{
    public class S29 : ISolution
    {
        public string GetAnswer()
        {
            var results = new HashSet<BigInteger>();
            for (int i = 2; i <= 100; i++)
            {
                for (int j = 2; j <= 100; j++)
                {
                    results.Add(BigInteger.Pow(i, j));
                }
            }

            return results.Count.ToString();
        }
    }
}
