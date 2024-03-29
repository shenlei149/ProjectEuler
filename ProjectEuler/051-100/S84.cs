using System;
using System.Linq;

namespace ProjectEuler
{
    public class S84 : ISolution
    {
        private static readonly int Rolls = 1_000_000;

        // some special positions
        private static readonly int Go = 0;
        private static readonly int Jail = 10;
        private static readonly int Go2Jail = 30;
        private static readonly int C1 = 11;
        private static readonly int E3 = 24;
        private static readonly int H2 = 39;
        private static readonly int R1 = 5;
        private static readonly int[] Community = [2, 17, 33];

        // Next corresponds to Chance
        private static readonly int[] Chance = [7, 22, 36];
        private static readonly int[] NextRailway = [15, 25, 5];
        private static readonly int[] NextUtility = [12, 28, 12];

        public string GetAnswer()
        {
            // record the counts
            int[] board = new int[40];

            Random random = new();
            int doubles = 0;
            int current = 0;

            // position of special card
            int chanceIndex = 0;
            int communityIndex = 0;

            for (int i = 0; i < Rolls; i++)
            {
                int dice1 = random.Next(1, 5);
                int dice2 = random.Next(1, 5);

                // handle scenario: double
                doubles = (dice1 == dice2) ? doubles + 1 : 0;
                if (doubles > 2)
                {
                    current = Jail;
                    doubles = 0;
                }
                else
                {
                    // move forward
                    current = (current + dice1 + dice2) % 40;

                    // handle Chance
                    if (current == Chance[0] || current == Chance[1] || current == Chance[2])
                    {
                        // use special card
                        chanceIndex++;
                        chanceIndex %= 16;

                        // go to Railway or Utility
                        int index = 0;
                        if (current == Chance[1])
                        {
                            index = 1;
                        }
                        else if (current == Chance[2])
                        {
                            index = 2;
                        }

                        switch (chanceIndex)
                        {
                            case 0:
                                current = Go;
                                break;
                            case 1:
                                current = Jail;
                                break;
                            case 2:
                                current = C1;
                                break;
                            case 3:
                                current = E3;
                                break;
                            case 4:
                                current = H2;
                                break;
                            case 5:
                                current = R1;
                                break;
                            case 6:
                            case 7:
                                current = NextRailway[index];
                                break;
                            case 8:
                                current = NextUtility[index];
                                break;
                            case 9:
                                current -= 3;
                                break;
                        }
                    }

                    // handle Community Chest
                    if (current == Community[0] || current == Community[1] || current == Community[2])
                    {
                        switch (communityIndex)
                        {
                            case 0:
                                current = Go;
                                break;
                            case 10:
                                current = Jail;
                                break;
                        }

                        communityIndex++;
                        communityIndex %= 16;
                    }

                    if (current == Go2Jail)
                    {
                        current = Jail;
                    }
                }

                board[current]++;
            }

            int[] order = board.Select((item, indx) => new { Item = item, Index = indx })
                               .OrderByDescending(x => x.Item)
                               .Select(x => x.Index)
                               .ToArray();

            string modalString = "";
            for (int i = 0; i < 3; i++)
            {
                if (order[i] < 10)
                {
                    modalString += "0";
                }

                modalString += order[i].ToString();
            }

            return modalString;
        }
    }
}
