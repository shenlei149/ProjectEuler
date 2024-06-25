namespace ProjectEuler
{
    public class S788 : ISolution
    {
        private static readonly int MaxD = 2022;
        private static readonly long Mod = 1_000_000_007;
        private static readonly long[] Power9 = new long[MaxD];
        private static readonly long[,] cache = new long[MaxD + 1, MaxD + 1];

        public string GetAnswer()
        {
            Power9[0] = 1;
            for (int i = 1; i < MaxD; i++)
            {
                Power9[i] = Power9[i - 1] * 9;
                Power9[i] %= Mod;
            }

            for (int i = 0; i <= MaxD; i++)
            {
                cache[i, 0] = 1;
                cache[i, 1] = i > 1 ? i : 1;
            }

            long sum = 0;
            for (int i = 1; i <= MaxD; i++)
            {
                sum += Count(i);
                sum %= Mod;
            }

            return sum.ToString();
        }

        private static long Count(int D)
        {
            long count = 0;
            int start = D % 2 == 0 ? D / 2 + 1 : (D + 1) / 2;
            for (int i = start; i <= D; i++)
            {
                // dominating is zero
                {
                    var thisCount = GetCombinationsCountWithCache(D - 1, i);
                    int remainNDigits = D - i;
                    thisCount *= Power9[remainNDigits];
                    thisCount %= Mod;

                    count += thisCount;
                }

                // dominating is not zero
                {
                    // first digit is dominating
                    {
                        var thisCount = GetCombinationsCountWithCache(D - 1, i - 1);
                        int remainNDigits = D - i;
                        thisCount *= Power9[remainNDigits];
                        thisCount %= Mod;

                        // # !zero
                        thisCount *= 9;

                        count += thisCount;
                    }

                    // first digit is not dominating
                    {
                        var thisCount = GetCombinationsCountWithCache(D - 1, i);
                        int remainNDigits = D - i - 1;
                        if (remainNDigits >= 0)
                        {
                            thisCount *= Power9[remainNDigits];
                            thisCount %= Mod;
                        }

                        // first digit
                        thisCount *= 8;

                        // # !zero
                        thisCount *= 9;

                        count += thisCount;
                    }
                }
            }

            return count % Mod;
        }

        private static long GetCombinationsCountWithCache(long total, long pickedCount)
        {
            if (pickedCount > total)
            {
                return 0;
            }

            if (pickedCount == total)
            {
                return 1;
            }

            if (pickedCount * 2 > total)
            {
                pickedCount = total - pickedCount;
            }

            if (cache[total, pickedCount] == 0)
            {

                long count = (GetCombinationsCountWithCache(total - 1, pickedCount)
                            + GetCombinationsCountWithCache(total - 1, pickedCount - 1)) % Mod;

                cache[total, pickedCount] = count;
                cache[total, total - pickedCount] = count;
            }

            return cache[total, pickedCount];
        }
    }
}
