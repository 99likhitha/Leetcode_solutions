public class Solution {
    public int MinimumCost(int[] cost) {
        int n= cost.Length;
        Array.Sort(cost);
        int i=n-1, mincost=0;
        while (i>=2)
        {
            mincost +=(cost[i] + cost[i-1]);
            i-=3;
        }

        while(i>=0)
        {
            mincost+=cost[i];
            i--;
        }

        return mincost;
    }
}