using System;
using System.Collections.Generic;
using System.Text;

namespace ProjectEuler
{
    public class S100 : ISolution
    {
        public string GetAnswer()
        {
            double sqrt2 = Math.Sqrt(2);

            for (int i = 1; ; i++)
            {
                long x = (long)((Math.Pow(1 + sqrt2, 2 * i - 1) + Math.Pow(1 - sqrt2, 2 * i - 1)) / 2) + 1;
                long y = (long)((Math.Pow(1 + sqrt2, 2 * i - 1) - Math.Pow(1 - sqrt2, 2 * i - 1)) / 2 / sqrt2) + 1;

                if (x > 2000000000000)
                {
                    return ((y + 1) / 2).ToString();
                }
            }
        }
    }
}
