using System.Collections.Generic;
using System.Linq;
using System.Numerics;

namespace ProjectEuler
{
    public class S323 : ISolution
    {
        public string GetAnswer()
        {
            List<Probability> probabilities =
            [
                new Probability(0, 1)
            ];

            BigInteger twoPow32 = BigInteger.Pow(2, 32);
            for (int i = 1; ; i++)
            {
                var baseDenominator = BigInteger.Pow(2, i);
                var baseNumerator = baseDenominator - 1;
                var lastBaseDenominator = BigInteger.Pow(2, i - 1);
                var lastBaseNumerator = lastBaseDenominator - 1;
                var denominator = BigInteger.Pow(baseDenominator, 32);
                var numerator = BigInteger.Pow(baseNumerator, 32);
                var lastNumerator = BigInteger.Pow(lastBaseNumerator, 32);
                probabilities.Add(new Probability(
                    numerator - lastNumerator * twoPow32,
                    denominator));

                if (probabilities[i].Denominator / probabilities[i].Numerator / i > BigInteger.Pow(10, 12))
                {
                    break;
                }
            }

            BigInteger ansDenominator = probabilities.Last().Denominator;
            BigInteger ansNumerator = 0;
            for (int i = 1; i < probabilities.Count; i++)
            {
                Probability current = probabilities[i];
                BigInteger times = ansDenominator / current.Denominator;
                ansNumerator += times * current.Numerator * i;
            }

            BigInteger times11 = ansNumerator * 100000000000 / ansDenominator;
            double answer = (double)times11 / 100000000000;

            return answer.ToString("N10");
        }

        private class Probability
        {
            public BigInteger Numerator { get; }
            public BigInteger Denominator { get; }

            public Probability(BigInteger numerator, BigInteger denominator)
            {
                Numerator = numerator;
                Denominator = denominator;
            }
        }
    }
}
