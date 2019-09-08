using System.Collections.Generic;

namespace ProjectEuler
{
    public class S91 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;

            List<Coordinate> fromPoints = new List<Coordinate>();
            List<Coordinate> toPoints = new List<Coordinate>();
            for (int i = 0; i <= 50; i++)
            {
                for (int j = 0; j <= 50; j++)
                {
                    fromPoints.Add(new Coordinate(i, j));
                    toPoints.Add(new Coordinate(i, j));
                }
            }

            fromPoints.RemoveAt(0);
            toPoints.RemoveAt(0);

            foreach (var from in fromPoints)
            {
                foreach (var to in toPoints)
                {
                    if (from.X == to.X && from.Y == to.Y)
                    {
                        continue;
                    }

                    if (to.Y * from.Y == -1 * to.X * from.X
                        || (to.Y - from.Y) * from.Y == -1 * (to.X - from.X) * from.X
                        || (to.Y - from.Y) * to.Y == -1 * (to.X - from.X) * to.X)
                    {
                        count++;
                    }
                }
            }

            return (count / 2).ToString();
        }

        private class Coordinate
        {
            public int X { get; private set; }
            public int Y { get; private set; }

            public Coordinate(int x, int y)
            {
                X = x;
                Y = y;
            }
        }
    }
}
