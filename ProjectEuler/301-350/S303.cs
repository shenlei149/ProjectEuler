using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S303 : ISolution
    {
        public string GetAnswer()
        {
            var numStr = new List<string>() { "1", "2" };
            var numStrs = new List<List<string>>() { numStr };
            GenerateNumStr(numStrs);

            var numbers = numStrs.SelectMany(numStr => numStr).Select(numStr => long.Parse(numStr)).ToList();

            var missingN = new List<long>();
            long sum = 0;
            for (int i = 1; i <=10000; i++)
            {
                long Fn = F(i, numbers, missingN);
                // Console.WriteLine(i+"\t"+Fn);
                sum+=Fn/i;
            }

            Console.WriteLine(missingN.Count);
            return sum.ToString();
        }

        private static long F(long n, List<long> numbers,List<long> missingN)
        {
            foreach (var l in numbers)
            {
                if (l%n==0)
                {
                    return l;
                }
            }

            //    12222
            //   1122222222
            //  111222222222222
            // 11112222222222222222
            missingN.Add(n);
            return 0;
        }

        private void GenerateNumStr(List<List<string>> numStrs)
        {
            var lastStr = numStrs.Last();
            if (lastStr.First().Length>12)
            {
                return;
            }

            var numStr = new List<string>();
            foreach (var str in lastStr)
            {
                numStr.Add(str+"0");
                numStr.Add(str+"1");
                numStr.Add(str+"2");
            }

            numStrs.Add(numStr);

            GenerateNumStr(numStrs);
        }
    }
}
