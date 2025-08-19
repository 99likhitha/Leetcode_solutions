class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     int n=nums.size();
     int count=0,i=0;
     long long ans=0;
     while(i<n)
     {
        if(nums[i]==0)
        {
            count++;
            ans+=count;
        }
        else
        {
            count=0;
        }
        i++;
     }

     return ans;
     
    }
};