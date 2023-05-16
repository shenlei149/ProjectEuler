using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S808 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes2(100_000_000);
            var squares = primes.Select(l => l * l).ToArray();

            var rps = new List<long>();
            for (int i = 0; i < squares.Length / 2; i++)
            {
                var res = Utils.Reverse(squares[i]);

                var index = Array.BinarySearch(squares, res);
                if (index > i)
                {
                    rps.Add(squares[i]);
                    rps.Add(res);
                }
            }

            return rps.Sum().ToString();
        }
    }
}
