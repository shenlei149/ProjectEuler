using System.Collections.Generic;

namespace ProjectEuler
{
    public class S109 : ISolution
    {
        private readonly int MAX = 100;

        struct Throw
        {
            public int Score;
            public int Multiplier;

            public Throw(int score, int multiplier)
            {
                Score = score;
                Multiplier = multiplier;
            }
        }

        private readonly List<Throw> Throws = [];

        public string GetAnswer()
        {
            int count = 0;

            // initialize possible throws
            for (int i = 1; i <= 20; i++)
            {
                Throws.Add(new Throw(i, 1));
                Throws.Add(new Throw(i, 2));
                Throws.Add(new Throw(i, 3));
            }
            Throws.Add(new Throw(25, 1));
            Throws.Add(new Throw(25, 2));

            Throws.Sort((a, b) => a.Score * a.Multiplier - b.Score * b.Multiplier);

            for (int target = 2; target < MAX; target++)
            { Search(Throws, target, 0, 3, ref count); }

            return count.ToString();
        }

        private static void Search(List<Throw> throws, int target, int startIndex, int maxThrows, ref int count)
        {
            if (maxThrows == 0) { return; }

            // try to finish
            if (target % 2 == 0 && (target / 2 == 25 || (target / 2 <= 20)))
            {
                count++;
            }

            // try to continue
            for (int i = startIndex; i < throws.Count; i++)
            {
                var t = throws[i];
                int score = t.Score * t.Multiplier;

                if (score < target)
                {
                    Search(throws, target - score, i, maxThrows - 1, ref count);
                }
                else
                {
                    break;
                }
            }
        }
    }
}
