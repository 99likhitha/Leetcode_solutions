class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        for(int i =0 ;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }

        int d=k;
        while(k)
        {
            if(s.find(d) == s.end()) 
            {
                return d;
            }
            d+=k;
        }

     return -1;
    }
};