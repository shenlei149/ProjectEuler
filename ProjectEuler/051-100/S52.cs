using System;

namespace ProjectEuler
{
    public class S52 : ISolution
    {
        public string GetAnswer()
        {
            int answer = 0;
            for (int i = 3; i < 10; i++)
            {
                for (int j = (int)Math.Pow(10, i) + 2; j < (int)Math.Pow(10, i + 1) / 6; j += 3)
                {
                    if (HasTwoOrThree(j) && HasZeroOrFive(j) && HasMoreThanSix(j) && HasFourOrFiveOrSix(j))
                    {
                        if (Utils.IsPermutation(j, j * 6)
                            && Utils.IsPermutation(j, j * 5)
                            && Utils.IsPermutation(j, j * 4)
                            && Utils.IsPermutation(j, j * 3)
                            && Utils.IsPermutation(j, j * 2))
                        {
                            answer = j;
                            goto exit;
                        }
                    }
                }
            }

        exit:
            return answer.ToString();
        }

        static bool HasSpecifiedDigit(int number, int spec)
        {
            while (number != 0)
            {
                if (number % 10 == spec)
                {
                    return true;
                }

                number /= 10;
            }

            return false;
        }

        static bool HasZeroOrFive(int number)
        {
            return HasSpecifiedDigit(number, 0) || HasSpecifiedDigit(number, 5);
        }

        static bool HasTwoOrThree(int number)
        {
            return HasSpecifiedDigit(number, 2) || HasSpecifiedDigit(number, 3);
        }

        static bool HasFourOrFiveOrSix(int number)
        {
            return HasSpecifiedDigit(number, 4) || HasSpecifiedDigit(number, 5) || HasSpecifiedDigit(number, 6);
        }

        static bool HasMoreThanSix(int number)
        {
            return HasSpecifiedDigit(number, 9)
                || HasSpecifiedDigit(number, 8)
                || HasSpecifiedDigit(number, 7)
                || HasSpecifiedDigit(number, 6)
                || HasSpecifiedDigit(number, 5);
        }
    }
}
