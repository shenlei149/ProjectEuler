using System.Text;

namespace ProjectEuler
{
    public class S40 : ISolution
    {
        public string GetAnswer()
        {
            StringBuilder sb = new StringBuilder(".");
            for (int i = 1; ; i++)
            {
                sb.Append(i.ToString());
                if (sb.Length > 1000000)
                {
                    break;
                }
            }

            string s = sb.ToString();
            int answer = (s[1] - '0') * (s[10] - '0') * (s[100] - '0') *
                (s[1000] - '0') * (s[10000] - '0') * (s[100000] - '0') * (s[1000000] - '0');

            return answer.ToString();
        }
    }
}
