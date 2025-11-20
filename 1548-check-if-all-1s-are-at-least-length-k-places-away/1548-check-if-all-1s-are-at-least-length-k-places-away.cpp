class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1 && mp.find(nums[i]) != mp.end())
            {
               int index=mp[nums[i]];
               if(abs(i-index) <= k) return false;
            }
            mp[nums[i]]=i; 
        }

        return true;
    }
};