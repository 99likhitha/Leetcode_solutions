class Solution {
public:
    int gcd(int a ,int b)
    {
        return b==0 ? a: gcd(b,a%b);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int curr;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1) count++;
        }
        if(count>0) return n-count;

        int minlen=INT_MAX;
        for(int i=0;i<n;i++)
        {
            curr=nums[i];
            for(int j=i+1;j<n;j++)
            {
                curr=gcd(curr,nums[j]);
                if(curr==1)
                {
                    minlen=min(minlen,j-i+1);
                    break;
                }
            }
        }

        if(minlen == INT_MAX) return -1;

        return minlen-1 + (n-1);
    }
};