using System.Text;

namespace ProjectEuler
{
    public class S751 : ISolution
    {
        private static readonly int Length = 16;
        public string GetAnswer()
        {
            double theta = 2.5;
            string lastAnswer = "2.5";
            while (true)
            {
                double[] bn = new double[Length];
                int[] an = new int[Length];
                bn[0] = theta;
                an[0] = (int)bn[0];
                for (int i = 0; i < Length - 1; i++)
                {
                    int b = (int)bn[i];
                    bn[i + 1] = b * (bn[i] - b + 1);
                    an[i + 1] = (int)bn[i + 1];
                }

                StringBuilder sb = new();
                sb.Append(an[0]).Append('.');
                for (int i = 1; i < Length; i++)
                {
                    sb.Append(an[i]);
                }

                string answer = sb.ToString();
                if (answer == lastAnswer)
                {
                    break;
                }

                lastAnswer = answer;
                theta = double.Parse(answer);
            }

            return lastAnswer[..26];
        }
    }
}
