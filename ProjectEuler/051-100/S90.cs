using System.Linq;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S90 : ISolution
    {
        private static readonly int[] squares = [1, 4, 9, 16, 25, 36, 49, 64, 81];

        public string GetAnswer()
        {
            int count = 0;
            var dice = Utils.Combination(new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 6);
            foreach (List<int> d1 in dice)
            {
                foreach (List<int> d2 in dice)
                {
                    if (CanBeDisplayed(d1, d2))
                    {
                        count++;
                    }
                }
            }

            return (count / 2).ToString();
        }

        private static bool CanBeDisplayed(List<int> d1, List<int> d2)
        {
            if (!d1.Contains(0) && !d2.Contains(0))
            { return false; }
            if (!d1.Contains(1) && !d2.Contains(1))
            { return false; }
            if (!d1.Contains(2) && !d2.Contains(2))
            { return false; }
            if (!d1.Contains(3) && !d2.Contains(3))
            { return false; }
            if (!d1.Contains(4) && !d2.Contains(4))
            { return false; }
            if (!d1.Contains(5) && !d2.Contains(5))
            { return false; }
            if (!d1.Contains(8) && !d2.Contains(8))
            { return false; }

            var newd1 = new List<int>(d1);
            var newd2 = new List<int>(d2);
            Extend(newd1);
            Extend(newd2);
            var numbers = new List<int>();
            foreach (var first in newd1)
            {
                foreach (var second in newd2)
                {
                    numbers.Add(first * 10 + second);
                    numbers.Add(second * 10 + first);
                }
            }

            return numbers.Intersect(squares).Count() == 9;
        }

        private static void Extend(List<int> dice)
        {
            if (dice.Contains(6) || dice.Contains(9))
            {
                dice.Add(6);
                dice.Add(9);
            }
        }
    }
}
