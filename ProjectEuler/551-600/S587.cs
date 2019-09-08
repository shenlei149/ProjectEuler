using System;

namespace ProjectEuler
{
    public class S587 : ISolution
    {
        public string GetAnswer()
        {
            int n = 16;
            while (true)
            {
                double y = (n - Math.Sqrt(2 * n) + 1) / (n * n + 1);
                double x = y * n;
                double sTriangle = x * y / 2;
                double sTrapezoid = (y + 1) * (1 - x) / 2;
                double theta = Math.Atan((1 - x) / (1 - y));
                double sConcaveTriangle = sTriangle + sTrapezoid - theta / 2;
                double sL = 1 - Math.PI / 4;
                if (sL / sConcaveTriangle > 1000)
                {
                    break;
                }

                n++;
            }

            return n.ToString();
        }
    }
}
