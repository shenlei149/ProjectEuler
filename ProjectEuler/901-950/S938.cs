using System;

namespace ProjectEuler
{
    public class S938 : ISolution
    {
        static readonly int RED = 24690;
        static readonly int BLACK = 12345;

        static readonly double?[][] p = new double?[RED + 1][];

        // 0.2928967987
        public string GetAnswer()
        {
            for (int r = 0; r < RED + 1; r++)
            {
                p[r] = new double?[BLACK + 1];
                for (int b = 0; b < BLACK + 1; b++)
                {
                    GetPBy(r, b);
                }

                if (r > 3)
                {
                    p[r - 3] = null;
                }
            }

            return GetPBy(RED, BLACK).ToString("F10");
        }

        static double GetPBy(int red, int black)
        {
            if (p[red][black].HasValue)
            {
                return p[red][black].Value;
            }

            if (red == 0 && black == 0)
            {
                return 0;
            }

            if (red == 0)
            {
                p[red][black] = 1;
                return p[red][black].Value;
            }

            if (black == 0)
            {
                p[red][black] = 0;
                return p[red][black].Value;
            }

            double p_r_b = GetPBy(red, black - 1);
            double r_b_choice_p = 2.0 * red * black / (red + black) / (red + black - 1);

            double p_r_r = 0;
            double r_r_choice_p = 0;
            if (red >= 2)
            {
                p_r_r = GetPBy(red - 2, black);
                r_r_choice_p = 1.0 * red * (red - 1) / (red + black) / (red + black - 1);
            }

            double b_b_choice_p = 0;
            if (black >= 2)
            {
                b_b_choice_p = 1.0 * black * (black - 1) / (red + black) / (red + black - 1);
            }

            double p_b_b = (p_r_b * r_b_choice_p + p_r_r * r_r_choice_p) / (1.0 - b_b_choice_p);
            p[red][black] = p_b_b;
            return p[red][black].Value;
        }
    }
}
