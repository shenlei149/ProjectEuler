using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S83 : ISolution
    {
        private static readonly int dim = 80;

        public string GetAnswer()
        {
            long[,] matrix = S81.GetMatrix();
            long[,] sum = new long[dim, dim];
            for (int i = 0; i < dim; i++)
            {
                for (int j = 0; j < dim; j++)
                {
                    sum[i, j] = int.MaxValue;
                }
            }

            sum[0, 0] = matrix[0, 0];
            var pointsToBeUpdated = new Queue<Tuple<int, int>>();
            pointsToBeUpdated.Enqueue(new Tuple<int, int>(0, 0));
            while (pointsToBeUpdated.Count != 0)
            {
                var point = pointsToBeUpdated.Dequeue();
                if (CanMoveToLeft(point))
                {
                    long newValue = sum[point.Item1, point.Item2] + matrix[point.Item1 - 1, point.Item2];
                    if (newValue < sum[point.Item1 - 1, point.Item2])
                    {
                        sum[point.Item1 - 1, point.Item2] = newValue;
                        pointsToBeUpdated.Enqueue(new Tuple<int, int>(point.Item1 - 1, point.Item2));
                    }
                }

                if (CanMoveToRight(point))
                {
                    long newValue = sum[point.Item1, point.Item2] + matrix[point.Item1 + 1, point.Item2];
                    if (newValue < sum[point.Item1 + 1, point.Item2])
                    {
                        sum[point.Item1 + 1, point.Item2] = newValue;
                        pointsToBeUpdated.Enqueue(new Tuple<int, int>(point.Item1 + 1, point.Item2));
                    }
                }

                if (CanUp(point))
                {
                    long newValue = sum[point.Item1, point.Item2] + matrix[point.Item1, point.Item2 - 1];
                    if (newValue < sum[point.Item1, point.Item2 - 1])
                    {
                        sum[point.Item1, point.Item2 - 1] = newValue;
                        pointsToBeUpdated.Enqueue(new Tuple<int, int>(point.Item1, point.Item2 - 1));
                    }
                }

                if (CanDown(point))
                {
                    long newValue = sum[point.Item1, point.Item2] + matrix[point.Item1, point.Item2 + 1];
                    if (newValue < sum[point.Item1, point.Item2 + 1])
                    {
                        sum[point.Item1, point.Item2 + 1] = newValue;
                        pointsToBeUpdated.Enqueue(new Tuple<int, int>(point.Item1, point.Item2 + 1));
                    }
                }
            }

            return sum[dim - 1, dim - 1].ToString();
        }

        private static bool CanMoveToLeft(Tuple<int, int> point)
        {
            return point.Item1 > 0;
        }

        private static bool CanMoveToRight(Tuple<int, int> point)
        {
            return point.Item1 < dim - 1;
        }

        private static bool CanUp(Tuple<int, int> point)
        {
            return point.Item2 > 0;
        }

        private static bool CanDown(Tuple<int, int> point)
        {
            return point.Item2 < dim - 1;
        }
    }
}
