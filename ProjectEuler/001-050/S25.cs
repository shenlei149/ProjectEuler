using System.Numerics;

namespace ProjectEuler
{
    public class S25 : ISolution
    {
        public string GetAnswer()
        {
            BigInteger f1 = 1;
            BigInteger f2 = 1;
            int count = 2;
            while (true)
            {
                BigInteger next = f1 + f2;
                count++;
                if (next.ToString().Length == 1000)
                {
                    return count.ToString();
                }

                f1 = f2;
                f2 = next;
            }
        }
    }
}
