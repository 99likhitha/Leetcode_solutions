public class Solution {
    public int RobotSim(int[] commands, int[][] obstacles) {
        int maxDist=0;
        var ObstacleSet = new HashSet<(int,int)>();

        for(int i = 0 ; i < obstacles.Length; i++)
        {
            ObstacleSet.Add((obstacles[i][0] , obstacles[i][1]));
        }

        int[][] directions = new int[][] {

            new int[] {0,1},
            new int[]{1,0},
            new int[] {0,-1},
            new int[] {-1,0}
        };

        int d=0;
        int newx=0,newy=0;

        for(int i = 0; i < commands.Length; i++)
        {
            if(commands[i] == -2)
            {
                d = (d + 3) % 4;
            }

            else if(commands[i] == -1)
            {
                d = (d + 1) % 4;
            }
            
            else
            {
                for(int step = 0 ; step < commands[i]; step++)
                {
                    int nx = newx + directions[d][0];
                    int ny = newy + directions[d][1];

                    if(ObstacleSet.Contains((nx,ny)))
                    {
                        break;
                    }

                    newx=nx;
                    newy=ny;
                }
                maxDist=Math.Max(maxDist, newx*newx + newy*newy);
            }
        }

        return maxDist;

    }
}