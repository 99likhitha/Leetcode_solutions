class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        int ans_start=intervals[0][0];
        int ans_end=intervals[0][1];
        ans.push_back({ans_start,ans_end});
        for(int i=1;i<n;i++)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                if(ans.back()[1] <intervals[i][1])
                {
                    ans.back()[1]=intervals[i][1];
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }


     return ans;
    }
};