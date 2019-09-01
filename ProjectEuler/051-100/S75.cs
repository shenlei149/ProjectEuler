using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S75 : ISolution
    {
        private static readonly long L = 1500000;

        public string GetAnswer()
        {
            var triangles = new List<long>();
            for (long a = 1; a < L / 2; a += 2)
            {
                for (long b = a + 2; a * b < L / 2; b += 2)
                {
                    if (Utils.GetGcd(a, b) == 1)
                    {
                        for (long k = 1; k * a * b < L / 2; k++)
                        {
                            long x = k * a * b;
                            long y = k * (b * b - a * a) / 2;
                            long z = k * (b * b + a * a) / 2;
                            if (x + y + z <= L)
                            {
                                triangles.Add(x + y + z);
                            }
                        }
                    }
                }
            }

            var countMapping = new Dictionary<long, int>();

            foreach (var circumference in triangles)
            {
                if (countMapping.ContainsKey(circumference))
                {
                    countMapping[circumference]++;
                }
                else
                {
                    countMapping[circumference] = 1;
                }
            }

            return countMapping.Count(p => p.Value == 1).ToString();
        }
    }
}
