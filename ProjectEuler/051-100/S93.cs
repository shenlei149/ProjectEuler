using System;
using System.Collections.Generic;
using System.Linq;

namespace ProjectEuler
{
    public class S93 : ISolution
    {
        enum Operators
        {
            Add,
            Sub,
            Mul,
            Div,
            Invalid,
        }

        readonly List<Operators[]> expressions = [];

        public string GetAnswer()
        {
            FillExpressions(expressions);

            int max = -1;
            List<int> digits = [];
            var series = Utils.Combination(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 4);
            foreach (var array in series)
            {
                var tmp = GetLastConsecutiveNumber(array as List<int>);
                if (tmp > max)
                {
                    max = tmp;
                    digits = array as List<int>;
                }
            }

            return string.Join("", digits);
        }

        private int GetLastConsecutiveNumber(List<int> numbers)
        {
            List<int> targets = [];
            var candidates = Utils.Permutations(numbers);
            foreach (var c in candidates)
            {
                targets.AddRange(GetTargets(c.ToList()));
            }

            targets = targets.Where(i => i > 0).Distinct().ToList();
            targets.Sort();
            for (int i = 0; i < targets.Count; i++)
            {
                if (targets[i] != i + 1)
                {
                    return i;
                }
            }

            return -1;
        }

        private List<int> GetTargets(List<int> numbers)
        {
            List<int> targets = [];
            foreach (var expression in expressions)
            {
                targets.AddRange(GetTargets(numbers, expression));
            }

            return targets;
        }

        private static List<int> GetTargets(List<int> numbers, Operators[] expression)
        {
            List<int> targets = [];

            var target = Compute(expression[1], Compute(expression[0], numbers[0], numbers[1]),
                                                Compute(expression[2], numbers[2], numbers[3]));
            AddNullableTarget(targets, target);

            target = Compute(expression[2],
                             Compute(expression[1],
                                     Compute(expression[0], numbers[0], numbers[1]),
                                     numbers[2]),
                             numbers[3]);
            AddNullableTarget(targets, target);

            target = Compute(expression[0], numbers[0],
                             Compute(expression[2],
                                     Compute(expression[1], numbers[1], numbers[2]),
                                     numbers[3]));
            AddNullableTarget(targets, target);

            target = Compute(expression[2],
                             Compute(expression[0],
                                     numbers[0],
                                     Compute(expression[1], numbers[1], numbers[2])),
                             numbers[3]);
            AddNullableTarget(targets, target);

            target = Compute(expression[0], numbers[0],
                             Compute(expression[1], numbers[1],
                                     Compute(expression[2], numbers[2], numbers[3])));
            AddNullableTarget(targets, target);

            return targets;
        }

        private static void AddNullableTarget(List<int> targets, double? v)
        {
            if (v.HasValue)
            {
                var i = Convert.ToInt32(v.Value);
                if (Math.Abs(v.Value - i) < 0.001)
                {
                    targets.Add(i);
                }
            }
        }

        private static double? Compute(Operators op, double? left, double? right)
        {
            if (!left.HasValue || !right.HasValue)
            {
                return null;
            }

            switch (op)
            {
                case Operators.Add:
                    return left + right;
                case Operators.Sub:
                    return left - right;
                case Operators.Mul:
                    return left * right;
                case Operators.Div:
                    if (right == 0)
                    {
                        return null;
                    }

                    return left / right;
            }

            return null;
        }

        private static void FillExpressions(List<Operators[]> expressions)
        {
            InternalFillExpressions(expressions, new Operators[3], 0);
        }

        private static void InternalFillExpressions(List<Operators[]> expressions, Operators[] expression, int depth)
        {
            if (depth == 3)
            {
                expressions.Add(expression);
                return;
            }

            for (Operators op = Operators.Add; op < Operators.Invalid; op++)
            {
                expression[depth] = op;
                InternalFillExpressions(expressions, (Operators[])expression.Clone(), depth + 1);
            }
        }
    }
}
