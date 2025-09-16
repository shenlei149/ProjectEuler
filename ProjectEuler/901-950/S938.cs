namespace ProjectEuler
{
    public class S938 : ISolution
    {
        static readonly int RED = 24690;
        static readonly int BLACK = 12345;

        static readonly double[][] p = new double[RED + 1][];

        // 0.2928967987
        public string GetAnswer()
        {
            p[0] = new double[BLACK + 1];
            p[0][0] = 0;
            for (int b = 1; b < BLACK + 1; b++)
            {
                p[0][b] = 1;
            }

            for (int r = 1; r < RED + 1; r++)
            {
                p[r] = new double[BLACK + 1];
                p[r][0] = 0;
                for (int b = 1; b < BLACK + 1; b++)
                {
                    GetPBy(r, b);
                }

                if (r >= 3)
                {
                    p[r - 3] = null;
                }
            }

            return p[RED][BLACK].ToString("F10");
        }

        static void GetPBy(int red, int black)
        {
            double dem = (red + black) * (red + black - 1);
            double p_r_b = p[red][black - 1];
            double r_b_choice_p = 2.0 * red * black / dem;

            double p_r_r = 0;
            double r_r_choice_p = 0;
            if (red >= 2)
            {
                p_r_r = p[red - 2][black];
                r_r_choice_p = 1.0 * red * (red - 1) / dem;
            }

            double b_b_choice_p = 1.0 * black * (black - 1) / dem;
            double p_b_b = (p_r_b * r_b_choice_p + p_r_r * r_r_choice_p) / (1.0 - b_b_choice_p);
            p[red][black] = p_b_b;
        }
    }
}
