class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxones=0;
        if(n==1 && nums[0]==1) return 1;
        int i=0;
        int j=i+1;
        while(i<n && j<n)
        {
            if(nums[i]==1 || nums[j]==1) maxones=max(maxones,1);
            while(j<n && nums[j]==nums[i] && nums[i]==1)
            {
                maxones=max(maxones,j-i+1);
                j++;
            }
            
            i=j;
            j++;
        }
        return maxones;
    }
};