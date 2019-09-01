using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S549 : ISolution
    {
        private static readonly int N = 100000000;

        public string GetAnswer()
        {
            var originPrimes = Utils.GenPrimes(N + 1);
            var primes = originPrimes.Where(l => l != 0).ToArray();

            var result = new long[N + 1];
            foreach (var p in primes)
            {
                result[p] = p;
            }

            for (int index = 0; primes[index] < N / 2; index++)
            {
                for (int j = 2; j < primes[index]; j++)
                {
                    var tmp = j * primes[index];
                    if (tmp > N)
                    {
                        break;
                    }
                    else
                    {
                        result[tmp] = primes[index];
                    }
                }
            }

            for (int index = 0; primes[index] < N / 6; index++)
            {
                for (int j = 2; j < primes[index] - 1; j++)
                {
                    long k = Math.Max(j + 1, primes[index] / j);
                    var test = j * k * primes[index];
                    if (test < 0 || test > N)
                    {
                        break;
                    }

                    for (; k < primes[index]; k++)
                    {
                        var tmp = j * k * primes[index];
                        if (tmp < 0 || tmp > N)
                        {
                            break;
                        }
                        else
                        {
                            result[tmp] = primes[index];
                        }
                    }

                }
            }

            for (int index = 0; primes[index] < N / 24; index++)
            {
                for (int j = 2; j < primes[index] - 2; j++)
                {
                    long k = Math.Max(j + 1, primes[index] / j);
                    var test = j * k * (k + 1) * primes[index];
                    if (test < 0 || test > N)
                    {
                        break;
                    }

                    for (; k < primes[index] - 1; k++)
                    {
                        long m = Math.Max(k + 1, primes[index] * primes[index] / (j * k));
                        var test2 = j * k * m * primes[index];
                        if (test2 < 0 || test2 > N)
                        {
                            break;
                        }

                        for (; m < primes[index]; m++)
                        {
                            var tmp = j * k * m * primes[index];
                            if (tmp < 0 || tmp > N)
                            {
                                break;
                            }
                            else
                            {
                                result[tmp] = primes[index];
                            }
                        }
                    }
                }
            }

            for (int i = 2; i <= N; i++)
            {
                if (result[i] == 0)
                {
                    var maps = Utils.Factorize(i, originPrimes);
                    long m = long.MinValue;
                    foreach (var map in maps)
                    {
                        var temp = GetMaxMByPrime(map);
                        if (temp > m)
                        {
                            m = temp;
                        }
                    }

                    result[i] = m;
                }
            }

            return result.Sum().ToString();
        }

        private static long GetMaxMByPrime(KeyValuePair<long, int> map)
        {
            long result = 0;
            long count = map.Value;
            while (count > 0)
            {
                result += map.Key;
                long cur = result;
                while (cur > 0)
                {
                    if (cur % map.Key == 0)
                    {
                        cur /= map.Key;
                        count--;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return result;
        }
    }
}
