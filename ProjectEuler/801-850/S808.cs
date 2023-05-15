using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S808 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(100_000_000).Where(l => l != 0).ToArray();
            var squares = primes.Select(l => l * l).ToArray();

            var rps = new List<long>();
            for (int i = 0; i < squares.Length; i++)
            {
                var res = Utils.Reverse(squares[i]);
                if (res % 10 >= 5)
                { continue; }

                var index = Array.BinarySearch(squares, res);
                if (index > i)
                {
                    rps.Add(squares[i]);
                    rps.Add(res);
                }

                // if (squares[i] > 5_000_000_000_000_000)
                // { break; }
            }

            return rps.Sum().ToString();
        }
    }
}
