class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        int n=firstList.size();
        int m=secondList.size();
        if((n && m==0) || (m && n==0)) return {};
        int i=0,j=0;
        while(i<n && j<m)
        {
            auto f=firstList[i];
            auto s=secondList[j];
            int start=max(f[0],s[0]);
            int end=min(f[1],s[1]);
            if(start<=end)
            {
                ans.push_back({start,end});
            }

            if(firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else j++;
        }
        
        return ans;
    }
};