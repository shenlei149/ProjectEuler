using System;
using System.Diagnostics;
using System.Reflection;

namespace ProjectEuler
{
    class Program
    {
        static void Main()
        {
            string problemNumber = Console.ReadLine();

            string className = "ProjectEuler.S" + problemNumber;
            Assembly assembly = typeof(Program).Assembly;
            Type type = assembly.GetType(className);

            ISolution solution = (ISolution)Activator.CreateInstance(type);

            Stopwatch sw = Stopwatch.StartNew();
            Console.WriteLine(solution.GetAnswer());
            sw.Stop();
            Console.WriteLine(sw.ElapsedMilliseconds + "ms");
        }
    }
}
