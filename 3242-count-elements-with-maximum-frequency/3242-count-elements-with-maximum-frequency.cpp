class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxfreq=INT_MIN;
        for(int num:nums)
        {
            mp[num]++;
            maxfreq=max(maxfreq,mp[num]);
        }
       
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==maxfreq) ans+=it.second;
        }
        return ans;
    }
};