class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size(); 
        int m=n/2;
        map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }

        int ans=-1;
        for(auto itr:mp)
        {
            if(itr.second==m) ans=itr.first;
        }

        return ans;
    }
};