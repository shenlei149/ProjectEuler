using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S61 : ISolution
    {
        [Flags]
        enum EnumCandidate
        {
            None = 0,
            Four = 1,
            Five = 2,
            Six = 4,
            Seven = 8,
            Eight = 16,
        }

        private class OrderedNumber
        {
            public OrderedNumber(long content, EnumCandidate flags = EnumCandidate.None)
            {
                Content = content;
                Flags = flags;
            }

            public long Content { get; set; }

            public EnumCandidate Flags { get; set; }
        }

        public string GetAnswer()
        {
            Initialize(out List<int> P3, out List<int> P4, out List<int> P5, out List<int> P6, out List<int> P7, out List<int> P8);

            List<OrderedNumber> cur = new List<OrderedNumber>();
            foreach (var i in P3)
            {
                cur.Add(new OrderedNumber(i));
            }

            for (int i = 0; i < 5; i++)
            {
                List<OrderedNumber> next = new List<OrderedNumber>();

                foreach (var orderedSet in cur)
                {
                    Cat(P4, next, orderedSet, EnumCandidate.Four);
                    Cat(P5, next, orderedSet, EnumCandidate.Five);
                    Cat(P6, next, orderedSet, EnumCandidate.Six);
                    Cat(P7, next, orderedSet, EnumCandidate.Seven);
                    Cat(P8, next, orderedSet, EnumCandidate.Eight);
                }

                cur = next;
            }

            foreach (var orderedSet in cur)
            {
                if (orderedSet.Content / 1000000000000L == orderedSet.Content % 100)
                {
                    long sum = 0;
                    long result = orderedSet.Content;
                    for (int i = 0; i < 6; i++)
                    {
                        sum += result % 10000;
                        result /= 100;
                    }

                    return sum.ToString();
                }
            }

            return string.Empty;
        }

        private static void Cat(List<int> Pi, List<OrderedNumber> numbers, OrderedNumber number, EnumCandidate flag)
        {
            if (!number.Flags.HasFlag(flag))
            {
                foreach (var i in Pi)
                {
                    if (number.Content % 100 == i / 100)
                    {
                        numbers.Add(new OrderedNumber(number.Content * 100 + i % 100, number.Flags | flag));
                    }
                }
            }
        }

        private static void Initialize(
            out List<int> P3, out List<int> P4, out List<int> P5,
            out List<int> P6, out List<int> P7, out List<int> P8)
        {
            P3 = new List<int>();
            P4 = new List<int>();
            P5 = new List<int>();
            P6 = new List<int>();
            P7 = new List<int>();
            P8 = new List<int>();

            for (int n = 0; n * (n + 1) / 2 < 10000; n++)
            {
                P3.Add(n * (n + 1) / 2);
                P4.Add(n * n);
                P5.Add(n * (3 * n - 1) / 2);
                P6.Add(n * (2 * n - 1));
                P7.Add(n * (5 * n - 3) / 2);
                P8.Add(n * (3 * n - 2));
            }

            P3 = P3.Where(Meet).ToList();
            P4 = P4.Where(Meet).ToList();
            P5 = P5.Where(Meet).ToList();
            P6 = P6.Where(Meet).ToList();
            P7 = P7.Where(Meet).ToList();
            P8 = P8.Where(Meet).ToList();
        }

        private static bool Meet(int i)
        {
            return i >= 1000 && i < 10000;
        }
    }
}
