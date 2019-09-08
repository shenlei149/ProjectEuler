namespace ProjectEuler
{
    public class S39 : ISolution
    {
        public string GetAnswer()
        {
            int maxValue = 0;
            int maxCount = 0;
            for (int i = 3; i <= 1000; i++)
            {
                int count = GetSolutionCount(i);
                if (count > maxCount)
                {
                    maxCount = count;
                    maxValue = i;
                }
            }

            return maxValue.ToString();
        }

        private static int GetSolutionCount(int p)
        {
            int count = 0;
            for (int a = 1; a <= p / 3; a++)
            {
                for (int b = a; b <= p / 2; b++)
                {
                    int c = p - a - b;
                    if (c >= b && a + b > c && a * a + b * b == c * c)
                    {
                        count++;
                    }
                }
            }

            return count;
        }
    }
}
