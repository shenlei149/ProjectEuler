namespace ProjectEuler
{
    public class S112 : ISolution
    {
        public string GetAnswer()
        {
            int bouncyCount = 0;
            for (int i = 100; ; i++)
            {
                if (IsBouncy(i))
                {
                    bouncyCount++;
                }

                if (bouncyCount * 100 / i == 99)
                {
                    return i.ToString();
                }
            }
        }

        private static bool IsBouncy(int number)
        {
            bool increasing = false;
            bool decreasing = false;

            int second = number % 10;
            number /= 10;
            while (number != 0)
            {
                int first = number % 10;
                number /= 10;

                if (first < second)
                {
                    increasing = true;
                }
                else if (first > second)
                {
                    decreasing = true;
                }

                if (increasing && decreasing)
                {
                    return true;
                }

                second = first;
            }

            return false;
        }
    }
}
