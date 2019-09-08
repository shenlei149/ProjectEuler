namespace ProjectEuler
{
    public class S28 : ISolution
    {
        public string GetAnswer()
        {
            int sum = 0;
            for (int i = 1; i <= 500; i++)
            {
                sum += i * i * 16 + i * 4 + 4;
            }

            return (sum + 1).ToString();
        }
    }
}
