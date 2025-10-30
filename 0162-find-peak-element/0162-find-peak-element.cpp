class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int peak=0;
        int high=n-1,low=0;
        while(low<high)
        {
            int mid= low + (high-low)/2;
            if(nums[mid]<nums[mid+1])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
              
            }
        }

        return low;

    }
};