using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S118 : ISolution
    {
        private readonly List<List<int>> unique = new();
        private readonly int[] pow = { 1, 10, 100, 1_000, 10_000, 100_000, 1_000_000, 10_000_000, 100_000_000 };

        public string GetAnswer()
        {
            // length 1 to 9
            for (int i = 0; i < 10; i++)
            {
                unique.Add(new List<int>());
            }

            var primes = Utils.GenPrimes(10000).Where(p => p != 0).ToArray();

            for (int i = 1; i < 10; i += 2)
            {
                GenPrimes(i, 1, primes);
            }

            unique[1].Add(2);

            foreach (var p in unique)
            {
                p.Sort();
                p.Reverse();
            }

            int count = 0;
            for (int i = 8; i >= 2; i--)
            {
                var list = unique[i];
                foreach (var start in list)
                {
                    GenSets(new List<int>() { start }, i, i, ref count);
                }
            }

            return count.ToString();
        }

        private void GenSets(List<int> elements, int length, int lastLength, ref int count)
        {
            if (length == 9)
            {
                if (Utils.IsPandigital(elements))
                {
                    count++;
                }

                return;
            }

            if (!Utils.IsPandigital(elements))
            {
                return;
            }

            var remain = 9 - length;
            var begin = Math.Min(remain, lastLength);
            for (int i = begin; i >= 1; i--)
            {
                var list = unique[i];

                int start = 0;
                if (lastLength == i)
                {
                    start = list.IndexOf(elements.Last()) + 1;
                }

                for (int j = start; j < list.Count; j++)
                {
                    var n = list[j];

                    var newlist = new List<int>(elements.Count + 1);
                    newlist.AddRange(elements);
                    newlist.Add(n);
                    GenSets(newlist, length + i, i, ref count);
                }
            }
        }

        private void GenPrimes(int value, int length, long[] primes)
        {
            if (!Utils.IsPandigital(value))
                return;

            if (Utils.IsPrime(value, primes))
                unique[length].Add(value);

            if (length >= 8)
                return;

            for (int i = 1; i < 10; i++)
            {
                GenPrimes(value + i * pow[length], length + 1, primes);
            }
        }
    }
}
