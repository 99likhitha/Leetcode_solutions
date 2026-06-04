class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int landearly=INT_MAX, waterearly=INT_MAX, landToWater=INT_MAX, waterToLand=INT_MAX;

        for(int i=0;i<n;i++)
        {
            landearly=min(landearly , landStartTime[i] + landDuration[i]);
        }

        for(int i=0;i<m;i++)
        {
            waterearly=min(waterearly , waterStartTime[i] + waterDuration[i]);
            landToWater=min(landToWater , max(landearly , waterStartTime[i]) + waterDuration[i]);
        }


        for(int i=0;i<n;i++)
        {
            waterToLand = min(waterToLand , max(waterearly , landStartTime[i]) + landDuration[i]);

        }

        return min(waterToLand , landToWater);
    }
};