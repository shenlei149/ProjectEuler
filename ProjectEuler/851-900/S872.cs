using System;

namespace ProjectEuler
{
    public class S872 : ISolution
    {
        public string GetAnswer()
        {
            long root = 100_000_000_000_000_000;
            long find = 16677181699666569;     //9^17
            long sum = root;
            long diff = root - find;

            long node = root;
            long diff_level = 1;
            while (diff != 0)
            {
                while (true)
                {
                    if (diff % 2 == 1)
                    {
                        node -= diff_level;
                        sum += node;

                        diff /= 2;
                        diff_level *= 2;

                        break;
                    }

                    diff /= 2;
                    diff_level *= 2;
                }
            }

            return sum.ToString(); ;
        }
    }
}
