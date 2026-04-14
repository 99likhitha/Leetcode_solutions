class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int mindist=INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                mindist=min(mindist,abs(i-start));
            }
        }
        return mindist;
    }
};