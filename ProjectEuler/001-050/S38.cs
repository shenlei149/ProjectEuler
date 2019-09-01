using System.Text;

namespace ProjectEuler
{
    public class S38 : ISolution
    {
        public string GetAnswer()
        {
            int maxPandigitalNumber = 0;
            for (int i = 2; i < 10000; i++)
            {
                StringBuilder sb = new StringBuilder();

                int n = 1;
                while (sb.Length < 9)
                {
                    sb.Append(i * n);
                    n++;
                }

                if (sb.Length == 9 && Utils.IsPandigital(sb.ToString(), false))
                {
                    int tmp = int.Parse(sb.ToString());

                    if (tmp > maxPandigitalNumber)
                    {
                        maxPandigitalNumber = tmp;
                    }
                }
            }

            return maxPandigitalNumber.ToString();
        }
    }
}
