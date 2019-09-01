using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectEuler
{
    public class S504 : ISolution
    {
        private static readonly int M = 100;
        private static readonly int[,] NumbersOfInsideVector = new int[M + 1, M + 1];

        public string GetAnswer()
        {
            var squares = Enumerable.Range(1, 140).Select(n => n * n).ToList();

            for (int i = 1; i <= M; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    int result = GetInsideVector(i, j);
                    NumbersOfInsideVector[i, j] = result;
                    NumbersOfInsideVector[j, i] = result;
                }
            }

            long count = 0;

            for (int d = 1; d <= M; d++)
            {
                for (int c = 1; c <= M; c++)
                {
                    for (int b = 1; b <= M; b++)
                    {
                        for (int a = 1; a <= M; a++)
                        {
                            int numberOfVector = GetNumberOfVector(a, b, c, d);
                            int sqrt = (int)Math.Sqrt(numberOfVector);
                            if (sqrt * sqrt == numberOfVector)
                            {
                                count++;
                            }
                        }
                    }
                }
            }

            return count.ToString();
        }

        private static int GetNumberOfVector(int a, int b, int c, int d)
        {
            int number = a + b + c + d + -3;
            number += NumbersOfInsideVector[a, b];
            number += NumbersOfInsideVector[b, c];
            number += NumbersOfInsideVector[c, d];
            number += NumbersOfInsideVector[d, a];

            return number;
        }

        private static int GetInsideVector(int a, int b)
        {
            int count = 0;

            for (int i = 1; i <= a - 1; i++)
            {
                int yi = b - b * i / a;
                count += (yi - 1);
            }

            return count;
        }
    }
}
