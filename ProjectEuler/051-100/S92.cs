using System.Linq;

namespace ProjectEuler
{
    public class S92 : ISolution
    {
        public string GetAnswer()
        {
            bool[] cache = new bool[600];

            int count = 0;
            int i = 2;
            for (; i < 600; i++)
            {
                int tmp = i;
                while (tmp != 89 && tmp != 1)
                {
                    tmp = tmp.ToString().Select(c => c - '0').Select(j => j * j).Sum();
                }

                if (tmp == 89)
                {
                    count++;
                    cache[i] = true;
                }
            }

            var squareSumCache = Enumerable.Range(0, 10000)
                .Select(n => n.ToString().Select(c => c - '0').Select(j => j * j).Sum())
                .ToList();

            for (; i < 10000000; i++)
            {
                int tmp = i;
                var squareSum = 0;
                while (tmp != 0)
                {
                    var d = tmp % 10000;
                    squareSum += squareSumCache[d];
                    tmp /= 10000;
                }

                if (cache[squareSum])
                {
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
