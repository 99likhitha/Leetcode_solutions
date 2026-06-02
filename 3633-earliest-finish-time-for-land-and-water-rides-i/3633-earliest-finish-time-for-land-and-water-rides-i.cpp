class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int landfinish=0;
        int ans=INT_MAX;
        int waterfinish=0;
        int waterstart=0;
        int landstart=0;
        for(int i=0;i<n;i++)
        {
            landfinish=landStartTime[i] + landDuration[i];
            for(int j=0;j<m;j++)
            {
                waterstart=max(landfinish , waterStartTime[j]);
                ans=min(waterstart+waterDuration[j], ans);
            }
        }

        for(int i=0;i<m;i++)
        {
            waterfinish=waterStartTime[i] + waterDuration[i];
            for(int j=0;j<n;j++)
            {
                landstart=max(waterfinish , landStartTime[j]);
                ans=min(landstart+landDuration[j], ans);
            }
        }

        return ans;
    }
};