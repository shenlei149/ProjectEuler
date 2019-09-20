using System;
using System.Collections.Generic;

namespace ProjectEuler
{
    public class S44 : ISolution
    {
        public string GetAnswer()
        {
            List<int> pentagonNumbers = new List<int>();
            for (int i = 1; i < 3000; i++)
            {
                pentagonNumbers.Add(i * (3 * i - 1) / 2);
            }

            int[] numbers = pentagonNumbers.ToArray();
            int length = numbers.Length;
            for (int i = 0; i < length - 1; i++)
            {
                for (int j = i; j < length; j++)
                {
                    if (Array.BinarySearch(numbers, numbers[i] + numbers[j]) > 0 && Array.BinarySearch(numbers, numbers[j] - numbers[i]) > 0)
                    {
                        return (numbers[j] - numbers[i]).ToString();
                    }
                }
            }

            return string.Empty;
        }
    }
}
