using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S346 : ISolution
    {
        public string GetAnswer()
        {
            var repunits = new List<long>();
            var MAX = 1_000_000_000_000;

            int b = 2;
            while (true)
            {
                int n = 3; // count of 1
                while (true)
                {
                    long sum = (long)((Utils.Pow(b, n) - 1) / (b - 1));
                    if (sum >= MAX)
                    {
                        break;
                    }

                    repunits.Add(sum);
                    n++;
                }

                if (n == 3)
                {
                    break;
                }

                b++;
            }

            return (repunits.Distinct().Sum() + 1).ToString();
        }
    }
}
