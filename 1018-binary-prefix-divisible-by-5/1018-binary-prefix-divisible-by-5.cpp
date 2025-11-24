class Solution {
public:
const int MOD=1e9;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans;
        long long val=0;
        int p=1;
        for(int i=0;i<n;i++)
        {
            if(val>1e9) val%=MOD;
            val=val*2+nums[i];
            if(val%5==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};