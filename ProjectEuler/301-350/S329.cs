using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectEuler
{
    public class S329 : ISolution
    {
        private static readonly int[] primes =
            Utils.GenPrimes(501).Select(l => (int)l).ToArray();
        private static readonly string croaks = "PPPPNNPPPNPPNPN";

        public string GetAnswer()
        {
            // numerator, denominator
            var probabilities = new List<(long, long)>();
            for (int i = 1; i <= 500; i++)
            {
                probabilities.AddRange(GetProbabilityAt(i));
            }

            var commonD = (long)Math.Pow(6, 15);
            long numerator = 0;
            foreach (var pair in probabilities)
            {
                numerator += pair.Item1 * commonD / pair.Item2;
            }

            commonD *= 500;
            var gcd = Utils.GetGcd(numerator, commonD);

            return $"{numerator / gcd}/{commonD / gcd}";
        }

        private List<(long, long)> GetProbabilityAt(int i)
        {
            var result = new List<(long, long)>();
            GetProbabilityAt(i, 0, 1, 1, result);
            return result;
        }

        private void GetProbabilityAt(int i, int step, long numerator, long denominator, List<(long, long)> result)
        {
            if (step == croaks.Length)
            {
                result.Add((numerator, denominator));
                return;
            }

            var (n, d) = GetProbabilityWithCroak(i, croaks[step]);
            numerator *= n;
            denominator *= d;

            step++;

            if (i == 1)
            {
                GetProbabilityAt(i + 1, step, numerator, denominator, result);
                return;
            }

            if (i == 500)
            {
                GetProbabilityAt(i - 1, step, numerator, denominator, result);
                return;
            }

            GetProbabilityAt(i + 1, step, numerator, denominator * 2, result);
            GetProbabilityAt(i - 1, step, numerator, denominator * 2, result);
        }

        private static (long, long) GetProbabilityWithCroak(int i, char p)
        {
            if (p == 'P')
            {
                if (primes[i] != 0)
                {
                    return (2, 3);
                }
                else
                {
                    return (1, 3);
                }
            }
            else
            {
                if (primes[i] != 0)
                {
                    return (1, 3);
                }
                else
                {
                    return (2, 3);
                }
            }
        }
    }
}
