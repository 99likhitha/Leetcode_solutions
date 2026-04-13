class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int min_dist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }

        bool goodtuple=false;
        for(auto &[f,s] : mp)
        {
            if(s.size() >=3)
            {
                goodtuple=true;
                for(int i=0; i+2 < s.size();i++)
                {
                    min_dist=min(min_dist, 2*(s[i+2] - s[i]));
                }
            }
        } 
        return goodtuple ? min_dist : -1;
    }
};