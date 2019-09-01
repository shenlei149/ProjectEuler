namespace ProjectEuler
{
    public class S71 : ISolution
    {
        public string GetAnswer()
        {
            double diff = 3.0 / 7;
            int numerator = 0;

            double basis = 3.0 / 7;
            for (int d = 10; d <= 1000000; d++)
            {
                int max = (int)(basis * d);
                while (Utils.GetGcd(max, d) != 1)
                {
                    max--;
                }

                double newDiff = basis - (double)max / d;
                if (newDiff < diff)
                {
                    diff = newDiff;
                    numerator = max;
                }
            }

            return numerator.ToString();
        }
    }
}
