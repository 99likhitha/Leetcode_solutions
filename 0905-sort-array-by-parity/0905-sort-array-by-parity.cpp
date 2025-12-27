class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int i=0,j=n-1;
        for(int k=0;k<n;k++)
        {
            if(nums[k]%2==0) 
            {
                ans[i]=nums[k];
                i++;
            }
            else
            {
                ans[j]=nums[k];
                j--;
            }
        }
        return ans;
    }
};