namespace ProjectEuler
{
    public class S174 : ISolution
    {
        private const int N = 1_000_000;

        public string GetAnswer()
        {
            int[] counts = new int[N + 1];
            for (int i = 0; i < counts.Length; i++)
            {
                counts[i] = 0;
            }

            for (int hole = 1; hole < N / 4; hole++)
            {
                int min_length = hole + 1;

                for (int max_length = min_length; ; max_length += 2)
                {
                    int a_1 = min_length;
                    int a_n = max_length;
                    int n = (a_n - a_1) / 2 + 1;
                    int total = (a_1 + a_n) * n / 2 * 4;
                    if (total <= N)
                    {
                        counts[total]++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            int sum = 0;
            for (int j = 0; j < counts.Length; j++)
            {
                if (counts[j] <= 10 && counts[j] >= 1)
                {
                    sum++;
                }
            }

            return sum.ToString();
        }
    }
}
