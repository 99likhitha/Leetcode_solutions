public class Solution {
    public int EarliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int n=landStartTime.Length;
        int m=waterStartTime.Length;
        int landfinish=0;
        int ans=int.MaxValue;
        int waterfinish=0;
        int waterstart=0;
        int landstart=0;
        for(int i=0;i<n;i++)
        {
            landfinish=landStartTime[i] + landDuration[i];
            for(int j=0;j<m;j++)
            {
                waterstart=Math.Max(landfinish , waterStartTime[j]);
                ans=Math.Min(waterstart+waterDuration[j], ans);
            }
        }

        for(int i=0;i<m;i++)
        {
            waterfinish=waterStartTime[i] + waterDuration[i];
            for(int j=0;j<n;j++)
            {
                landstart=Math.Max(waterfinish , landStartTime[j]);
                ans=Math.Min(landstart+landDuration[j], ans);
            }
        }

        return ans;

    }
}