class Solution {
public:
const int MOD=1e9;
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans(n,0);
        long long val=0;
        int p=1;
        for(int i=0;i<n;i++)
        {
            val%=MOD;
            if(nums[i] == 1)
            {
                val=val*2+1;
            }
            else
            {
                val*=2;
            }
            if(val%5==0) 
            {
                ans[i]=true;
            }
            else ans[i]=false;
        }
        return ans;
    }
};