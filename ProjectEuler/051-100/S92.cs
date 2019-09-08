using System.Linq;

namespace ProjectEuler
{
    public class S92 : ISolution
    {
        public string GetAnswer()
        {
            int count = 0;
            for (int i = 2; i < 10000000; i++)
            {
                int tmp = i;
                while (tmp != 89 && tmp != 1)
                {
                    tmp = tmp.ToString().Select(c => c - '0').Select(j => j * j).Sum();
                }

                if (tmp == 89)
                {
                    count++;
                }
            }

            return count.ToString();
        }
    }
}
