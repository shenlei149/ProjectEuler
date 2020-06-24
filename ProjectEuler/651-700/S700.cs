namespace ProjectEuler
{
    public class S700 : ISolution
    {
        public string GetAnswer()
        {
            long second = 1504170715041707;
            long first = 8912517754604;
            long sum = second + first;
            while (true)
            {
                var next = first - second % first;
                sum += next;
                second = first;
                first = next;
                if (next == 1 || next == 0)
                {
                    break;
                }
            }

            return sum.ToString();
        }
    }
}
