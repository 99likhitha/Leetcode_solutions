class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num:arr)
        {
            mp[num]++;
        }

        int ans=-1;
        for(auto &itr:mp)
        {
            if(itr.first == itr.second)
            {
                ans=max(ans,itr.first);
            }
        }

        return ans;
    }
};