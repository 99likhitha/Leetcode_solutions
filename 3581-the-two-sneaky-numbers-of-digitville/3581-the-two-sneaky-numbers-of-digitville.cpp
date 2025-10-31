class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto itr:mp)
        {
             if(itr.second >1) ans.push_back(itr.first);
        }

        return ans;
    }
};