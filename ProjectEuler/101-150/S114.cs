namespace ProjectEuler
{
    public class S114 : ISolution
    {
        private static readonly int Layer = 50;
        private static readonly int RedBlockLength = Layer;

        public string GetAnswer()
        {
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
                for (int red = 3; red <= RedBlockLength; red++)
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
            for (int red = 3; red <= RedBlockLength; red++)
            {
                result += reds[red, Layer - 1];
            }
            result += reds[0, Layer - 1]; //add #grey

            return result.ToString();
        }
    }
}
