using System.Collections.Generic;
using System.Numerics;

namespace ProjectEuler
{
    public class S119 : ISolution
    {
        public string GetAnswer()
        {
            var candidates = new List<long>();
            for (int i = 2; i < 9 * long.MaxValue.ToString().Length; i++)
            {
                int power = 2;
                while (true)
                {
                    var ret = BigInteger.Pow(i, power);
                    if (ret > long.MaxValue)
                    {
                        break;
                    }

                    long number = (long)ret;
                    long sum = Utils.DigitSum(number);
                    if (sum == i)
                    {
                        candidates.Add(number);
                    }

                    power++;
                }
            }

            candidates.Sort();

            return candidates[29].ToString();
        }
    }
}
