using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectEuler
{
    public class S692 : ISolution
    {
        public string GetAnswer()
        {
            var nodes = new List<long> { 1, 2, 3, 5 };
            var diffs = new List<long> { 0, 1, 1, 2 };
            var sums = new List<long> { 1, 3, 6, 12 };
            for (int index = 2; ; index++)
            {
                var nextD = nodes[index];
                var nextN = nodes.Last() + nextD;
                diffs.Add(nextD);
                nodes.Add(nextN);
                sums.Add(sums[nodes.Count - 2] + sums[index] - nodes[index] + nextN);

                if (nextN == 23416728348467685)
                {
                    return sums.Last().ToString();
                }
            }
        }
    }
}
