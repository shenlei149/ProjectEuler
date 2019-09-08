using System;

namespace ProjectEuler
{
    public class S85 : ISolution
    {
        private static readonly int N = 2000000;

        public string GetAnswer()
        {
            int gridCount = 0;
            int length = 0;
            int width = 0;

            for (int i = 1; i < 1500; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    int newGridCount = i * (i + 1) * j * (j + 1) / 4;
                    if (Math.Abs(newGridCount - N) < Math.Abs(gridCount - N))
                    {
                        gridCount = newGridCount;
                        length = i;
                        width = j;
                    }
                }
            }

            return (length * width).ToString();
        }
    }
}
