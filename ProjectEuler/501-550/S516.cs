using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S516 : ISolution
    {
        public string GetAnswer()
        {
            long sum = 0;
            long max = 1000000000000;

            var smooths = new List<long>();
            for (int i = 0; i < Math.Log(max) / Math.Log(2); i++)
            {
                for (int j = 0; j < Math.Log(max) / Math.Log(3); j++)
                {
                    for (int k = 0; k < Math.Log(max) / Math.Log(5); k++)
                    {
                        if (Math.Pow(2, i) * Math.Pow(3, j) * Math.Pow(5, k) <= max)
                        {
                            smooths.Add((long)(Math.Pow(2, i) * Math.Pow(3, j) * Math.Pow(5, k)));
                        }
                    }
                }
            }

            smooths.Sort();

            var candidates =
                smooths
                .Select(l => l + 1)
                .Where(Utils.IsPrime)
                .Where(p => p > 5)
                .ToArray();

            foreach (var factor in candidates)
            {
                foreach (var smooth in smooths)
                {
                    if ((double)smooth * factor <= max)
                    {
                        sum += smooth * factor;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            var curTier = candidates.Select(p => new Tuple<long, long>(p, p)).ToList();

            while (curTier.Count != 0)
            {
                var nextTier = new List<Tuple<long, long>>();

                foreach (var combination in curTier)
                {
                    double product = combination.Item2;

                    int index = Array.BinarySearch(candidates, combination.Item1);
                    for (int i = index + 1; i < candidates.Length; i++)
                    {
                        if (product * candidates[i] <= max)
                        {
                            long factor = (long)product * candidates[i];
                            nextTier.Add(new Tuple<long, long>(candidates[i], factor));

                            foreach (var smooth in smooths)
                            {
                                if ((double)smooth * factor <= max)
                                {
                                    sum += smooth * factor;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                curTier = nextTier;
            }

            sum += smooths.Sum();

            return ((uint)sum).ToString();
        }
    }
}
