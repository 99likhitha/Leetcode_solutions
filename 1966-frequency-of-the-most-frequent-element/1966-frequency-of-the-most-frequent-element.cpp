class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int maxfreq=0;
        sort(nums.begin(),nums.end());
        int left=0,right=0;
        long long sum=0;
        for(int right=0;right<n;right++)
        {
            sum+=nums[right];

            while((long long)nums[right] * (right-left+1) - sum >k)
            {
                sum-=nums[left];
                left++;
            }

            maxfreq=max(maxfreq, right-left+1);
        }

        return maxfreq;
    }
};