using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S51 : ISolution
    {
        private static readonly string[] patterns = new string[] { "110001", "101001", "100101", "100011", "011001", "010101", "010011", "001011", "000111" };

        public string GetAnswer()
        {
            var primes = Utils.GenPrimes(1000000).Where(l => l > 100000).Select(l => (int)l).ToArray();
            primes = primes.Where(l => { string ls = l.ToString(); return ls.Contains('0') || ls.Contains('1') || ls.Contains('2'); }).ToArray();
            primes = primes.Where(l =>
            {
                for (int i = 0; i < patterns.Length; i++)
                {
                    string pattern = patterns[i];
                    List<char> chars = new List<char>();
                    for (int j = 0; j < pattern.Length; j++)
                    {
                        if (pattern[j] == '0')
                        {
                            chars.Add(l.ToString()[j]);
                        }
                    }

                    if (chars.Distinct().Count() == 1)
                    {
                        return true;
                    }
                }

                return false;
            }).ToArray();


            int length = primes.Length;
            bool[,] graph = new bool[length, length];
            HashSet<int> ddd = new HashSet<int> { 0 };
            for (int i = 0; i < length - 1; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    ddd.Clear();
                    ddd.Add(0);
                    int key = primes[i];
                    int comparison = primes[j];
                    for (int k = 0; k < 6; k++) // six figures
                    {
                        int diff = key % 10 - comparison % 10;
                        ddd.Add(diff);
                        key /= 10;
                        comparison /= 10;
                    }

                    if (ddd.Count == 2)
                    {
                        graph[i, j] = graph[j, i] = true;
                    }
                }
            }

            List<int[]> two = new List<int[]>();
            for (int i = 0; i < length - 1; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (graph[i, j])
                    {
                        two.Add(new int[2] { i, j });
                    }
                }
            }

            List<int[]> four = new List<int[]>();
            for (int i = 0; i < two.Count - 1; i++)
            {
                for (int j = i + 1; j < two.Count; j++)
                {
                    var tmp1 = two[i];
                    var tmp2 = two[j];
                    if (graph[tmp1[0], tmp2[0]] && graph[tmp1[1], tmp2[0]] &&
                        graph[tmp1[0], tmp2[1]] && graph[tmp1[1], tmp2[1]])
                    {
                        var list = new int[] { tmp1[0], tmp2[0], tmp1[1], tmp2[1] };
                        Array.Sort(list);

                        four.Add(list);
                    }
                }
            }
            four = four.Distinct(new IntArrayComparer()).ToList();

            List<int[]> eight = new List<int[]>();
            for (int i = 0; i < four.Count - 1; i++)
            {
                for (int j = i + 1; j < four.Count; j++)
                {
                    var tmp1 = four[i];
                    var tmp2 = four[j];
                    if (graph[tmp1[0], tmp2[0]] && graph[tmp1[1], tmp2[0]] && graph[tmp1[2], tmp2[0]] && graph[tmp1[3], tmp2[0]] &&
                        graph[tmp1[0], tmp2[1]] && graph[tmp1[1], tmp2[1]] && graph[tmp1[2], tmp2[1]] && graph[tmp1[3], tmp2[1]] &&
                        graph[tmp1[0], tmp2[2]] && graph[tmp1[1], tmp2[2]] && graph[tmp1[2], tmp2[2]] && graph[tmp1[3], tmp2[2]] &&
                        graph[tmp1[0], tmp2[3]] && graph[tmp1[1], tmp2[3]] && graph[tmp1[2], tmp2[3]] && graph[tmp1[3], tmp2[3]])
                    {
                        var list = tmp1.Concat(tmp2).ToArray();
                        Array.Sort(list);
                        eight.Add(list);
                    }
                }
            }
            eight = eight.Distinct(new IntArrayComparer()).ToList();

            return primes[eight.First()[0]].ToString();
        }

        private class IntArrayComparer : IEqualityComparer<int[]>
        {
            public bool Equals(int[] x, int[] y)
            {
                if (x.Length != y.Length)
                {
                    return false;
                }

                for (int i = 0; i < x.Length; i++)
                {
                    if (x[i] != y[i])
                    {
                        return false;
                    }
                }

                return true;
            }

            public int GetHashCode(int[] obj)
            {
                int result = 0;
                for (int i = 0; i < obj.Length; i++)
                {
                    result ^= obj[i].GetHashCode();
                }

                return result;
            }
        }
    }
}
