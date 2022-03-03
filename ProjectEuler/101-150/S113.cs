using System.Linq;

namespace ProjectEuler
{
    public class S113 : ISolution
    {
        private static readonly int Power = 100;

        // 51161058134250
        public string GetAnswer()
        {
            long increasing = GetIncreasingCount();
            long decreasing = GetDecreasingCount();

            return (increasing + decreasing - 9 * Power).ToString();
        }

        private static long GetDecreasingCount()
        {
            //          9,8,7...,2,1,0
            // 1 digits 1,1,1...,1,1,1
            // 2 digits 
            // n digits
            long[,] matrix = new long[Power, 10];
            for (int i = 0; i < 10; i++)
            {
                matrix[0, i] = 1;
            }

            for (int i = 1; i < Power; i++)
            {
                long count = 0;
                for (int j = 0; j < 10; j++)
                {
                    count += matrix[i - 1, j];
                    matrix[i, j] = count;
                }
            }

            return matrix.Cast<long>().Sum() - Power;
        }

        private static long GetIncreasingCount()
        {
            //          9,8,7...,3,2,1
            // 1 digits 1,1,1...,1,1,1
            // 2 digits
            // n digits
            long[,] matrix = new long[Power, 9];
            for (int i = 0; i < 9; i++)
            {
                matrix[0, i] = 1;
            }

            for (int i = 1; i < Power; i++)
            {
                long count = 0;
                for (int j = 0; j < 9; j++)
                {
                    count += matrix[i - 1, j];
                    matrix[i, j] = count;
                }
            }

            return matrix.Cast<long>().Sum();
        }
    }
}
