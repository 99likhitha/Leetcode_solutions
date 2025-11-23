class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<int>mod1,mod2;
        if(total%3==0) return total;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%3==1) mod1.push_back(nums[i]);
            if(nums[i]%3==2) mod2.push_back(nums[i]);
        }

        sort(mod1.begin(),mod1.end());
        sort(mod2.begin(),mod2.end());

        int res=0;
        if(total%3==1)
        {
            int first= ( mod1.size()>=1 )? mod1[0]:INT_MAX;
            int second = (mod2.size()>=2)? mod2[0]+mod2[1] :INT_MAX;
            res=total-min(first,second);
        }
        else if(total%3==2)
        {
            int first= (mod2.size()>=1) ? mod2[0]:INT_MAX;
            int second = (mod1.size()>=2) ? mod1[0]+mod1[1]:INT_MAX;
            res=total-min(first,second);
        }

        return res;
    }
};