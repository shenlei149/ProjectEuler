namespace ProjectEuler
{
    public class S72 : ISolution
    {
        public string GetAnswer()
        {
            long count = 0;

            for (int d = 2; d <= 1000000; d++)
            {
                count += Utils.GetCoprimeCount(d);
            }

            return count.ToString();
        }
    }
}
