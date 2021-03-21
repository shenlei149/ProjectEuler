using System;

namespace ProjectEuler
{
    public class S94 : ISolution
    {
        public string GetAnswer()
        {
            long perimeters = 0;
            for (long a = 3; a <= 333_333_333; a += 2)
            {
                long c = a + 1;
                if (Meet(a, c))
                {
                    perimeters += 2 * a + c;
                    continue;
                }

                c = a - 1;
                if (Meet(a, c))
                {
                    perimeters += 2 * a + c;
                }
            }

            return perimeters.ToString();
        }

        private static bool Meet(long a, long c)
        {
            long half = c >> 1;
            long hsquare = half * half;
            long asquare = a * a;
            long height = (long)Math.Sqrt(asquare - hsquare);
            long htsquare = height * height;
            return asquare == htsquare + hsquare;
        }
    }
}
