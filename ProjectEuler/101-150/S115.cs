namespace ProjectEuler
{
    public class S115 : ISolution
    {
        public string GetAnswer()
        {
            int n = 50;
            while (true)
            {
                if (F(50, n) > 1_000_000)
                    break;

                n++;
            }

            return n.ToString();
        }

        private long F(int m, int n)
        {
            int Layer = n;
            int RedBlockLength = Layer;

            // Color: grey[0] or red[1:RedBlockLength]; Layer
            var reds = new long[RedBlockLength + 1, Layer];
            reds[0, 0] = 1;
            reds[1, 0] = 1;
            for (int i = 2; i <= RedBlockLength; i++)
            {
                reds[i, 0] = 0;
            }

            for (int layer = 1; layer < Layer; layer++)
            {
                long count = 0;
                for (int red = m; red <= RedBlockLength; red++)
                {
                    count += reds[red, layer - 1];
                }
                count += reds[0, layer - 1]; //add #grey

                reds[0, layer] = count;

                for (int red = 1; red <= RedBlockLength; red++)
                {
                    reds[red, layer] = reds[red - 1, layer - 1];
                }
            }

            long result = 0;
            for (int red = m; red <= RedBlockLength; red++)
            {
                result += reds[red, Layer - 1];
            }
            result += reds[0, Layer - 1]; //add #grey

            return result;
        }
    }
}
