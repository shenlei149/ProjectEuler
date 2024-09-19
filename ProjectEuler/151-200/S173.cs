namespace ProjectEuler
{
    public class S173 : ISolution
    {
        private static readonly int N = 1_000_000;
        // private static readonly int N = 100;

        public string GetAnswer()
        {
            int count = 0;
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
                        count++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return count.ToString();
        }
    }
}
