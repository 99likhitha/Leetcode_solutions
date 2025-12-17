class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double maxavg=numeric_limits<double>::lowest();
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        maxavg=max(maxavg,(double)sum/k);
        for(int i=k;i<n;i++)
        {
            sum-=nums[i-k];
            sum+=nums[i];
            maxavg=max(maxavg,(double)sum/k);
        }

        return maxavg;
    }
};