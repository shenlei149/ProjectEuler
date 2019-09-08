namespace ProjectEuler
{
    public class S206 : ISolution
    {
        public string GetAnswer()
        {
            for (long i = 100000003; ;)
            {
                if (HasRightForm(i))
                {
                    return (i * 10).ToString();
                }

                if (i % 10 == 3)
                {
                    i += 4;
                }
                else
                {
                    i += 6;
                }
            }
        }

        private static bool HasRightForm(long i)
        {
            string s = (i * i).ToString();
            return s[2] == '2' && s[4] == '3' && s[6] == '4' && s[8] == '5'
                && s[10] == '6' && s[12] == '7' && s[14] == '8';
        }
    }
}
