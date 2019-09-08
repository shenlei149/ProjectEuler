namespace ProjectEuler
{
    public class S120 : ISolution
    {
        public string GetAnswer()
        {
            int sum = 0;
            for (int a = 3; a <= 1000; a++)
            {
                sum += GetMaxRByA(a);
            }

            return sum.ToString();
        }

        private static int GetMaxRByA(int a)
        {
            return (a - 1) / 2 * 2 * a;
        }
    }
}
