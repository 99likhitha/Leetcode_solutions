class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        int low=0,high=n-1;
        int i=-1,j=-1;
        while(low<=high)
        {
            int mid= (high-low)/2 + low;
            if(nums[mid] < target)
            {
                low=mid+1;
            }
            else{
            if(nums[mid]==target) i=mid;
            high=mid-1;
            }
        }

        low=0,high=n-1;

        while(low<=high)
        {
            int mid= (high-low)/2 + low;
            if(nums[mid] > target)
            {
                high=mid-1;
            }
            else
            {
            if(nums[mid]==target) j=mid;
            low=mid+1;

            }
        }

        return {i,j};

    }
};