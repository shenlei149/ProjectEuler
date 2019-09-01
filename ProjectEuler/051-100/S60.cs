using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S60 : ISolution
    {
        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(8400).Where(l => l != 0).ToArray();
            var primesLength = primes.Length;

            bool[,] isConnected = new bool[primesLength, primesLength];

            List<Tuple<int, int>> two = new List<Tuple<int, int>>();
            for (int i = 0; i < primesLength - 1; i++)
            {
                for (int j = i + 1; j < primesLength; j++)
                {
                    var a = primes[i];
                    var b = primes[j];

                    if (Utils.IsPrime(int.Parse(a.ToString() + b.ToString())) && Utils.IsPrime(int.Parse(b.ToString() + a.ToString())))
                    {
                        isConnected[i, j] = true;
                        isConnected[j, i] = true;
                        two.Add(new Tuple<int, int>(i, j));
                    }
                }
            }

            List<Tuple<int, int, int>> three = new List<Tuple<int, int, int>>();
            foreach (var item in two)
            {
                for (int i = item.Item2 + 1; i < primesLength; i++)
                {
                    if (isConnected[i, item.Item1] && isConnected[i, item.Item2])
                    {
                        three.Add(new Tuple<int, int, int>(item.Item1, item.Item2, i));
                    }

                }
            }

            List<Tuple<int, int, int, int>> four = new List<Tuple<int, int, int, int>>();
            foreach (var item in three)
            {
                for (int i = item.Item3 + 1; i < primesLength; i++)
                {
                    if (isConnected[i, item.Item1] && isConnected[i, item.Item2] && isConnected[i, item.Item3])
                    {
                        four.Add(new Tuple<int, int, int, int>(item.Item1, item.Item2, item.Item3, i));
                    }
                }
            }

            List<Tuple<int, int, int, int, int>> five = new List<Tuple<int, int, int, int, int>>();
            foreach (var item in four)
            {
                for (int i = item.Item4; i < primesLength; i++)
                {
                    if (isConnected[i, item.Item1] && isConnected[i, item.Item2] && isConnected[i, item.Item3] && isConnected[i, item.Item4])
                    {
                        five.Add(new Tuple<int, int, int, int, int>(item.Item1, item.Item2, item.Item3, item.Item4, i));
                    }
                }
            }

            Tuple<int, int, int, int, int> index = five.First();
            return (primes[index.Item1] + primes[index.Item2] + primes[index.Item3] + primes[index.Item4] + primes[index.Item5]).ToString();
        }
    }
}
