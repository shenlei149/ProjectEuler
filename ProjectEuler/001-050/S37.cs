using System.Linq;

namespace ProjectEuler
{
    public class S37 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            int[] truncatablePrimes = new int[11];

            for (int i = 11; ; i += 2)
            {
                if (IsTruncatablePrimes(i))
                {
                    truncatablePrimes[count] = i;
                    count++;
                }

                if (count == 11)
                {
                    break;
                }
            }

            return truncatablePrimes.Sum().ToString();
        }

        private static bool IsTruncatablePrimes(int number)
        {
            if (!Utils.IsPrime(number))
            {
                return false;
            }
            else
            {
                int left = number / 10;
                while (left != 0)
                {
                    if (!Utils.IsPrime(left))
                    {
                        return false;
                    }

                    left /= 10;
                }

                string right = number.ToString();
                while (true)
                {
                    right = right.Substring(1);
                    if (right.Length == 0)
                    {
                        break;
                    }
                    if (!Utils.IsPrime(int.Parse(right)))
                    {
                        return false;
                    }
                }

                return true;
            }
        }
    }
}
