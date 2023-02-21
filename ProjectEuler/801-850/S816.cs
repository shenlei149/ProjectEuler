using System;

namespace ProjectEuler
{
    public class S816 : ISolution
    {
        struct Point : IComparable<Point>
        {
            public int X { get; set; }
            public int Y { get; set; }

            public int CompareTo(Point other)
            {
                if (X < other.X)
                { return -1; }
                else if (X == other.X)
                {
                    if (Y < other.Y)
                    { return -1; }
                    else if (Y == other.Y)
                    { return 0; }
                    else return 1;
                }
                else
                { return 1; }
            }

            public double Distance(Point other)
            {
                long diffX = other.X - X;
                long diffY = other.Y - Y;
                return Math.Sqrt(diffX * diffX + diffY * diffY);
            }
        }

        private static readonly int N = 2_000_000;

        public string GetAnswer()
        {
            int[] s = new int[2 * N];
            Point[] P = new Point[N];

            s[0] = 290797;
            for (int i = 1; i < 2 * N; i++)
            {
                long pre = s[i - 1];
                s[i] = (int)((pre * pre) % 50515093);
            }

            for (int i = 0; i < N; i++)
            {
                P[i].X = s[i * 2];
                P[i].Y = s[i * 2 + 1];
            }

            Array.Sort(P);

            double distance = double.MaxValue;
            for (int i = 0; i < P.Length - 1; i++)
            {
                var p = P[i];
                for (int j = i + 1; j < P.Length; j++)
                {
                    var other = P[j];
                    if ((other.X - p.X) > distance)
                    { break; }

                    var d = p.Distance(other);
                    if (d < distance)
                    { distance = d; }
                }
            }

            // 20.880613018
            return String.Format("{0:0.000000000}", distance);
        }
    }
}
