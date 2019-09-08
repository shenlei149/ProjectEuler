using System;
using System.Collections.Generic;
using static System.Math;

namespace ProjectEuler
{
    public class S607 : ISolution
    {
        public string GetAnswer()
        {
            List<Point> points = new List<Point>
            {
                new Point(0, 0) // A
            };

            double scaling = Sqrt(2);

            double direct = 50 * scaling;

            double current = (100 - direct) / 2 / scaling; // 25*(sqrt(2)-1)
            points.Add(new Point(current, current));

            for (int i = 1; i <= 5; i++)
            {
                points.Add(new Point(current + i * 10, current + i * 10));
            }

            // B
            points.Add(new Point(100 / scaling, 100 / scaling));

            const int NumIterations = 10000;
            for (double delta = 0.01; delta >= 0.00001; delta /= 10)
            {
                for (int i = 0; i < NumIterations; i++)
                {
                    Mutate(points, delta);
                }
            }

            return Duration(points).ToString("F10");
        }

        private class Point
        {
            public double X { get; }
            public double Y { get; set; }

            public Point(double x, double y)
            {
                X = x;
                Y = y;
            }

            // distance between two points
            public double Distance(Point other)
            {
                var diffX = X - other.X;
                var diffY = Y - other.Y;
                return Sqrt(diffX * diffX + diffY * diffY);
            }
        }

        private static double Duration(List<Point> points)
        {
            List<double> speed = new List<double> { 10, 9, 8, 7, 6, 5, 10 };

            double result = 0;
            for (int i = 0; i < speed.Count; i++)
            {
                var way = points[i].Distance(points[i + 1]);
                result += way / speed[i];
            }

            return result;
        }

        private static void Mutate(List<Point> points, double delta)
        {
            var oldDuration = Duration(points);

            if ((random.Next() & 1) != 0)
            {
                delta = -delta;
            }

            var id = random.Next() % 6 + 1;
            points[id].Y += delta;

            if (Duration(points) >= oldDuration)
            {
                points[id].Y -= delta;
            }
        }

        private static readonly Random random = new Random();
    }
}
