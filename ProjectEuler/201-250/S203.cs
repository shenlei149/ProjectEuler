using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProjectEuler
{
    public class S203 : ISolution
    {
        public string GetAnswer()
        {
            var rows = new List<long[]>();
            for (int i = 0; i < 51; i++)
            {
                long[] row = new long[i + 1];
                for (int j = 0; j < row.Length; j++)
                {
                    if (j == 0 || j == row.Length - 1)
                    {
                        row[j] = 1;
                    }
                    else
                    {
                        var lastRow = rows[i - 1];
                        row[j] = lastRow[j - 1] + lastRow[j];
                    }
                }

                rows.Add(row);
            }

            var smallPrimeSquare = new int[] { 4, 9, 25, 49 };
            return rows.SelectMany(l => l).Distinct()
                .Where(l =>
                {
                    foreach (var square in smallPrimeSquare)
                    {
                        if (l % square == 0)
                        {
                            return false;
                        }
                    }

                    return true;
                }).Sum().ToString();
        }
    }
}
