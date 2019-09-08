using System.Collections.Generic;

namespace ProjectEuler
{
    public class S26 : ISolution
    {
        public string GetAnswer()
        {
            int max = 0;
            int value = 1;
            for (int i = 2; i < 1000; i++)
            {
                int tmp = GetRecurringCycle(1, i);
                if (tmp > max)
                {
                    max = tmp;
                    value = i;
                }
            }

            return value.ToString();
        }

        // n/m
        private static int GetRecurringCycle(int n, int m)
        {
            List<int> dividends = new List<int>();

            while (true)
            {
                while (n < m)
                {
                    n *= 10;
                }

                // search pattern.
                int index = dividends.IndexOf(n);
                if (index >= 0)
                {
                    return dividends.Count - index;
                }

                dividends.Add(n);
                n %= m;

                // n is divisible by m.
                if (n == 0)
                {
                    return 0;
                }
            }
        }
    }
}
