namespace ProjectEuler
{
    public class S745 : ISolution
    {
        private static readonly long N = 100_000_000_000_000;
        private static readonly int NSqrt = 10_000_000;
        private static readonly int Mod = 1_000_000_007;

        public string GetAnswer()
        {
            var counts = new long[NSqrt + 1];
            for (long i = counts.Length - 1; i >= 2; i--)
            {
                long count = N / (i * i);
                for (long j = i * 2; j < counts.Length; j += i)
                {
                    count -= counts[j];
                }

                counts[i] = count;
            }

            long sum = N;
            for (int i = 2; i < counts.Length; i++)
            {
                sum -= counts[i];
            }

            // so far, sum is the number of g(n)=1

            sum %= Mod;

            for (long i = 2; i < counts.Length; i++)
            {
                sum += counts[i] * i * i;
                sum %= Mod;
            }

            return sum.ToString();
        }
    }
}
