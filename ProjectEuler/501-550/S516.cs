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

            List<List<List<long>>> tiers = new List<List<List<long>>>();
            var firstTier = candidates.Select(p => new List<long>() { p }).ToList();
            tiers.Add(firstTier);

            while (tiers.Last().Count != 0)
            {
                var lastTier = tiers.Last();
                var currentTier = new List<List<long>>();
                tiers.Add(currentTier);

                foreach (var combination in lastTier)
                {
                    double product = combination.Aggregate((total, next) => total * next);

                    int index = Array.BinarySearch(candidates, combination.Last());
                    for (int i = index + 1; i < candidates.Length; i++)
                    {
                        if (product * candidates[i] <= max)
                        {
                            currentTier.Add(new List<long>(combination)
                            {
                                candidates[i]
                            });
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }

            var factors = new List<long>();
            foreach (var tier in tiers)
            {
                foreach (var combination in tier)
                {
                    factors.Add(combination.Aggregate((total, next) => total * next));
                }
            }

            factors.Sort();

            foreach (var factor in factors)
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

            sum += smooths.Sum();

            return ((uint)sum).ToString();
        }
    }
}
