using System;

namespace ProjectEuler
{
    public class S86 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            int a = 2;
            while (count < 1_000_000)
            {
                a++;
                count += GetCountByA(a);
            }

            return a.ToString();
        }

        int GetCountByA(int a)
        {
            int count = 0;
            for (int bc = 2; bc <= 2 * a; bc++)
            {
                int slope = (int)Math.Sqrt(a * a + bc * bc);
                if (a * a + bc * bc == slope * slope)
                {
                    int bStart = bc % 2 == 0 ? bc / 2 : bc / 2 + 1;
                    int bEnd = Math.Min(a, bc - 1);
                    count += bEnd - bStart + 1;
                }
            }

            return count;
        }
    }
}
