using System;

namespace ProjectEuler
{
    public class S345 : ISolution
    {
        private static readonly int MatrixLength = 15;
        private static readonly int[,] matrix = new int[MatrixLength, MatrixLength];
        private static readonly int[] MaxNumber = new int[MatrixLength];
        private static int MaxSum = 0;

        public string GetAnswer()
        {
            Init();
            InitMaxNumber();

            int[] columns = new int[MatrixLength];
            for (int curRow = 0; curRow < MatrixLength; curRow++)
            {
                SearchMaxSum(0, columns, curRow);
            }

            return MaxSum.ToString();
        }

        private static void SearchMaxSum(int row, int[] columns, int searchTo)
        {
            int sum = GetSum(columns, row);
            if (row == searchTo + 1)
            {
                if (sum > MaxSum)
                {
                    MaxSum = sum;
                }
            }
            else
            {
                int possibleMax = sum;
                for (int curRow = row; curRow <= searchTo; curRow++)
                {
                    possibleMax += MaxNumber[curRow];
                }

                if (possibleMax < MaxSum)
                {
                    return;
                }

                for (int col = 0; col < MatrixLength; col++)
                {
                    if (CheckValid(columns, row, col))
                    {
                        columns[row] = col;
                        SearchMaxSum(row + 1, columns, searchTo);
                    }
                }
            }
        }

        private static bool CheckValid(int[] columns, int row, int col)
        {
            for (int i = 0; i < row; i++)
            {
                if (columns[i] == col)
                {
                    return false;
                }
            }

            return true;
        }

        private static int GetSum(int[] columns, int row)
        {
            int sum = 0;
            for (int i = 0; i < row; i++)
            {
                sum += matrix[i, columns[i]];
            }

            return sum;
        }

        private static void InitMaxNumber()
        {
            for (int i = 0; i < MatrixLength; i++)
            {
                int max = 0;
                for (int j = 0; j < MatrixLength; j++)
                {
                    if (matrix[i, j] > max)
                    {
                        max = matrix[i, j];
                    }
                }

                MaxNumber[i] = max;
            }
        }

        private static void Init()
        {
            string[] words = Data.Split(new char[] { ' ', '\n', '\r' },
                StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < words.Length; i++)
            {
                matrix[i / MatrixLength, i % MatrixLength] = int.Parse(words[i]);
            }
        }

        private static readonly string Data = @"
  7  53 183 439 863 497 383 563  79 973 287  63 343 169 583
627 343 773 959 943 767 473 103 699 303 957 703 583 639 913
447 283 463  29  23 487 463 993 119 883 327 493 423 159 743
217 623   3 399 853 407 103 983  89 463 290 516 212 462 350
960 376 682 962 300 780 486 502 912 800 250 346 172 812 350
870 456 192 162 593 473 915  45 989 873 823 965 425 329 803
973 965 905 919 133 673 665 235 509 613 673 815 165 992 326
322 148 972 962 286 255 941 541 265 323 925 281 601  95 973
445 721  11 525 473  65 511 164 138 672  18 428 154 448 848
414 456 310 312 798 104 566 520 302 248 694 976 430 392 198
184 829 373 181 631 101 969 613 840 740 778 458 284 760 390
821 461 843 513  17 901 711 993 293 157 274  94 192 156 574
 34 124   4 878 450 476 712 914 838 669 875 299 823 329 699
815 559 813 459 522 788 168 586 966 232 308 833 251 631 107
813 883 451 509 615  77 281 613 459 205 380 274 302  35 805";
    }
}
