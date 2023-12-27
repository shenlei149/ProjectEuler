namespace ProjectEuler
{
    public class S117 : ISolution
    {
        private static readonly int Layer = 50;

        public string GetAnswer()
        {
            var reds = new long[3, Layer];
            var greens = new long[4, Layer];
            var blues = new long[5, Layer];
            reds[0, 0] = 1;
            reds[1, 0] = 1;
            reds[2, 0] = 0;
            greens[0, 0] = 1;
            greens[1, 0] = 1;
            greens[2, 0] = 0;
            greens[3, 0] = 0;
            blues[0, 0] = 1;
            blues[1, 0] = 1;
            blues[2, 0] = 0;
            blues[3, 0] = 0;
            blues[4, 0] = 0;

            for (int i = 1; i < Layer; i++)
            {
                long next_blank = reds[0, i - 1] + reds[2, i - 1] + greens[3, i - 1] + blues[4, i - 1];
                reds[1, i] = reds[0, i] = next_blank;
                greens[1, i] = greens[0, i] = next_blank;
                blues[1, i] = blues[0, i] = next_blank;

                reds[2, i] = reds[1, i - 1];
                greens[2, i] = greens[1, i - 1];
                greens[3, i] = greens[2, i - 1];
                blues[2, i] = blues[1, i - 1];
                blues[3, i] = blues[2, i - 1];
                blues[4, i] = blues[3, i - 1];
            }

            long result = reds[0, Layer - 1] + reds[2, Layer - 1] + greens[3, Layer - 1] + blues[4, Layer - 1];
            return result.ToString();
        }
    }
}
