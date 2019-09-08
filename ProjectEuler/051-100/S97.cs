namespace ProjectEuler
{
    public class S97 : ISolution
    {
        public string GetAnswer()
        {
            long massivePrime = 1;
            for (int i = 0; i < 7830457; i++)
            {
                massivePrime *= 2;
                massivePrime %= 10_000_000_000;
            }

            massivePrime *= 28433;
            massivePrime += 1;

            return (massivePrime % 10_000_000_000).ToString();
        }
    }
}
