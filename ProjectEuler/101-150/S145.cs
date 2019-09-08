namespace ProjectEuler
{
    public class S145 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            for (long i = 1; i < 1_000_000_000; i++)
            {
                if (IsReversibleNumbers(i))
                {
                    count++;
                }
            }

            return count.ToString();
        }

        private static bool IsReversibleNumbers(long number)
        {
            long last = number % 10;
            if (last == 0)
            {
                return false;
            }

            long reverseNumber = GetReverse(number);

            return HasNonEvenNumber(number + reverseNumber);
        }

        private static long GetReverse(long number)
        {
            long reverse = 0;
            while (number != 0)
            {
                reverse *= 10;
                reverse += number % 10;
                number /= 10;
            }

            return reverse;
        }

        private static bool HasNonEvenNumber(long number)
        {
            while (number != 0)
            {
                var d = number % 10;
                if (d % 2 == 0)
                {
                    return false;
                }

                number /= 10;
            }

            return true;
        }
    }
}
