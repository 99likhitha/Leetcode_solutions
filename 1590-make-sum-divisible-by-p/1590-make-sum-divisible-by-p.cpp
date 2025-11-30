class Solution {
public:
const int MOD=1e9;
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        // if(total < p) return -1;
        int k = total % p;
        if (k == 0) return 0;

        int n = nums.size();
        int result = INT_MAX;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long prefix=0;

        for (int i=0;i<n;i++) 
        {
            prefix= (prefix + nums[i])%p;

            int rem= (prefix-k+p)%p;
            if(mp.count(rem))
            {
                result=min(result, i-mp[rem]);
            }
            mp[prefix]=i;
        }

        return (result == n ? -1 : result);
    }
};