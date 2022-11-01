using System.Linq;

namespace ProjectEuler
{
    public class S121 : ISolution
    {
        public string GetAnswer()
        {
            int count = 15;
            var denominator = Enumerable.Range(2, count).Aggregate(1, (long i, int j) => i * j);
            long numerator = 0;
            var Reds = Enumerable.Range(1, count);
            for (int i = 1; i < (count + 1) / 2; i++)
            {
                var selection = Utils.Combination(Reds, i);
                numerator += selection.Sum(list => list.Aggregate(1L, (long p, int l) => p * l));
            }

            return (denominator / (numerator + 1)).ToString();
        }
    }
}
