namespace ProjectEuler
{
    public class S301 : ISolution
    {
        public string GetAnswer()
        {
            int[] zero_count = new int[30];
            int[] one_count = new int[30];
            zero_count[0] = 1;
            one_count[0] = 1;
            for (int i = 1; i < 30; i++)
            {
                zero_count[i] = zero_count[i - 1] + one_count[i - 1];
                one_count[i] = zero_count[i - 1];
            }

            return (zero_count[29] + one_count[29]).ToString();
        }
    }
}
