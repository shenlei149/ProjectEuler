using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S62 : ISolution
    {
        public string GetAnswer()
        {
            var cubes = new List<long>();
            for (long i = 4642; i < 10000; i++)
            {
                cubes.Add(i * i * i);
            }

            var cubeMapping = new Dictionary<long, string>();
            for (int i = 0; i < cubes.Count; i++)
            {
                long cube = cubes[i];
                char[] abs = cube.ToString().ToCharArray();
                Array.Sort(abs);
                string curString = new string(abs);
                cubeMapping.Add(cube, curString);
            }

            string[] sortedABS = cubeMapping.Values.ToArray();
            Array.Sort(sortedABS);

            List<string> answerStrings = new List<string>();
            for (int i = 0; i < sortedABS.Length - 4; i++)
            {
                if (sortedABS[i].Equals(sortedABS[i + 4]))
                {
                    answerStrings.Add(sortedABS[i]);
                }
            }

            return cubeMapping.Where(p => p.Value.Equals(answerStrings[0])).First().Key.ToString();
        }
    }
}
