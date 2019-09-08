using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S82 : ISolution
    {
        private static readonly int dim = 80;

        public string GetAnswer()
        {
            long[,] matrix = S81.GetMatrix();

            long[,] sums = new long[dim, dim];
            for (int i = 0; i < dim; i++)
            {
                sums[i, 0] = matrix[i, 0];
            }

            for (int j = 1; j < dim; j++)
            {
                // from column j-1 to column j
                for (int i = 0; i < dim; i++)
                {
                    // consider row i
                    long min = long.MaxValue;
                    for (int k = 0; k < dim; k++)
                    {
                        long temp = sums[k, j - 1] + matrix[i, j];
                        int begin;
                        int end;
                        if (k < i)
                        {
                            begin = k + 1;
                            end = i;
                        }
                        else
                        {
                            begin = i;
                            end = k - 1;
                        }
                        for (int index = begin; index <= end; index++)
                        {
                            temp += matrix[index, j - 1];
                        }

                        if (temp < min)
                        {
                            min = temp;
                        }
                    }

                    sums[i, j] = min;
                }
            }

            var lastColumn = new List<long>();
            for (int i = 0; i < dim; i++)
            {
                lastColumn.Add(sums[i, dim - 1]);
            }

            return lastColumn.Min().ToString();
        }
    }
}
