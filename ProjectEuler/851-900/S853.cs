namespace ProjectEuler
{
    public class S853 : ISolution
    {
        private static readonly long N = 1000000000;
        private static readonly long[] f100 = new long[125];
        private static readonly long[] m100 = new long[125];

        private static readonly int[] bases = new int[] { 2, 3, 5, 7, 11, 31, 41, 61, 2521 };
        private static readonly int[] power = new int[] { 1, 0, 0, 0, 0, 0, 0, 0, 0 };

        public string GetAnswer()
        {
            long sum = 0;

            m100[0] = 1;
            m100[1] = 1;

            f100[0] = 1;
            f100[1] = 1;

            while (true)
            {
                long n = 0;
                bool ok = Next(power, ref n);
                if (!ok)
                {
                    break;
                }

                if (Period200(n))
                {
                    sum += n;
                }
            }

            return sum.ToString(); ;
        }

        private static long ToLong(int[] power)
        {
            long p = 1;
            for (int i = 0; i < power.Length; i++)
            {
                for (int j = 0; j < power[i]; j++)
                {
                    p *= bases[i];
                }
            }

            return p;
        }

        private static bool Next(int[] power, ref long n)
        {
            for (int i = 0; i < power.Length; i++)
            {
                power[i]++;
                n = ToLong(power);
                if (n > N)
                {
                    power[i] = 0;
                    if (i == power.Length - 1)
                    {
                        return false;
                    }
                }
                else
                {
                    break;
                }
            }

            return true;
        }

        private static bool Period200(long n)
        {
            for (int p = 2; p < 125; p++)
            {
                f100[p] = (f100[p - 1] + f100[p - 2]) % n;
                m100[p] = f100[p];
            }

            for (int i = 2; i < 122; i++)
            {
                if (m100[i] == 1 && m100[i + 1] == 1 && m100[i + 2] == 2)
                {
                    if (i == 120)
                    {
                        return true;
                    }

                    break;
                }
            }

            return false;
        }
    }
}
