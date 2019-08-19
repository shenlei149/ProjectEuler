using System.Linq;

namespace ProjectEuler
{
    public class S43 : ISolution
    {
        public string GetAnswer()
        {
            var digits = new string[] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

            var d3 = (from i in digits
                      from j in digits
                      from k in digits
                      select i + j + k)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s) % 17 == 0)
                      .ToArray();

            var d4 = (from i in digits
                      from n in d3
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 13 == 0)
                      .ToArray();

            var d5 = (from i in digits
                      from n in d4
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 11 == 0)
                      .ToArray();

            var d6 = (from i in digits
                      from n in d5
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 7 == 0)
                      .ToArray();

            var d7 = (from i in digits
                      from n in d6
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 5 == 0)
                      .ToArray();

            var d8 = (from i in digits
                      from n in d7
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 3 == 0)
                      .ToArray();

            var d9 = (from i in digits
                      from n in d8
                      select i + n)
                      .Where(s => Utils.IsPandigital(s, true))
                      .Where(s => int.Parse(s.Substring(0, 3)) % 2 == 0)
                      .ToArray();

            var d10 = (from i in digits
                       from n in d9
                       select i + n)
                       .Where(s => Utils.IsPandigital(s, true))
                       .Where(s => s[0] != 0)
                       .ToArray();

            return d10.Select(s => long.Parse(s)).Sum().ToString();
        }
    }
}
