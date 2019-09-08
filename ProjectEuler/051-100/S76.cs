namespace ProjectEuler
{
    public class S76 : ISolution
    {
        private static int count = 0;

        public string GetAnswer()
        {
            CountingSummations(100, 100);
            return (count - 1).ToString(); // exclude 100
        }

        private static void CountingSummations(int p, int lastAddend)
        {
            if (p == 0)
            {
                count++;
            }

            for (int i = 1; i <= lastAddend && i <= p; i++)
            {
                CountingSummations(p - i, i);
            }
        }
    }
}
