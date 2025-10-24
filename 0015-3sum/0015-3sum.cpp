class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>S;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;

            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0)
                {
                    S.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }
                if(sum>0)
                {
                    right--;
                }
                if(sum<0)
                {
                    left++;
                }
            }
        }
        vector<vector<int>>ans(S.begin(),S.end());
        return ans;


    }
};