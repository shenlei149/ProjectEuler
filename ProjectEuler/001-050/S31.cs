namespace ProjectEuler
{
    public class S31 : ISolution
    {
        private readonly int[] kindOfCoins = new int[] { 1, 2, 5, 10, 20, 50, 100, 200 };

        public string GetAnswer()
        {
            return CountCoins(200, kindOfCoins.Length - 1).ToString();
        }

        private int CountCoins(int amount, int index)
        {
            if (amount == 0)
            {
                return 1;
            }

            if (amount < 0 || index < 0)
            {
                return 0;
            }

            return CountCoins(amount, index - 1) + CountCoins(amount - kindOfCoins[index], index);
        }
    }
}
