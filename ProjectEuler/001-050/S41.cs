using System.Collections.Generic;

namespace ProjectEuler
{
    public class S41 : ISolution
    {
        public string GetAnswer()
        {
            int max = 0;
            // sum(1..8)=36, 36%3=0
            // sum(1..9)=45, 45%3=0
            // so the number contians (1..8) or (1..9) MUST not be prime.
            for (int i = 1; i < 8; i++)
            {
                List<int> numbers = new List<int>();
                for (int j = 1; j <= i; j++)
                {
                    numbers.Add(j);
                }

                var per = numbers.Permutations();

                foreach (var item in per)
                {
                    int number = 0;
                    foreach (var d in item)
                    {
                        number *= 10;
                        number += d;
                    }

                    if (number > max && Utils.IsPrime(number))
                    {
                        max = number;
                    }
                }
            }

            return max.ToString();
        }
    }
}
