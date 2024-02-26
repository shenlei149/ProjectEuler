using System.Collections.Generic;

namespace ProjectEuler
{
    public class S205 : ISolution
    {
        private static readonly List<string> PeterResults = [];
        private static readonly List<string> ColinResults = [];

        public string GetAnswer()
        {
            int[] Peter = new int[37];
            int[] Colin = new int[37];

            GenPeterResults("", 0);
            PeterResults.ForEach(s => Peter[Utils.DigitSum(int.Parse(s))]++);

            GenColinResults("", 0);
            ColinResults.ForEach(s => Colin[Utils.DigitSum(int.Parse(s))]++);

            long numerator = 0;
            for (int p = 1; p < Peter.Length; p++)
            {
                for (int c = 1; c < Colin.Length; c++)
                {
                    if (p > c)
                    {
                        numerator += Peter[p] * Colin[c];
                    }
                }
            }

            return ((double)numerator / 262144 / 46656).ToString("F7");
        }

        private static void GenPeterResults(string num, int nth)
        {
            for (int i = 1; i <= 4; i++)
            {
                if (nth == 8)
                {
                    PeterResults.Add(num + i);
                }
                else
                {
                    GenPeterResults(num + i, nth + 1);
                }
            }
        }

        private static void GenColinResults(string num, int nth)
        {
            for (int i = 1; i <= 6; i++)
            {
                if (nth == 5)
                {
                    ColinResults.Add(num + i);
                }
                else
                {
                    GenColinResults(num + i, nth + 1);
                }
            }
        }
    }
}
