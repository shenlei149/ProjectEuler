namespace ProjectEuler
{
    public class S820 : ISolution
    {
        private static readonly int MAX = 10_000_000;

        public string GetAnswer()
        {
            long sum = 0;

            for (int k = 3; k <= MAX; k++)
            {
                sum += D(k);
            }

            return sum.ToString();
        }

        static int D(int k)
        {
            return PowerMod(10, MAX - 1, k) * 10 / k;
        }

        static int PowerMod(int baseValue, int exponent, int modulus)
        {
            long result = 1;
            long baseMod = baseValue % modulus;

            while (exponent > 0)
            {
                if ((exponent & 1) == 1)
                {
                    result = result * baseMod % modulus;
                }

                baseMod = baseMod * baseMod % modulus;
                exponent >>= 1;
            }

            return (int)result;
        }
    }
}