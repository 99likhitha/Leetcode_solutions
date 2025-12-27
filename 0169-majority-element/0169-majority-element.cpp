class Solution {
public:
int findcand(vector<int>&nums)
{
    int n=nums.size();
    int count=0;
    int ele;
    for(int i=0;i<n;i++)
    {
        if(count==0) 
        {
            ele=nums[i];
            count++;
        }
        else if(ele==nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return ele;
}
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand=findcand(nums);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==cand)
            {
                count++;
            }
        }

        if(count>n/2) return cand;
        else return -1;

    }
};