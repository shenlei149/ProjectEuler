using static System.Math;

namespace ProjectEuler
{
    public class S613 : ISolution
    {
        public string GetAnswer()
        {
            // |\
            // | \
            // 3  5
            // |   \
            // |__4_\
            // https://www.wolframalpha.com/input/?i=integrate+arctan(x%2F(3-y))%2Barctan(y%2F(4-x))+dy+dx,+x%3D0..4,+y%3D0..-3*x%2F4%2B3
            // 1 / 12 * PI * (integrate PI/2+arctan(x/(3-y))+arctan(y/(4-x)) dy dx, x=0..4, y=0..-3*x/4+3)
            // 1 / 12 * PI * (3 * PI + (integrate arctan(x/(3-y))+arctan(y/(4-x)) dy dx, x=0..4, y=0..-3*x/4+3))
            // 1 / 12 * PI * (3 * PI + 3 * PI + ln((3^4*2^16*sqrt(3/5))/(5^12)))
            // 1/2 + PI/12*ln((3^4*4^8*sqrt(3/5))/(5^12))
            double p = 0.5 + Log(Sqrt(0.6) * Pow(3, 4) * Pow(4, 8) / Pow(5, 12)) / 12 / PI;

            return p.ToString("F10");
        }
    }
}
