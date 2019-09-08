namespace ProjectEuler
{
    public class S301 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            long max = 1 << 30;
            for (long n = 1; n <= max; n++)
            {
                long n1 = n;
                long n2 = n << 1;
                long n3 = n1 + n2;
                if ((n1 ^ n2 ^ n3) == 0)
                {
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
